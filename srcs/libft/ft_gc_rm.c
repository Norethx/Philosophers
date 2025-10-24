/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_rm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 21:22:56 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/09 16:30:39 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_gc_rm(t_gc_list **lst)
{
	t_gcext_list	*all_allocs;

	all_allocs = ft_gc_start();
	if (!all_allocs || !lst || !*lst)
		return (1);
	if (all_allocs->head == *lst)
		all_allocs->head = (*lst)->next;
	if (all_allocs->tail == *lst)
		all_allocs->tail = (*lst)->prev;
	if ((*lst)->prev)
		(*lst)->prev->next = (*lst)->next;
	if ((*lst)->next)
		(*lst)->next->prev = (*lst)->prev;
	if (all_allocs->tail)
		all_allocs->tail->next = NULL;
	if (all_allocs->head)
		all_allocs->head->prev = NULL;
	ft_gclstdelone(lst, free);
	return (0);
}
