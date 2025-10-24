/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_del_root.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 10:03:37 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/24 11:50:30 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_root_list	*ft_fix_root(void);

void	ft_gc_del_root(char *categ)
{
	t_list		*aux;
	t_root_list	*aux_root[2];
	t_gc_list	*aux_gc;

	aux = ft_gc_clean_root(categ);
	aux_gc = NULL;
	aux_root[0] = ((t_gc_list *)aux->content)->content;
	if (!aux_root[0])
		return ;
	aux_root[1] = ft_fix_root();
	if (!aux_root[1] || !aux_root[0])
		return ;
	ft_gc_rm_meta(categ);
	if (aux_root[1]->lst->head == aux)
		aux_root[1]->lst->head = aux_root[1]->lst->head->next;
	if (aux_root[1]->lst->tail == aux)
		aux_root[1]->lst->tail = aux_root[1]->lst->tail->prev;
	if (aux->prev)
		aux->prev->next = aux->next;
	if (aux->next)
		aux->next->prev = aux->prev;
	aux_gc = aux->content;
	ft_gc_rm(&aux_gc);
	free(aux);
}

static t_root_list	*ft_fix_root(void)
{
	t_gc_list		*aux;
	t_gcext_list	*all_allocs;

	all_allocs = ft_gc_start();
	if (!all_allocs)
		return (NULL);
	aux = all_allocs->head;
	while (aux && !(aux->type == GC_SYSROOT
			&& !ft_strcmp(((t_root_list *)aux->content)->categ, "gc_roots")))
		aux = aux->next;
	if (aux->type == GC_SYSROOT && !ft_strcmp(ft_to_root_list(aux)->categ,
			"gc_roots"))
		return ((t_root_list *)aux->content);
	else
		return (NULL);
}
