/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 02:45:02 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/18 18:23:45 by gafreire         ###   ########.fr       */
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
	// TODO 		- Find start to path.											|
	// TODO 		- Splits the path string into an array using : as the delimiter.|
	// TODO 		- For each path, build the full command path using ft_strjoin.	|
	// TODO 		- Check if the command exists in that path using access			|
	// TODO 		- If find command, return all path it not find clean all.		|
	// ------------------------------------------------------------------------------
	
}
void	child(char *infile)
{
	int	file;

	// ------------------------------------------------------------------------
	// TODO 		- send estandar exit to pipe and out estandar to file.
	// ------------------------------------------------------------------------
	file = 0;
	//*	open first file to read.
	file = open(infile, O_RDONLY);
	if (file < 0)
	{
		printf("Error archivo\n");
		return (1);
	}
	//* execute second comand.
	exc_prcs();
	//! close read pipe.
	//? close(pip[1]);
}

void	parent(char *outfile)
{
	int	file;

	// ------------------------------------------------------------------------
	// TODO 		- send out estandar to pipe and extandar exit.   				|
	// ------------------------------------------------------------------------
	file = 0;
	//* open second file to write.
	file = open(outfile, O_RDWR, 0644);
	//* if exist infile and outfile.
	if (outfile < 0)
	{
		//* O_CREAT
		//* create file
		printf("Crea archivo\n");
		file = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		//! study open
	}
	//!	execute first command.
	exc_prcs();
	//* close write pipe
	//? close(pip[0]);
}

int	main(int argc, char *argv[], char **envp) // stdudy envp
{
	// ------------------------------------------------------------------------
	// TODO 		- if 0 arguments corrects print error.								|
	// ------------------------------------------------------------------------
	int pip[2];
	int check_pipe;
	int infile;
	int outfile;
	pid_t pid; // ???

	//* is 5 arguments?
	if (argc != 5)
	{
		printf("No es valido\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		//* create pipe
		check_pipe = pipe(pip);
		if (check_pipe == 0)
		{
			pid = fork();
			//* if fork == -1 --> error
			if (pid == -1)
			{
				printf("Error al crear el fork");
			}
			//* create proccess child with fork.
			//* if child process?
			else if (pid == 0)
			{
				//* children
				child(argv[1]);
			}
			//* create procces father
			//* if parent proccess? --> wait to  child process
			else
			{
				//* wait to child finish proccess an then call father proccess.
				pid = wait();
				//* parent
				parent(argv[4]);
			}
		}
		else if (check_pipe == -1)
			printf("Error al ejecutar pipe");
	}
	// else
	// {
	// 	infile = open(argv[1], O_RDONLY);
	// 	if (infile < 0)
	// 	{
	// 		printf("Error archivo\n");
	// 		return (1);
	// 	}
	// 	outfile = open(argv[4], O_RDONLY);
	// 	// if exist infile and outfile
	// 	if (outfile < 0)
	// 	{
	// 		// O_CREAT
	// 		// create file
	// 		printf("Crea archivo\n");
	// 		outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	// 		// study open
	// 	}
	// 	// wait to all procces
	// 	// execute execve
	// }
}

//! add libft