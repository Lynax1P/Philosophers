/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 23:12:04 by csherill          #+#    #+#             */
/*   Updated: 2021/10/21 23:12:05 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*result;
	unsigned long	i;

	i = (unsigned long) count * (unsigned long) size;
	result = malloc(i);
	if (result)
	{
		ft_bzero(result, i);
		return (result);
	}
	return (0);
}
