/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 02:45:02 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/13 15:08:05 by gafreire         ###   ########.fr       */
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
        open(argv[1]);
        if(open < 0)
        {
            printf("Error archivo");
        }
        open(argv[5]);
        if(open < 0)
        {
            //O_CREAT
            // create file
            
        }
        // if exist infile and outfile
        // create pipe
        // child proccess
        // parent proccess
        // wait to all procces
        // execute execve
    }
}




// add libft