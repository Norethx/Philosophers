/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 10:03:41 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/09 16:30:08 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_gc_del_meta(char *categ);
static t_gc_list	*ft_gc_clean_meta(char *categ);
static t_gc_list	*ft_to_root(char *categ);

void	ft_gc_end(void)
{
	t_gc_list		*aux;
	t_gcext_list	*all_allocs;
	t_list			*aux_tlist[2];

	all_allocs = ft_gc_start();
	aux_tlist[0] = NULL;
	if (!all_allocs)
		return ;
	aux = all_allocs->head;
	while (aux && !(aux->type == GC_SYSROOT
			&& !ft_strcmp(((t_root_list *)aux->content)->categ, "gc_roots")))
		aux = aux->next;
	if (aux->type == GC_SYSROOT && !ft_strcmp(ft_to_root_list(aux)->categ,
			"gc_roots"))
		aux_tlist[0] = ((t_root_list *)aux->content)->lst->head;
	while (aux_tlist[0])
	{
		aux_tlist[1] = aux_tlist[0];
		aux_tlist[0] = aux_tlist[0]->next;
		ft_gc_del_root(ft_to_root_list(aux_tlist[1]->content)->categ);
	}
	ft_gc_collect();
	ft_gc_del_meta("gc_roots");
	ft_gc_del_meta("gc_meta");
	free(all_allocs);
}

static void	ft_gc_del_meta(char *categ)
{
	t_root_list	*aux_root[2];
	t_gc_list	*aux_gc;

	aux_gc = ft_gc_clean_meta(categ);
	aux_root[0] = aux_gc->content;
	if (!aux_root[0])
		return ;
	ft_gc_rm_meta(categ);
	ft_gc_rm(&aux_gc);
}

static t_gc_list	*ft_gc_clean_meta(char *categ)
{
	t_gc_list	*aux;
	t_ext_list	*aux_ext;

	aux = ft_to_root(categ);
	if (!aux)
		return (NULL);
	if (!ft_strcmp(categ, "gc_meta"))
		return (aux);
	aux_ext = ((t_root_list *)aux->content)->lst;
	while (aux_ext->head)
		ft_gc_rm_root(&aux_ext, aux_ext->head);
	return (aux);
}

static t_gc_list	*ft_to_root(char *categ)
{
	t_gc_list		*aux;
	t_gcext_list	*all_allocs;

	all_allocs = ft_gc_start();
	if (!all_allocs)
		return (NULL);
	aux = all_allocs->head;
	while (aux)
	{
		if (aux->type == GC_SYSROOT
			&& !ft_strcmp(((t_root_list *)aux->content)->categ, categ))
			return (aux);
		aux = aux->next;
	}
	return (NULL);
}
