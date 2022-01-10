/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 23:13:52 by csherill          #+#    #+#             */
/*   Updated: 2021/10/21 23:13:53 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_number_len(int nb)
{
	int	length;

	length = 0;
	while (nb != 0)
	{
		length++;
		nb /= 10;
	}
	return (length);
}

static void	print_result(char *digits, int temp_len, int fd)
{
	int	counter;

	counter = 0;
	while (counter < temp_len)
		ft_putchar_fd(digits[counter++], fd);
}

static void	make_job(int n, int fd)
{
	int		num_len;
	int		temp_len;
	char	digits[10];

	num_len = get_number_len(n);
	temp_len = num_len;
	while (n != 0)
	{
		digits[--num_len] = (char)(n % 10 + '0');
		n /= 10;
	}
	print_result(digits, temp_len, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n + (-2 * n);
	}
	make_job(n, fd);
}
