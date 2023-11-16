/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:48:46 by seonmiki          #+#    #+#             */
/*   Updated: 2023/04/01 20:14:09 by seonmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getsize(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			cnt++;
			while (*s && *s != c)
				s++;
		}
	}
	return (cnt);
}

static size_t	ft_getword(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s && *s != c)
	{
		cnt++;
		s++;
	}
	return (cnt);
}

static void	ft_splitfree(char **split, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static char	**ft_split_in(char **split, char const *s, char c, size_t size)
{
	size_t	i;
	size_t	word;

	i = 0;
	while (i < size)
	{
		while (*s == c)
			s++;
		word = ft_getword(s, c);
		split[i] = (char *)malloc(sizeof(char) * (word + 1));
		if (!split[i])
		{
			ft_splitfree(split, i);
			return (NULL);
		}
		ft_memcpy(split[i], s, word);
		split[i][word] = '\0';
		s += word;
		i++;
	}
	split[i] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_getsize(s, c);
	split = (char **)malloc(sizeof(char *) * (size + 1));
	if (!split)
		return (NULL);
	return (ft_split_in(split, s, c, size));
}
