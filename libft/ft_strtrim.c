/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 22:11:49 by seonmiki          #+#    #+#             */
/*   Updated: 2023/04/01 20:19:22 by seonmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_trim(char *trim, char const *s1, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	while (start + i < end)
	{
		trim[i] = s1[start + i];
		i++;
	}
	trim[i] = '\0';
	return (trim);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	start;
	size_t	end;
	size_t	size;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (start < end && (ft_strchr(set, s1[start])) != NULL)
		start++;
	while (start < end && (ft_strchr(set, s1[end - 1])) != NULL)
		end--;
	size = end - start + 1;
	trim = (char *)malloc(sizeof(char) * size);
	if (!trim)
		return (NULL);
	return (ft_trim(trim, s1, start, end));
}
