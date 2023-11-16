/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:23:25 by seonmiki          #+#    #+#             */
/*   Updated: 2023/03/17 22:48:16 by seonmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dd;
	const char	*ss;

	if (dst == 0 && src == 0)
		return (NULL);
	dd = (char *)dst;
	ss = (const char *)src;
	i = 0;
	if (dst >= src)
	{
		while (i < len)
		{
			dd[len - i - 1] = ss[len - i - 1];
			i++;
		}
		return (dst);
	}
	return (ft_memcpy(dst, src, len));
}
