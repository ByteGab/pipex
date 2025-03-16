/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 02:45:02 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/16 21:08:27 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
#include <errno.h>

void	child(void)
{
	// open first file to read.
	// send estandar exit to pipe and out estandar to file.
	// close descriptor file pipe.
	// execute second comand.
}

void	parent(void)
{
	// open second file to write.
	// send out estandar to pipe and extandar exit.
	// close descriptor.
	// execute first command.
}

int	main(int argc, char *argv[], char **envp) // stdudy envp
{
	int pip[2];
	int check_pipe;
	int infile;
	int outfile;
	// create pipe.
	// create proccess child with fork.
	// create procces father,
	// wait to child finish proccess an then call father proccess.
	// if 0 arguments corrects print error.
    // is 5 arguments?
	if (argc != 5)
	{
		perror("No es valido\n");
        errno();
        exit(EXIT_FAILURE);
	}
	else
	{
		infile = open(argv[1],O_RDONLY);
		if(infile < 0)
		{
		    printf("Error archivo\n");
            return(1);
		}
		outfile = open(argv[4], O_RDONLY);
		// if exist infile and outfile
		if (outfile < 0)
		{
			// O_CREAT
			// create file
            printf("Crea archivo\n");
			outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644); // study open
		}
		else
		{
			// create pipe
			check_pipe = pipe(pip);
			if (check_pipe == 0)
			{
				fork();
				// if fork == -1 --> error
				// if child process?
				child();
				// if parent proccess? --> wait to  child process
				parent();
			}
			else if (check_pipe == -1)
				printf("Error al ejecutar pipe");
		}
		// wait to all procces
		// execute execve
	}
}

// add libft