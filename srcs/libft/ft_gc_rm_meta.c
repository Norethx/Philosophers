/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_rm_meta.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:26:45 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/09 16:30:31 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_gc_rm_meta_aux(t_ext_list **root, t_list *rm_root);

void	ft_gc_rm_meta(char *categ)
{
	t_gc_list		*aux;
	t_gcext_list	*all_allocs;
	t_list			*aux_tlist;

	aux_tlist = NULL;
	all_allocs = ft_gc_start();
	if (!all_allocs)
		return ;
	aux = all_allocs->head;
	while (aux && !(aux->type == GC_SYSROOT
			&& !ft_strcmp(((t_root_list *)aux->content)->categ, "gc_meta")))
		aux = aux->next;
	if (aux && aux->type == GC_SYSROOT
		&& !ft_strcmp(ft_to_root_list(aux)->categ, "gc_meta"))
		aux_tlist = ft_to_root_list(aux)->lst->head;
	while (aux_tlist)
	{
		if (!ft_strcmp(((t_gc_list *)aux_tlist->content)->content, categ))
		{
			ft_gc_rm_meta_aux(&(ft_to_root_list(aux)->lst), aux_tlist);
			return ;
		}
		aux_tlist = aux_tlist->next;
	}
	return ;
}

static void	ft_gc_rm_meta_aux(t_ext_list **root, t_list *rm_root)
{
	t_list	*aux[2];
	int		i;

	i = 0;
	aux[0] = rm_root;
	while (i < 2)
	{
		if (!*root || !aux[0])
			return ;
		if ((t_list *)root[0]->head == (t_list *)aux[0])
			root[0]->head = (t_list *)root[0]->head->next;
		if ((t_list *)root[0]->tail == (t_list *)aux[0])
			root[0]->tail = (t_list *)root[0]->tail->prev;
		if (aux[0]->prev)
			aux[0]->prev->next = (t_list *)aux[0]->next;
		if (aux[0]->next)
			aux[0]->next->prev = (t_list *)aux[0]->prev;
		aux[1] = aux[0]->next;
		ft_gc_rm(((t_gc_list **)&aux[0]->content));
		free(aux[0]);
		aux[0] = aux[1];
		i++;
	}
}
