/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 09:24:48 by csherill          #+#    #+#             */
/*   Updated: 2022/01/16 09:46:15 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_dead(void *s)
{
	t_date_test	*date;
	int			time;

	date = (t_date_test *)s;
	time = get_time(date->start_time);
	while (1)
	{
		time = get_time(date->start_time);
		if (date->info.death < get_time(date->start_time) - date->time_last_eat)
		{
			output_to_terminal("philo dead\n", \
				get_time(date->start_time), date);
			sem_post(date->ph_die);
			return (0);
		}
	}
	return (0);
}

int	ms_satiety(t_date_test *philo)
{
	philo->total_eat += 1;
	if (philo->total_eat == philo->info.food)
		sem_post(philo->satiety);
	philo->time_last_eat = get_time(philo->start_time);
	output_to_terminal("philo eating\n", get_time(philo->start_time), philo);
	sem_post(philo->write);
	while (1)
	{
		if (get_time(philo->start_time) - philo->time_last_eat >= \
												philo->info.death)
			return (1);
		if (get_time(philo->start_time) - philo->time_last_eat - \
												philo->info.eat >= 0)
			break ;
		usleep(300);
	}
	return (0);
}

static int	eat_philo(t_date_test *philo)
{
	sem_wait(philo->lock);
	sem_wait(philo->forks);
	output_to_terminal("fork left\n", get_time(philo->start_time), philo);
	sem_post(philo->write);
	sem_wait(philo->forks);
	output_to_terminal("fork right\n", get_time(philo->start_time), philo);
	sem_post(philo->write);
	sem_post(philo->lock);
	if (ms_satiety(philo) == 1)
		return (1);
	sem_post(philo->forks);
	sem_post(philo->forks);
	return (0);
}

static void	sleep_philo(t_date_test *philo)
{
	output_to_terminal("philo sleep \n", get_time(philo->start_time), \
												philo);
	sem_post(philo->write);
	usleep(philo->info.sleep * 1000);
}

void	simulation(t_date_test *date)
{
	pthread_create(&date->thread, NULL, check_dead, (void *)date);
	while (1)
	{
		if (get_time(date->start_time) - date->time_last_eat >= \
													date->info.death)
			break ;
		if (eat_philo(date))
			break ;
		if (get_time(date->start_time) - date->time_last_eat >= \
													date->info.death)
			break ;
		sleep_philo(date);
		if (get_time(date->start_time) - date->time_last_eat >= \
													date->info.death)
			break ;
		output_to_terminal("philo thinking \n", \
						get_time(date->start_time), date);
		sem_post(date->write);
	}
	exit(1);
}
