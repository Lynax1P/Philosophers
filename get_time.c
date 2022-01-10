#include "philo.h"

int		get_time(int s)
{
	struct timeval		time;
	int					ms;
	
	gettimeofday(&time, NULL);
	ms = (time.tv_sec % 100000 * 1000) + (time.tv_usec / 1000) - s;
	return (ms); 
}