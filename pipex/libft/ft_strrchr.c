/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:45:06 by seonmiki          #+#    #+#             */
/*   Updated: 2023/03/18 21:51:54 by seonmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	int		flag;

	flag = 0;
	while (*s)
	{
		if (*s == (char)c)
		{
			flag = 1;
			last = (char *)s;
		}
		s++;
	}
	if (*s == (char)c)
	{
		flag = 1;
		last = (char *)s;
	}
	if (flag)
		return (last);
	return (NULL);
}
