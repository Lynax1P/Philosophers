/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pulse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 09:48:20 by csherill          #+#    #+#             */
/*   Updated: 2022/01/16 10:36:56 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	death_philo(t_general *s)
{
	int		temp;
	t_philo	*point;
	t_philo	*space;
	int		i;

	i = 0;
	point = s->philo;
	temp = s->info.philo;
	space = NULL;
	while (i < temp)
	{
		pthread_detach(point->thread);
		pthread_mutex_destroy(&point->lock);
		space = point;
		point = point->next;
		free(space);
		i++;
	}
}

static int	check_food(t_philo *point, char **eat, t_general **s)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	if (point->total_eat >= point->info->food)
		(*eat)[point->id - 1] = '1';
	while (i < point->info->philo)
		if ((*eat)[i++] == '1')
			count++;
	if (count == i)
	{
		pthread_mutex_lock(&(*s)->info.write);
		printf("eat till full\n");
		free(*eat);
		(*s)->info.dead = 1;
		death_philo(*s);
		return (1);
	}
	return (0);
}

static int	check_death(t_general **s, char **eat, t_philo **point)
{
	if ((*s)->info.death < get_time((*s)->info.start_time) - \
											(*point)->last_time_eat)
	{
		pthread_mutex_lock(&(*s)->info.write);
		printf("philo dead");
		free(*eat);
		(*s)->info.dead = 1;
		death_philo((*s));
		return (1);
	}
	return (0);
}

static void	*monitor(void *p)
{
	int			i;
	char		*eat;
	t_philo		*point;
	t_general	*s;

	s = (t_general *)p;
	eat = malloc(1001);
	i = 0;
	point = s->philo;
	while (i < s->info.philo)
		eat[i++] = '0';
	eat[s->info.philo] = '\0';
	while (1)
	{
		if (check_death(&s, &eat, &point))
			return (0);
		if (s->info.food != -1)
			if (check_food(point, &eat, &s) == 1)
				return (0);
		point = point->next;
	}
	return (0);
}

int	heart_rate_monitor(t_general *s)
{
	pthread_t			thread;

	pthread_create(&thread, NULL, monitor, (void *)s);
	pthread_join(thread, NULL);
	return (0);
}
