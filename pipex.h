/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 02:39:31 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/23 08:46:02 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <wait.h>

void ft_error(char * str,int fd);
void   ft_free(int check,int *pip);
char *ft_cmd_complete(char **path,char *cmd);
void check_pipe(char *msg, int pip[2]);
// void ft_free(char **arr);
#endif