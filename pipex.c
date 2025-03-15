/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 02:45:02 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/15 23:38:20 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
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


int main(int argc,char *argv[])
{
    int pip[2];
    int check_pipe;
    // is 5 arguments?
    // create pipe.
    // create proccess child with fork.
    // create procces father, wait to child finish proccess an then call father proccess.
    // if 0 arguments corrects print error.
    if (argc != 5)
    {
        printf("No es valido\n");
    }
    else
    {
        open(argv[1],O_RDONLY);
        if(open < 0)
        {
            printf("Error archivo");
        }
        open(argv[5],O_RDONLY);
        // if exist infile and outfile
        if(open < 0)
        {
            //O_CREAT
            // create file
            open(argv[5],O_CREAT);
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