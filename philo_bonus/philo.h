/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 09:44:30 by csherill          #+#    #+#             */
/*   Updated: 2022/01/16 09:45:15 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <signal.h>
# include "libft/libft.h"
# include <fcntl.h>

typedef struct s_date_test	t_date_test;
typedef struct s_info		t_info;

struct s_info
{
	int			philo;
	int			death;
	int			eat;
	int			sleep;
	int			food;
};

struct s_date_test
{
	int			id;
	t_info		info;
	int			time_last_eat;
	int			total_eat;
	int			start_time;
	pthread_t	thread;
	sem_t		*satiety;
	sem_t		*write;
	sem_t		*ph_die;
	sem_t		*lock;
	sem_t		*forks;
};

int		get_time(int s);
int		general_init(int argc, char const *argv[], \
						t_date_test *date);

void	output_to_terminal(char *str, int time,	t_date_test *s);
int		ms_satiety(t_date_test *philo);
void	simulation(t_date_test *date);

//observer
void	*check_dead(void *s);
void	*check_satiety(void *s);

#endif
