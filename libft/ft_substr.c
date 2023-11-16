/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:21:33 by seonmiki          #+#    #+#             */
/*   Updated: 2023/03/31 22:07:45 by seonmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getsize(size_t slen, unsigned int start, size_t len)
{
	size_t	size;

	if (len > (slen - start))
		size = slen - start + 1;
	else
		size = len + 1;
	return (size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (slen <= start || len == 0)
		return (ft_strdup(""));
	size = ft_getsize(slen, start, len);
	sub = (char *)malloc(sizeof(char) * size);
	if (!sub)
		return (NULL);
	i = 0;
	while ((start + i < slen) && s[start + i] && (i < size - 1))
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
