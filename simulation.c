#include "philo.h"

int	itoa_nomalloc(int n, char **str)
{
	int		i;
	int		temp;
	
	temp = n;
	i = 0;
	if (!n)
	{
		(*str)[0]= '0';
		(*str)[1] = ' ';
		return (2);
	}
	while (temp != 0)
	{
		temp /= 10;
		i++;
	}
	temp = i;
	while (n != 0)
	{
		(*str)[i - 1] = "0123456789"[n % 10];
		n /= 10;
		i--;
	}
	(*str)[temp] = ' ';
	(*str)[temp + 1] = '\0';
	return (temp + 1);
}

int	join(char **str, char *what)
{
	int		i;
	char	*temp;

	i = 0;
	while (what[i] != 0)
	{
		(*str)[i] = what[i];
		i = i + 1;
	}
	(*str)[i] = '\0';
	i += 1;
	return (i);
}

void	output_to_terminal(char *str, int time, t_philo *s)
{
	char	buf[100];
	int		i;
	char	*point;

	point = buf;
	i = 0;
	i += itoa_nomalloc(time, &point);
	point = buf + i;
	i += itoa_nomalloc(s->id, &point);
	point = buf + i;
	i += join(&point, str);
	point = buf + i;
	*point = '\n';
	// if (pthread_mutex_lock(&s->info->write) != 0 )
		// printf("didnt lock\n");
	pthread_mutex_lock(&s->info->write);
	write(1, buf, i);
	// if (pthread_mutex_unlock(&s->info->write))
	// 	printf("didnt unlock\n");
}

void	eat_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock);
	output_to_terminal("fork left\n", get_time(philo->info->start_time), philo);
	pthread_mutex_unlock(&philo->info->write);
	pthread_mutex_lock(&philo->next->lock);
	output_to_terminal("fork right\n", get_time(philo->info->start_time), philo);
	pthread_mutex_unlock(&philo->info->write);
	philo->total_eat += 1;
	philo->last_time_eat = get_time(philo->info->start_time);
	usleep(philo->info->eat * 1000);
	output_to_terminal("philo eating\n", get_time(philo->info->start_time), philo);
	pthread_mutex_unlock(&philo->info->write);

	pthread_mutex_unlock(&philo->lock);
	pthread_mutex_unlock(&philo->next->lock);
}

void	sleep_philo(t_philo *philo)
{

	output_to_terminal("philo sleep \n", get_time(philo->info->start_time), philo);
	pthread_mutex_unlock(&philo->info->write);
	usleep(philo->info->sleep * 1000);
}

void	thinking_philo(t_philo *philo)
{
	output_to_terminal("philo thinking \n", get_time(philo->info->start_time), philo);
	pthread_mutex_unlock(&philo->info->write);
}

void	*thread(void *s)
{
	t_philo	*philo;

	philo = (t_philo *)s;
	while (1)
	{
		eat_philo(philo);
		sleep_philo(philo);
		thinking_philo(philo);
	}
}

int	start_simulation(t_general *s)
{
	int		i;
	int		temp;
	t_philo	*point;

	i = 0;
	point = s->philo;
	temp = s->info.philo;
	while (i < temp) 
	{
		usleep(10);
		point->last_time_eat = get_time(s->info.start_time);
		pthread_create(&point->thread, NULL, thread, (void *)point);
		point = point->next;
		i++;
	}
	return (0);
}
