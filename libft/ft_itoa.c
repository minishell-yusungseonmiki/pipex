/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:56:22 by seonmiki          #+#    #+#             */
/*   Updated: 2023/04/01 18:01:54 by seonmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getsize(long n)
{
	size_t	cnt;

	cnt = 1;
	while (n / 10)
	{
		cnt++;
		n = n / 10;
	}
	return (cnt);
}

static char	*ft_itoa_negative(int n)
{
	char	*itoa;
	long	num;
	size_t	size;
	size_t	i;

	num = (long)n * -1;
	size = ft_getsize(num);
	itoa = (char *)malloc(sizeof(char) * (size + 2));
	if (!itoa)
		return (NULL);
	itoa[0] = '-';
	i = size;
	while (i > 0)
	{
		itoa[i] = (num % 10) + '0';
		num = num / 10;
		i--;
	}
	itoa[size + 1] = '\0';
	return (itoa);
}

static char	*ft_itoa_positive(int n)
{
	char	*itoa;
	size_t	size;
	size_t	i;

	size = ft_getsize(n);
	itoa = (char *)malloc(sizeof(char) * (size + 1));
	if (!itoa)
		return (NULL);
	i = size - 1;
	while (i > 0)
	{
		itoa[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	itoa[i] = (n % 10) + '0';
	itoa[size] = '\0';
	return (itoa);
}

char	*ft_itoa(int n)
{
	if (n < 0)
		return (ft_itoa_negative(n));
	else
		return (ft_itoa_positive(n));
}
