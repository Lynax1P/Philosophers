/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 08:47:40 by csherill          #+#    #+#             */
/*   Updated: 2022/01/16 09:42:15 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_digit(int argc, char const *argv[])
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	argc--;
	while (argc--)
	{
		i = 0;
		while (argv[j][i] != 0)
		{
			if (argv[j][i] > '9' || argv[j][i] < '0')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	valid_string(int argc, char const *argv[])
{
	if (argc < 5 || argc > 6)
	{
		write(1, "Count arg != 5 or 6\n", ft_strlen("Count arg != 5 or 6\n"));
		return (1);
	}
	if (!check_digit(argc, argv))
	{
		write(1, "Uncorrect argument\n", ft_strlen("Uncorrect argument\n"));
		return (1);
	}
	return (0);
}

int	init_value(int argc, char const *argv[],
						t_date_test *date)
{
	int		stop;

	stop = 0;
	date->info.philo = ft_atoi(argv[1]);
	if (date->info.philo < 1)
	{
		stop = 1;
		write(1, "philo zero\n", 11);
	}
	date->info.death = ft_atoi(argv[2]);
	date->info.eat = ft_atoi(argv[3]);
	date->info.sleep = ft_atoi(argv[4]);
	if (argc == 6)
		date->info.food = ft_atoi(argv[5]);
	else
		date->info.food = -1;
	if (stop == 1)
		return (1);
	return (0);
}

int	init_sem(t_date_test *s)
{
	sem_unlink("forks");
	s->forks = sem_open("forks", O_CREAT, 0644, s->info.philo);
	if (s->forks == SEM_FAILED)
		return (1);
	sem_unlink("lock");
	s->lock = sem_open("lock", O_CREAT, 0644, 1);
	if (s->lock == SEM_FAILED)
		return (1);
	sem_unlink("write");
	s->write = sem_open("write", O_CREAT, 0644, 1);
	if (s->write == SEM_FAILED)
		return (1);
	sem_unlink("ph_die");
	s->ph_die = sem_open("ph_die", O_CREAT, 0644, 0);
	if (s->ph_die == SEM_FAILED)
		return (1);
	sem_unlink("satiety");
	s->satiety = sem_open("satiety", O_CREAT, 0644, 0);
	if (s->satiety == SEM_FAILED)
		return (1);
	return (0);
}

int	general_init(int argc, char const *argv[], \
						t_date_test *date)
{
	date->start_time = get_time(0);
	date->total_eat = 0;
	date->id = 1;
	if (valid_string(argc, argv))
		return (1);
	if (init_value(argc, argv, date) == 1)
		return (1);
	if (init_sem(date) == 1)
	{
		write(1, "InitSem Error\n", 15);
		return (1);
	}
	return (0);
}
