/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 23:14:19 by csherill          #+#    #+#             */
/*   Updated: 2021/10/21 23:14:20 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result;
	unsigned int	s1_len;
	unsigned int	s2_len;
	unsigned int	total_len;

	if (s1 == 0 || s2 == 0)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len + 1;
	result = malloc(total_len);
	if (result == 0)
		return (0);
	while (*s1)
		*(result++) = *(s1++);
	*result = 0;
	result -= s1_len;
	ft_strlcat(result, s2, total_len);
	return (result);
}
