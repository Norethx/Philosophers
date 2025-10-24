/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_call_root.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:00:26 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/09 16:29:38 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_root_list	*ft_gc_call_root(char *categ)
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
	if (!aux && (!ft_strcmp(categ, "gc_meta") || !ft_strcmp(categ, "gc_roots")))
		return (NULL);
	else
		aux_tlist = ((t_root_list *)aux->content)->lst->head;
	while (aux_tlist)
	{
		if (!ft_strcmp(ft_to_root_list(aux_tlist->content)->categ, categ))
			return (aux_tlist->content);
		aux_tlist = aux_tlist->next;
	}
	return (NULL);
}
