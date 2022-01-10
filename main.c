#include "philo.h"
#include <fcntl.h>
#include <unistd.h>

int	main(int argc, char const *argv[])
{
	t_general	s;
	int i = 0;	

	s.info.start_time = 0;
	s.info.start_time = get_time(s.info.start_time);
	if (init_struct(argc, argv, &s))
		return (write(1, "|", 1));
	if (init_philo(&s))
		return (write(1, "||\n", 3));
	if (start_simulation(&s))
		return (write(1, "|||", 3));
	if (heart_rate_monitor(&s))
		return (write(1, "||||", 4));
	return (0);
}
