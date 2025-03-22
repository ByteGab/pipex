/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 02:45:02 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/22 01:16:02 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <errno.h>
#include <stdlib.h>

int	exc_prcs(char **envp)
{
	int	path;

	// ------------------------------------------------------------------------
	// TODO 		- Splits the command argument into an array of arguments.		|
	// ------------------------------------------------------------------------
	//! split
	//* call search_prcs to obtain path.
	path = search_prcs(envp);
	//* if no exists free all.
	if (path == 1)
	{
		printf("No se  encuntra la ruta");
		//! free all
		return (1);
	}
	//* if exists use execve.
	else if (path == 0)
	{
		//!		execve();
	}
}
int	search_prcs(char **envp)
{
	int		i;
	size_t	size_envp;
	char	**path;

	// ------------------------------------------------------------------------------
	// TODO 		- If find command, return all path it not find clean all.		|
	// ------------------------------------------------------------------------------
	//* Find start to path.	strncmp(envp[i], "PATH=") == 0	-> envp[i]
	i = 0;
	size_envp = 0;
	while (*envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			printf("Te encontre");
			break ;
		}
		i++;
	}
	//* Splits the path string into an array using : as the delimiter.
	path = ft_split(envp[i] + 5, ':');
	//* For each path, build the full command path using ft_strjoin.
	//* Check if the command exists in that path using access
	return (1);
}
void	child(char *file, char *pip, char **envp)
{
	int	infile;

	// ------------------------------------------------------------------------
	// TODO 		- send estandar exit to pipe and out estandar to file.
	// ------------------------------------------------------------------------
	infile = 0;
	close(pip[0]); //* close pip read
	//*	open first file to read.
	infile = open(file, O_RDONLY);
	if (infile < 0)
	{
		printf("Error archivo\n");
		return (1);
	}
	//* move fd to mi fd's
	dup2(STDIN_FILENO, infile);
	dup2(STDOUT_FILENO, pip[1]);
	//* close mi fd and pip write
	close(infile);
	close(pip[1]);
	//* execute second comand.
	exc_prcs(envp);
}

void	parent(char *file, char *pip, char **envp)
{
	int	outfile;

	// ------------------------------------------------------------------------
	// TODO 		- send out estandar to pipe and extandar exit.   				|
	// ------------------------------------------------------------------------
	outfile = 0;
	close(pip[1]); //* close pip write
	//* open second file to write.
	outfile = open(file, O_RDWR, 0644);
	//* if exist infile and outfile.
	if (outfile < 0)
	{
		//* O_CREAT
		//* create file
		printf("Crea archivo\n");
		outfile = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		//! study open
	}
	//* move fd to mi fd's
	dup2(STDIN_FILENO, pip[0]);
	dup2(STDOUT_FILENO, outfile);
	//* close mi fd and pip read
	close(outfile);
	close(pip[0]);
	//*	execute first command.
	exc_prcs(envp);
}

// for (int i = 0; envp[i]; i++)
// 	printf ("linea --> %s\n", envp[i]);

int	main(int argc, char *argv[], char **envp) // stdudy envp
{
	// ------------------------------------------------------------------------
	// TODO 		- if 0 arguments corrects print error.								|
	// ------------------------------------------------------------------------
	int pip[2]; //* pipe con dos extremos [0] lectura [1] escritura
	pid_t pid;  // Identificador de procesos

	//* is 5 arguments?
	if (argc != 5)
	{
		printf("No es valido\n"); //* close mi fd and pip read
		exit(EXIT_FAILURE);
	}
	else
	{
		//* create pipe
		if (pipe(pip) == -1)
			printf("Error al ejecutar pipe");
		else
		{
			pid = fork();
			//* if fork == -1 --> error
			if (pid == -1)
			{
				close(pip[0]);
				close(pip[1]);
				printf("Error al crear el fork");
			}
			//* create proccess child with fork.
			//* if child process?
			else if (pid == 0)
			{
				//* children
				child(argv[1], pip, envp);
			}
			//* create procces father
			//* if parent proccess? --> wait to  child process
			else
			{
				//* wait to child finish proccess an then call father proccess.
				pid = wait();
				//* parent
				parent(argv[4], pip, envp);
			}
		}
	}
}