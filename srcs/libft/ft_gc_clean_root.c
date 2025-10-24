/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_clean_root.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 10:03:21 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/09 16:29:50 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_to_root(char *categ);

t_list	*ft_gc_clean_root(char *categ)
{
	t_ext_list	*aux_ext;
	t_list		*aux_tlist;

	if (!categ || !ft_strcmp(categ, "gc_roots") || !ft_strcmp(categ, "gc_meta"))
		return (NULL);
	aux_tlist = ft_to_root(categ);
	if (!aux_tlist)
		return (NULL);
	aux_ext = ((t_root_list *)((t_gc_list *)aux_tlist->content)->content)->lst;
	while (aux_ext->head)
		ft_gc_rm_root(&aux_ext, aux_ext->head);
	return (aux_tlist);
}

static t_list	*ft_to_root(char *categ)
{
	t_gc_list		*aux;
	t_gcext_list	*all_allocs;
	t_list			*aux_tlist;

	all_allocs = ft_gc_start();
	aux_tlist = NULL;
	if (!all_allocs)
		return (NULL);
	aux = all_allocs->head;
	while (aux && !(aux->type == GC_SYSROOT
			&& !ft_strcmp(((t_root_list *)aux->content)->categ, "gc_roots")))
		aux = aux->next;
	if (aux->type == GC_SYSROOT && !ft_strcmp(ft_to_root_list(aux)->categ,
			"gc_roots"))
		aux_tlist = ((t_root_list *)aux->content)->lst->head;
	else
		return (NULL);
	while (aux_tlist)
	{
		if (!ft_strcmp(ft_to_root_list(aux_tlist->content)->categ, categ))
			return (aux_tlist);
		aux_tlist = aux_tlist->next;
	}
	return (NULL);
}
