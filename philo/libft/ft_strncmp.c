/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 23:14:39 by csherill          #+#    #+#             */
/*   Updated: 2021/10/21 23:14:40 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned long	count;

	if (n == 0)
		return (0);
	count = 0;
	while (*s1 == *s2 && count < n - 1)
	{
		if (*s1 == '\0' && *s2 == '\0')
			return (*(unsigned char *) s1 - *(unsigned char *) s2);
		s1++;
		s2++;
		count++;
	}
	return (*(unsigned char *) s1 - *(unsigned char *) s2);
}
