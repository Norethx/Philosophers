/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gclstadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 22:33:13 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/09 16:30:58 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_gclstadd_back(t_gcext_list **lst, t_gc_list *new)
{
	if (!lst[0] || !new)
		return ;
	new->next = NULL;
	if (!lst[0]->tail && !lst[0]->head)
	{
		new->prev = NULL;
		lst[0]->head = new;
		lst[0]->tail = new;
		return ;
	}
	new->prev = lst[0]->tail;
	lst[0]->tail->next = new;
	lst[0]->tail = new;
}
