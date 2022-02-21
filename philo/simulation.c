/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:53:28 by csherill          #+#    #+#             */
/*   Updated: 2022/01/16 10:36:03 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	eat_philo(t_philo *ph)
{
	pthread_mutex_lock(&ph->next->lock);
	output_to_terminal("fork right\n", get_time(ph->info->start_time), ph);
	pthread_mutex_unlock(&ph->info->write);
	pthread_mutex_lock(&ph->lock);
	output_to_terminal("fork left\n", get_time(ph->info->start_time), ph);
	pthread_mutex_unlock(&ph->info->write);
	ph->total_eat += 1;
	ph->last_time_eat = get_time(ph->info->start_time);
	output_to_terminal("philo eating\n", get_time(ph->info->start_time), ph);
	pthread_mutex_unlock(&ph->info->write);
	while (1)
	{
		if (get_time(ph->info->start_time) - ph->last_time_eat >= \
												ph->info->death)
			return (1);
		if (get_time(ph->info->start_time) - ph->last_time_eat - \
						ph->info->eat >= 0)
			break ;
		usleep(200);
	}
	pthread_mutex_unlock(&ph->next->lock);
	pthread_mutex_unlock(&ph->lock);
	return (0);
}

static int	sleep_philo(t_philo *philo)
{
	output_to_terminal("philo sleep \n", get_time(philo->info->start_time), \
										philo);
	pthread_mutex_unlock(&philo->info->write);
	usleep(philo->info->sleep * 1000);
	return (0);
}

static int	thinking_philo(t_philo *philo)
{
	output_to_terminal("philo thinking \n", get_time(philo->info->start_time), \
						philo);
	pthread_mutex_unlock(&philo->info->write);
	return (0);
}

static void	*thread(void *s)
{
	t_philo	*philo;

	philo = (t_philo *)s;
	while (1)
	{
		if (get_time(philo->info->start_time) - philo->last_time_eat - \
						philo->info->death >= 0)
			return (NULL);
		if (eat_philo(philo))
			return (NULL);
		if (get_time(philo->info->start_time) - philo->last_time_eat - \
				philo->info->death >= 0)
			return (NULL);
		sleep_philo(philo);
		thinking_philo(philo);
	}
}

int	start_simulation(t_general *s)
{
	int		i;
	int		temp;
	t_philo	*point;

	i = 0;
	point = s->philo;
	temp = s->info.philo;
	while (i < (temp - temp / 2))
	{
		pthread_create(&point->thread, NULL, thread, (void *)point);
		if (temp > 2)
			point = point->next->next;
		i++;
	}
	point = s->philo->next;
	i = 0;
	usleep(100);
	while (i < temp / 2)
	{
		pthread_create(&point->thread, NULL, thread, (void *)point);
		point = point->next->next;
		i++;
	}
	return (0);
}
