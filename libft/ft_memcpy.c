/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 23:13:27 by csherill          #+#    #+#             */
/*   Updated: 2021/10/21 23:13:28 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	int		s;
	void	*temp;

	if (src == 0 && dst == 0)
		return (dst);
	temp = dst;
	i = 0;
	while (i < (int) n)
	{
		s = *(unsigned char *) src;
		*(unsigned char *) dst = s;
		i++;
		src++;
		dst++;
	}
	return (temp);
}
