/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:25:59 by seonmiki          #+#    #+#             */
/*   Updated: 2023/10/09 23:11:55 by seonmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_spacensign(const char *str, int *sign)
{
	int	tmp;

	tmp = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
	{
		str++;
		tmp++;
	}
	*sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*sign = -1;
		str++;
		tmp++;
	}
	return (tmp);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	str += ft_spacensign(str, &sign);
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		if ((result < 214748364) || ((result == 214748364) && (*str <= '7')))
		{
			result = result * 10 + (*str - '0');
			str++;
		}
		else if ((result == 214748364) && (*str == '8') && (sign == -1))
			return (-2147483648);
		else
		{
			if (sign == 1)
				return (2147483647);
			return (-2147483648);
		}
	}
	return (result * sign);
}
