/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 05:29:42 by csherill          #+#    #+#             */
/*   Updated: 2022/01/16 10:21:27 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char const *argv[])
{
	t_general	s;

	s.info.start_time = get_time(0);
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
