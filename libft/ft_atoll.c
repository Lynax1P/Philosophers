/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 23:11:39 by csherill          #+#    #+#             */
/*   Updated: 2021/10/21 23:11:40 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	ten_power(int power)
{
	if (power == 0)
		return (1);
	if (power == 1)
		return (10);
	return (10 * ten_power(power - 1));
}

static int	get_num_len(const char *str)
{
	int	len;

	len = 0;
	while (*str >= '0' && *str <= '9')
	{
		len++;
		str++;
	}
	return (len);
}

long long	ft_atoll(const char *str)
{
	long long	result;
	int			sign;
	int			num_len;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	num_len = get_num_len(str);
	while (num_len > 0)
	{
		result += (*(str++) - '0') * ten_power(num_len - 1);
		num_len--;
	}
	return (result * sign);
}
