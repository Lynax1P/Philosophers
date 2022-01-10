#include "philo.h"

void	death_philo(t_general *s)
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
		space = point;
		point = point->next;
		free(space);
		i++;
	}
}

void	*monitor(void *p)
{
	int		i;
	int		time;
	int		temp;
	t_philo	*point;
	t_general *s;
	
	s = (t_general *)p;
	temp = 0;
	i = 0;
	point = s->philo;
	// return;
	while (1)
	{
		temp = s->info.death;
		time = get_time(s->info.start_time) - point->last_time_eat;
		// printf("ID:%d\n1. temp %d\n2. time %d\n", point->id, temp, time);
		if (temp < time)
		{
			output_to_terminal("philo dead\n", get_time(s->info.start_time) , point);
			// pthread_mutex_lock(&s->info.write);
			death_philo(s);
			// exit(1);
			return (1);
		}
		point = point->next;
	}
	return (0);
}

int	heart_rate_monitor(t_general *s)
{
	pthread_t			thread;

	pthread_create(&thread, NULL, monitor, (void *)s);

	pthread_join(thread, NULL);
}