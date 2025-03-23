/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 00:07:39 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/23 08:45:18 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str, int fd)
{
	ft_putstr_fd(str, fd);
	exit(EXIT_FAILURE);
}


void   ft_free(int check,int *pip)
{
    if (check == 1)
    {
        close(pip[0]);
		close(pip[1]);
    }
}

char *ft_cmd_complete(char **path,char *cmd)
{
    int i;
    char *cmd_complete;
    char *full_cmd;

    i = 0;
    while (path[i] != NULL)
	{
		cmd_complete = ft_strjoin("/", cmd);
		full_cmd = ft_strjoin(path[i], cmd_complete);
		free(cmd_complete);
		if (access(full_cmd, F_OK) == 0)
		{
			// ft_free(path);
			return (full_cmd);
		}
		free(full_cmd);
		i++;
	}
    return (NULL);
}

void check_pipe(char *msg, int pip[2])
{
    ft_free(1, pip);
	ft_error(msg, 1);
}

// void ft_free(char **arr)
// {
//     int	i;

// 	if (!arr)
// 		return ;
// 	i = 0;
// 	while (arr[i] != NULL)
// 	{
// 		free(arr[i]);
// 		i++;
// 	}
// 	free(arr);
// }