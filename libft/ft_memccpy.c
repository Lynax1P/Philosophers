/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 23:13:15 by csherill          #+#    #+#             */
/*   Updated: 2021/10/21 23:13:16 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int				i;
	unsigned char	s;

	if (src == 0 && dst == 0)
		return (dst);
	i = 0;
	while (i < (int) n)
	{
		s = *(unsigned char *) src;
		*(unsigned char *) dst = s;
		i++;
		src++;
		dst++;
		if (s == (unsigned char) c)
			return (dst);
	}
	return (0);
}
