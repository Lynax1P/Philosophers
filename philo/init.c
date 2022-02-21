/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 10:13:00 by csherill          #+#    #+#             */
/*   Updated: 2022/01/16 10:27:25 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init(int argc, char const *argv[],
						t_general *sys)
{
	int	stop;

	stop = 0;
	sys->info.philo = ft_atoi(argv[1]);
	if (sys->info.philo < 1)
	{
		stop = 1;
		write(1, "philo zero\n", 11);
	}
	sys->info.death = ft_atoi(argv[2]);
	sys->info.eat = ft_atoi(argv[3]);
	sys->info.sleep = ft_atoi(argv[4]);
	if (argc == 6)
		sys->info.food = ft_atoi(argv[5]);
	else
		sys->info.food = -1;
	if (stop == 1)
		return (1);
	return (0);
}

int	init_struct(int argc, char const *argv[], \
						t_general *s)
{
	int		n;

	s->info.dead = 0;
	if (valid_string(argc, argv))
		return (1);
	n = init(argc, argv, s);
	pthread_mutex_init(&s->info.write, NULL);
	if (n == 0)
		return (0);
	return (1);
}

static int	error_free(t_general *s, int i)
{
	t_philo		*point;

	point = NULL;
	while (s->philo->id <= i)
	{
		point = s->philo;
		s->philo = s->philo->next;
		free(point);
	}
	write(1, "Error Malloc init Philo\n", 25);
	return (1);
}

static void	init_value_philo(t_philo *point, int i, t_info *info)
{
	point->id = i;
	pthread_mutex_init(&point->lock, NULL);
	point->info = info;
	point->last_time_eat = get_time(info->start_time);
	point->dead = 0;
	point->total_eat = 0;
}

int	init_philo(t_general *s)
{
	t_philo	*point;
	int		i;

	i = 1;
	s->philo = malloc(sizeof(t_philo));
	s->philo->next = NULL;
	point = s->philo;
	while (i < s->info.philo + 1)
	{
		init_value_philo(point, i, &s->info);
		if (i != s->info.philo)
		{
			point->next = malloc(sizeof(t_philo));
			if (!point->next && error_free(s, i))
				return (1);
		}
		else
			point->next = s->philo;
		point = point->next;
		i++;
	}
	return (0);
}
