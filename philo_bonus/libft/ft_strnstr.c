/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 23:14:44 by csherill          #+#    #+#             */
/*   Updated: 2022/01/16 09:38:32 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *search, size_t len)
{
	size_t	i;
	size_t	n;
	size_t	size;

	i = 0;
	n = 0;
	if (!*search)
		return (&*(char *)src);
	size = ft_strlen(search);
	while (len > i && src[i] != 0)
	{
		if (src[i] == search[n])
			while (src[i + n] == search[n] && (search[n] != 0) \
			&& (src[i + n] != 0) && i + n < len)
				n++;
		if (size == n)
			return ((char *)&src[i]);
		n = 0;
		i++;
	}
	return (NULL);
}
