#include "philo.h"

void	*test(void *s)
{
	t_philo *philo;
	int		time;

	philo = (t_philo *)s;
	printf("2\n");
	while (1)
	{
		time = get_time(philo->info->start_time);
	// 	// printf("%d \n",time);
		output_to_terminal("test \n", time, philo);
		// printf("%d \n",time);

	}
	return NULL;
}

int main(int argc, char const *argv[])
{
	t_general s;
	int			i;

	s.philo = malloc(sizeof(t_philo));
	s.philo->id = 1;
	s.philo->info = &s.info;
	s.info.start_time = 0; 
	s.info.start_time = get_time(s.info.start_time);
	// while (1)
	// {

	// // usleep(10000);
	i = get_time(s.info.start_time);
	pthread_mutex_init(&s.info.write, NULL);
	// printf("%d\n", i);
	// }
	
	// output_to_terminal("test \n", 0, s.philo);
	pthread_create(&s.philo->thread,	NULL, test,  (void *)s.philo);
	while (1)
	{
		/* code */
	};
	


	return 0;
}
