/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:47:19 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/23 17:56:07 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_args(char **arr)
{
	int		i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
