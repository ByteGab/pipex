/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 02:45:02 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/21 23:26:53 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <errno.h>
#include <stdlib.h>

void	exc_prcs(void)
{
	int	path;

	// ------------------------------------------------------------------------
	// TODO 		- Splits the command argument into an array of arguments.		|
	// ------------------------------------------------------------------------
	//! split
	//* call search_prcs to obtain path.
	path = search_prcs();
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
int	search_prcs(void)
{
	// ------------------------------------------------------------------------------
	// TODO 		- Find start to path.	strncmp(envp[i], "PATH=") == 0	-> envp[i]		|
	// TODO 		- Splits the path string into an array using : as the delimiter.|
	// TODO 		- For each path, build the full command path using ft_strjoin.	|
	// TODO 		- Check if the command exists in that path using access			|
	// TODO 		- If find command, return all path it not find clean all.		|
	// ------------------------------------------------------------------------------
	
}
void	child(char *file,char *pip)
{
	int	infile;

	// ------------------------------------------------------------------------
	// TODO 		- send estandar exit to pipe and out estandar to file.
	// ------------------------------------------------------------------------
	infile = 0;
	close (pip[0]); //* close pip read
	//*	open first file to read.
	infile = open(file, O_RDONLY);
	if (infile < 0)
	{
		printf("Error archivo\n");
		return (1);
	}
	//* move fd to mi fd's
	dup2(STDIN_FILENO,infile);
	dup2(STDOUT_FILENO, pip[1]);
	//* close mi fd and pip write
	close (infile);
	close(pip[1]);
	//* execute second comand.
	exc_prcs();
}

void	parent(char *file, char *pip)
{
	int	outfile;

	// ------------------------------------------------------------------------
	// TODO 		- send out estandar to pipe and extandar exit.   				|
	// ------------------------------------------------------------------------
	outfile = 0;
	close (pip[1]); //* close pip write
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
	dup2(STDIN_FILENO,pip[0]);
	dup2(STDOUT_FILENO,outfile);
	//* close mi fd and pip read
	close (outfile);
	close(pip[0]);
	
	//*	execute first command.
	exc_prcs();	
}

	// for (int i = 0; envp[i]; i++)
	// 	printf ("linea --> %s\n", envp[i]);

int	main(int argc, char *argv[], char **envp) // stdudy envp
{
	// ------------------------------------------------------------------------
	// TODO 		- if 0 arguments corrects print error.								|
	// ------------------------------------------------------------------------
	int pip[2]; //* pipe con dos extremos [0] lectura [1] escritura
	pid_t pid; // Identificador de procesos

	//* is 5 arguments?
	 if (argc != 5)
	 {
	 	printf("No es valido\n");//* close mi fd and pip read
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
	 			child(argv[1], pip);
	 		}
	 		//* create procces father
	 		//* if parent proccess? --> wait to  child process
	 		else
	 		{
	 			//* wait to child finish proccess an then call father proccess.
	 			pid = wait();
	 			//* parent
	 			parent(argv[4], pip);
	 		}
	 	}
		}
		//  else
		//  {
		//  	infile = open(argv[1], O_RDONLY);
		//  	if (infile < 0)
		//  	{
		//  		printf("Error archivo\n");
		//  		return (1);
		//  	}
		//  	outfile = open(argv[4], O_RDONLY);
		//  	// if exist infile and outfile
		//  	if (outfile < 0)
		//  	{
		//  		// O_CREAT
		//  		// create file
		//  		printf("Crea archivo\n");
		//  		outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		//  		// study open
		//  	}
		//  	// wait to all procces
		//  	// execute execve
		//  }
}