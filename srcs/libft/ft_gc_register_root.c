/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_register_root.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:23:14 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/24 12:32:48 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_add_root(t_ext_list *root, t_gc_list *n_root);

void	*ft_gc_register_root(t_gc_list *n_root, char *categ)
{
	t_gc_list		*aux;
	t_gcext_list	*all_allocs;
	t_list			*aux_tlist;

	all_allocs = ft_gc_start();
	aux_tlist = NULL;
	if (!categ || !n_root || !all_allocs || !ft_strcmp(categ, "gc_roots")
		|| !ft_strcmp(categ, "gc_meta"))
		return (NULL);
	ft_gc_new_root(categ);
	aux = all_allocs->head;
	while (aux && !(aux->type == GC_SYSROOT
			&& !ft_strcmp(((t_root_list *)aux->content)->categ, "gc_roots")))
		aux = aux->next;
	if (!aux || !ft_strcmp(categ, "gc_roots") || !ft_strcmp(categ, "gc_meta"))
		return (NULL);
	aux_tlist = ((t_root_list *)aux->content)->lst->head;
	while (aux_tlist)
	{
		if (!ft_strcmp(ft_to_root_list(aux_tlist->content)->categ, categ))
			return (ft_add_root(ft_to_root_list(aux_tlist->content)->lst,
					n_root));
		aux_tlist = aux_tlist->next;
	}
	return (NULL);
}

static void	*ft_add_root(t_ext_list *root, t_gc_list *n_root)
{
	t_list	*new;

	new = ft_calloc(1, sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = n_root;
	ft_lstadd_back(&root, new);
	return (root);
}
