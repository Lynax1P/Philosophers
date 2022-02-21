/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 08:55:01 by csherill          #+#    #+#             */
/*   Updated: 2022/01/16 10:42:01 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_satiety(void *s)
{
	t_date_test	*date;
	int			i;

	date = (t_date_test *)s;
	i = date->info.philo;
	if (date->info.food != -1)
		while (--i >= 0)
			sem_wait(date->satiety);
	if (date->info.food != -1)
	{
		sem_wait(date->write);
		sem_post(date->ph_die);
		printf("All philo satiety\n");
	}
	return (s);
}

int	clean_mut(t_date_test *date)
{
	sem_unlink("forks");
	sem_unlink("lock");
	sem_unlink("write");
	sem_unlink("ph_die");
	sem_unlink("satiety");
	sem_close(date->forks);
	sem_close(date->lock);
	sem_close(date->satiety);
	sem_close(date->write);
	sem_close(date->ph_die);
	return (0);
}

int	errorr(char *str)
{
	printf("%s\n", str);
	return (1);
}

int	main_thread(t_date_test *date)
{
	pid_t		*pid;
	pthread_t	control;
	int			i;

	i = 0;
	pid = malloc(sizeof(*pid) * date->info.philo);
	if (pid == NULL)
		exit(errorr("Error Arr"));
	pthread_create(&control, NULL, check_satiety, (void *)date);
	while (i < date->info.philo)
	{
		pid[i] = fork();
		date->time_last_eat = get_time(date->start_time);
		if (pid[i] == 0)
			simulation(date);
		else
			date->id += 1;
		i++;
	}
	sem_wait(date->ph_die);
	while (--i >= 0)
		kill(pid[i], SIGINT);
	free(pid);
	return (0);
}

int	main(int argc, char const *argv[])
{
	t_date_test		date;

	if (general_init(argc, argv, &date) == 1)
		return (1);
	main_thread(&date);
	clean_mut(&date);
	return (0);
}
