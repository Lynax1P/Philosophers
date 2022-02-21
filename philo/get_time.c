/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 10:12:42 by csherill          #+#    #+#             */
/*   Updated: 2022/01/16 10:31:40 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time(int s)
{
	struct timeval		time;
	int					ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec % 100000 * 1000) + (time.tv_usec / 1000) - s;
	return (ms);
}
