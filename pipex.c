/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 02:45:02 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/17 20:55:13 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <errno.h>
#include <stdlib.h>

void	child(void)
{
// ------------------------------------------------------------------------
// 		- open first file to read.
// 		- send estandar exit to pipe and out estandar to file.
// 		- close descriptor file pipe.
// 		- execute second comand.
// ------------------------------------------------------------------------


}

void	parent(void)
{
// ------------------------------------------------------------------------
// 		- open second file to write. 									  |
// 		- send out estandar to pipe and extandar exit.   				  |
// 		- close descriptor.												  |
// 		- execute first command.										  |
// ------------------------------------------------------------------------


}

int	main(int argc, char *argv[], char **envp) // stdudy envp
{
// ------------------------------------------------------------------------
// 		- wait to child finish proccess an then call father proccess.	  |
// 		- if 0 arguments corrects print error.							  |
// ------------------------------------------------------------------------
	int pip[2];
	int check_pipe;
	int infile;
	int outfile;
	pid_t pid; // ???
	
	// is 5 arguments?
	if (argc != 5)
	{
		printf("No es valido\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		// create pipe
		check_pipe = pipe(pip);
		if (check_pipe == 0)
		{
			pid = fork();
			// if fork == -1 --> error
			if (pid == -1)
			{
				printf("Error al crear el fork");
			}
			//create proccess child with fork.
			// if child process? 
			else if (pid == 0)
			{
				// children
				close(pip[1]); // close write pipe
				child();
			}
			// create procces father
			// if parent proccess? --> wait to  child process
			else
			{
				// parent
				close(pip[0]); // close read pipe
				parent();	
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

// add libft