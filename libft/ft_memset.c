/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:47:19 by seonmiki          #+#    #+#             */
/*   Updated: 2023/04/01 19:49:24 by seonmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*memset;
	size_t			i;

	memset = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		memset[i] = (unsigned char)c;
		i++;
	}
	return (memset);
}
