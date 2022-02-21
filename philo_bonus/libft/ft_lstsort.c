/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 23:13:11 by csherill          #+#    #+#             */
/*   Updated: 2021/10/21 23:13:12 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list **begin_list, int (*cmp)())
{
	void	*temp;
	t_list	*current;
	t_list	*comparing;

	current = (*begin_list);
	while (current)
	{
		comparing = current->next;
		while (comparing)
		{
			if ((*cmp)(current->content, comparing->content) > 0)
			{
				temp = current->content;
				current->content = comparing->content;
				comparing->content = temp;
			}
			comparing = comparing->next;
		}
		current = current->next;
	}
}
