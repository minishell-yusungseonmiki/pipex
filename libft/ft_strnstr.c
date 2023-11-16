/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:33:39 by seonmiki          #+#    #+#             */
/*   Updated: 2023/03/21 22:22:27 by seonmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (!(*needle))
		return ((char *)haystack);
	while (*(haystack + i) && i + ft_strlen(needle) <= len)
	{
		if (*(haystack + i) == *needle)
		{
			if (ft_strncmp(haystack + i, needle, ft_strlen(needle)) == 0)
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
