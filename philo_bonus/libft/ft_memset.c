/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 23:13:35 by csherill          #+#    #+#             */
/*   Updated: 2021/10/21 23:13:36 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	void	*temp;

	temp = b;
	i = 0;
	while (i < (int) len)
	{
		*(unsigned char *) b = c;
		b++;
		i++;
	}
	return (temp);
}
