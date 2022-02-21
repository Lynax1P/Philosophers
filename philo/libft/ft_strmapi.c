/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 23:14:35 by csherill          #+#    #+#             */
/*   Updated: 2021/10/21 23:17:44 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned
											int, char))
{
	int		i;
	size_t	size;
	char	symbol;
	char	*result;

	if (s == 0)
		return (0);
	i = 0;
	size = ft_strlen(s);
	result = malloc(size + 1);
	if (result == 0)
		return (0);
	while (*s)
	{
		symbol = f(i, *s);
		*(result + i) = symbol;
		s++;
		i++;
	}
	*(result + i) = 0;
	return (result);
}
