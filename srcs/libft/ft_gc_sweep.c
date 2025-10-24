/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_sweep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:01:43 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/09 16:30:47 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_sweep_aux(t_gc_list **gc_del);

void	ft_gc_sweep(void)
{
	t_gcext_list	*gc;
	t_gc_list		*aux[2];

	gc = ft_gc_start();
	if (!gc)
		return ;
	aux[0] = gc->head;
	while (aux[0])
	{
		if (aux[0]->type == GC_DATA && !aux[0]->marked)
		{
			aux[1] = aux[0];
			aux[0] = aux[0]->next;
			ft_sweep_aux(&aux[1]);
			aux[1] = NULL;
		}
		else
		{
			aux[0]->marked = 0;
			aux[0] = aux[0]->next;
		}
	}
	if (!gc->tail)
		gc->tail = NULL;
	return ;
}

static void	ft_sweep_aux(t_gc_list **gc_del)
{
	t_gcext_list	*gc;

	gc = ft_gc_start();
	gc = ft_gc_start();
	if (!gc || !gc_del || !gc_del[0])
		return ;
	if (gc->head == gc_del[0])
		gc->head = gc_del[0]->next;
	if (gc->tail == gc_del[0])
		gc->tail = gc_del[0]->prev;
	if (gc_del[0]->prev)
		gc_del[0]->prev->next = gc_del[0]->next;
	if (gc_del[0]->next)
		gc_del[0]->next->prev = gc_del[0]->prev;
	if (gc->head)
		gc->head->prev = NULL;
	if (gc->tail)
		gc->tail->next = NULL;
	ft_gclstdelone(gc_del, free);
	*gc_del = NULL;
}
