/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 23:14:02 by csherill          #+#    #+#             */
/*   Updated: 2021/10/21 23:14:03 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_if_error(char **result, int len)
{
	len--;
	result--;
	while (len >= 0)
	{
		free(*result);
		if (len != 0)
			result--;
		len--;
	}
	free(result);
}

static int	get_result_size(char const *s, char c)
{
	int	size;

	size = 0;
	if (ft_strlen(s) == 1)
		size = 0;
	s++;
	while (*(s - 1))
	{
		if (*(s - 1) != c && (*s == c || *s == 0))
			size++;
		s++;
	}
	return (size);
}

static int	get_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static char	**make_all_job(char **result, const char *s, char c)
{
	int	count;
	int	len;

	count = 0;
	while (*s)
	{
		if (*s == c)
		{
			s++;
			continue ;
		}
		len = get_len(s, c);
		*result = malloc(len + 1);
		if (*result == 0)
		{
			free_if_error(result, count);
			return (0);
		}
		count++;
		ft_strlcpy(*result, s, len + 1);
		s += len;
		result++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		size;
	char	**result;

	if (s == 0)
		return (0);
	size = get_result_size(s, c);
	result = malloc((size + 1) * sizeof (char *));
	if (result == 0)
		return (0);
	result = make_all_job(result, s, c);
	if (result == 0)
		return (0);
	*result = 0;
	result -= size;
	return (result);
}
