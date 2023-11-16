/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:14:14 by seonmiki          #+#    #+#             */
/*   Updated: 2023/03/17 22:41:44 by seonmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dd;
	const char	*ss;

	if (dst == 0 && src == 0)
		return (NULL);
	dd = (char *)dst;
	ss = (const char *)src;
	i = 0;
	while (i < n)
	{
		dd[i] = ss[i];
		i++;
	}
	return (dst);
}
