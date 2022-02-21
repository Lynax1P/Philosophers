/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 23:14:51 by csherill          #+#    #+#             */
/*   Updated: 2021/10/21 23:14:52 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	symbol_in_set(char s1, char const *set)
{
	while (*set)
	{
		if (*set == s1)
			return (1);
		set++;
	}
	return (0);
}

static int	get_result_len(const char *s1, const char *set)
{
	int	result_len;

	result_len = 0;
	while (*s1)
	{
		if (symbol_in_set(*s1, set))
			result_len++;
		else
			result_len = 0;
		s1++;
	}
	return (result_len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		s1_len;
	int		result_len;

	if (s1 == 0 || set == 0)
		return (0);
	while (*s1)
	{
		if (!symbol_in_set(*s1, set))
			break ;
		s1++;
	}
	s1_len = (int)ft_strlen(s1);
	result_len = get_result_len(s1, set);
	result = malloc(s1_len - result_len + 1);
	if (result == 0)
		return (0);
	ft_strlcpy(result, s1, s1_len - result_len + 1);
	return (result);
}
