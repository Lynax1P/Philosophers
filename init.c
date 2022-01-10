#include "philo.h"

int	init(int argc, char const *argv[],
						t_general *sys)
{
	int stop;

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
	printf("1.philo %d\n",sys->info.philo);
	printf("2.death %d\n",sys->info.death);
	printf("3.eat %d\n",sys->info.eat);
	printf("4.sleep %d\n",sys->info.sleep);
	printf("5.food %d\n",sys->info.food);
	return (0);

}

int	init_struct(int argc, char const *argv[], 
						t_general *s)
{
	int		n;

	if (valid_string(argc, argv))
		return (1);
	n = init(argc, argv, s);
	if (n == 0);
		return (0);
	return (1);
}

int	error_free(t_general *s, int i)
{
	t_philo		*point;
	
	point = NULL;
	while(s->philo->id <= i)
	{
		point = s->philo;
		s->philo = s->philo->next;
		free(point);
	}
	write(1, "Error Malloc init Philo\n", 25);
	return (1);
}

int	init_philo(t_general *s)
{
	t_philo *point;
	t_philo	*start;
	int		i;

	i = 1;
	s->philo = malloc(sizeof(t_philo));
	s->philo->next = NULL;
	point = s->philo;
	start = point;
	while (i < s->info.philo + 1)
	{
		point->id = i;
		printf("%d\n", point->id);
		pthread_mutex_init(&point->lock, NULL);
		point->info = &s->info;
		point->dead = 0;
		point->total_eat = 0;
		if(i != s->info.philo)
		{
			point->next = malloc(sizeof(t_philo));
			if (!point->next && error_free(s, i))
			return (1);
		}
		else
			point->next = start;
		point = point->next;
		i++;
	}
	i = 0;
	point = s->philo;
	// while (1)
	// {
	// 	printf("1. id %d\n", point->id);
	// 	printf("2. start_time%d\n", point->info->start_time);
	// 	i++;
	// 	point = point->next;
	// }
	
	return (0);
}