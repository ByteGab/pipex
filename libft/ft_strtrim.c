/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:40:29 by gafreire          #+#    #+#             */
/*   Updated: 2024/10/20 11:55:24 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	new_len;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	if (end == 0)
		return (ft_strdup(""));
	end--;
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	if (start > end)
		return (ft_strdup(""));
	new_len = end - start + 1;
	result = (char *)malloc(new_len + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, &s1[start], new_len + 1);
	return (result);
}
