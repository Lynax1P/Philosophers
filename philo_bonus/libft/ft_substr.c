/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 23:14:55 by csherill          #+#    #+#             */
/*   Updated: 2021/10/21 23:14:56 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ret_empty_string(void)
{
	char	*result;

	result = malloc(1);
	if (result == 0)
		return (0);
	*result = 0;
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring;
	unsigned int	count;
	unsigned int	s_len;

	if (s == 0)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ret_empty_string());
	if (len > s_len)
		len = s_len;
	count = 0;
	while (count++ < start)
		s++;
	substring = malloc(len + 1);
	if (substring == 0)
		return (0);
	count = 0;
	while (count < len)
	{
		*(substring++) = *(s++);
		count++;
	}
	*substring = 0;
	return (substring - count);
}
