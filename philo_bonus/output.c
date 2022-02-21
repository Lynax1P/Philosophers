/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 04:00:47 by csherill          #+#    #+#             */
/*   Updated: 2022/01/16 10:42:28 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	zero(char **str)
{
	(*str)[0] = '0';
	(*str)[1] = ' ';
	return (2);
}

int	itoa_nomalloc(int n, char **str)
{
	int		i;
	int		temp;

	temp = n;
	i = 0;
	if (!n)
		return (zero(str));
	while (temp != 0)
	{
		temp /= 10;
		i++;
	}
	temp = i;
	while (n != 0)
	{
		(*str)[i - 1] = "0123456789"[n % 10];
		n /= 10;
		i--;
	}
	(*str)[temp] = ' ';
	(*str)[temp + 1] = '\0';
	return (temp + 1);
}

int	join(char **str, char *what)
{
	int		i;

	i = 0;
	while (what[i] != 0)
	{
		(*str)[i] = what[i];
		i = i + 1;
	}
	(*str)[i] = '\0';
	i += 1;
	return (i);
}

void	output_to_terminal(char *str, int time,	t_date_test *s)
{
	char	buf[100];
	int		i;
	char	*point;

	point = buf;
	i = 0;
	i += itoa_nomalloc(time, &point);
	point = buf + i;
	i += itoa_nomalloc(s->id, &point);
	point = buf + i;
	i += join(&point, str);
	point = buf + i;
	*point = '\n';
	sem_post(s->write);
	write(1, buf, i);
}
