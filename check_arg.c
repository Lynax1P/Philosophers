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

int		valid_string(int argc, char const *argv[])
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
