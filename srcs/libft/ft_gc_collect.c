/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_collect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 00:33:18 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/11 11:39:43 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_mark_root(t_root_list *root);

void	ft_gc_collect(void)
{
	t_gcext_list	*gc;
	t_gc_list		*aux;
	t_root_list		*roots;
	t_list			*aux_roots;

	gc = ft_gc_start();
	if (!gc || !gc->head)
		return ;
	aux = gc->head;
	while (aux)
	{
		roots = aux->content;
		if (aux->type == GC_SYSROOT && !ft_strcmp(roots->categ, "gc_roots"))
			break ;
		aux = aux->next;
	}
	if (!aux || aux->type != GC_SYSROOT)
		return ;
	aux_roots = roots->lst->head;
	while (aux_roots)
	{
		ft_mark_root(ft_to_root_list(aux_roots->content));
		aux_roots = aux_roots->next;
	}
	ft_gc_sweep();
}

static void	ft_mark_root(t_root_list *root)
{
	t_list	*aux_root;

	aux_root = root->lst->head;
	while (aux_root)
	{
		ft_gc_mark(aux_root->content);
		aux_root = aux_root->next;
	}
}
