/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 10:29:30 by csherill          #+#    #+#             */
/*   Updated: 2022/01/16 10:30:03 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include "libft/libft.h"
# include <fcntl.h>

typedef struct s_info		t_info;
typedef struct s_philo		t_philo;
typedef struct s_general	t_general;

struct s_philo
{
	int					id;
	int					dead;
	int					last_time_eat;
	int					total_eat;
	pthread_mutex_t		lock;
	pthread_t			thread;
	t_info				*info;
	t_philo				*next;
};

struct s_info
{
	pthread_mutex_t	write;
	int				dead;
	int				start_time;
	int				philo;
	int				eat;
	int				sleep;
	int				thinking;
	int				death;
	int				food;
};

struct s_general
{
	int					dead;
	unsigned long long	time;
	char				*error;
	t_info				info;
	t_philo				*philo;
};

int		init_struct(int argc, char const *argv[], \
						t_general *sys);
int		valid_string(int argc, char const *argv[]);
int		get_time(int s);
int		init_philo(t_general *s);
int		start_simulation(t_general *s);
int		heart_rate_monitor(t_general *s);
void	output_to_terminal(char *str, int time, t_philo *s);

#endif
