/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 23:11:32 by csherill          #+#    #+#             */
/*   Updated: 2021/10/21 23:11:34 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	digital;
	int		flag;

	digital = 0;
	flag = 1;
	while (*str == ' ' || *str == '\t' || *str == '\v' \
		|| *str == '\f' || *str == '\r' || *str == '\n')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			flag *= -1;
	while (*str >= '0' && *str <= '9')
	{
		if (digital * flag < -2147483648)
			return (0);
		if (digital * flag > 2147483647)
			return (-1);
		digital = (digital * 10) + (*str - '0');
		str++;
	}
	return (flag * (int) digital);
}
