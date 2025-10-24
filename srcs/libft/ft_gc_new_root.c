/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_new_root.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:17:13 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/09 16:30:21 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_new_root_aux(char *categ, t_gc_type type);
static int	ft_add_meta(t_gc_list **lst);
static void	*ft_add_roots_aux(t_gc_list *new_root, char *categ);

void	*ft_gc_new_root(char *categ)
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
		return (ft_new_root_aux(categ, GC_SYSROOT));
	else
		aux_tlist = ((t_root_list *)aux->content)->lst->head;
	if (!ft_strcmp(categ, "gc_roots") || !ft_strcmp(categ, "gc_meta"))
		return (NULL);
	while (aux_tlist)
	{
		if (!ft_strcmp(ft_to_root_list(aux_tlist->content)->categ, categ))
			return (NULL);
		aux_tlist = aux_tlist->next;
	}
	return (ft_new_root_aux(categ, GC_ROOT));
}

static void	*ft_new_root_aux(char *categ, t_gc_type type)
{
	t_gc_list	*new[3];
	int			i;

	i = 0;
	new[2] = ft_gcfct_register(ft_root_newlst(), type);
	new[0] = ft_gcfct_register(ft_strdup(categ), GC_META);
	new[1] = ft_gcfct_register(ft_ext_newlst(), GC_META);
	if (!new[0] || !new[1] || !new[2])
		while (i < 3)
			if (new[i++])
				ft_gc_rm(&new[i - 1]);
	if (!new[0])
		return (NULL);
	((t_root_list *)new[2]->content)->categ = (char *)new[0]->content;
	((t_root_list *)new[2]->content)->lst = (t_ext_list *)new[1]->content;
	if (ft_add_meta(new))
		return (NULL);
	if (type == GC_ROOT && !ft_add_roots_aux(new[2], "gc_roots"))
		return (NULL);
	return (new[2]);
}

static int	ft_add_meta(t_gc_list **lst)
{
	t_list	*new[3];
	int		i;

	i = 0;
	while (i < 2)
	{
		new[i] = ft_add_roots_aux(lst[i], "gc_meta");
		if (!new[i++])
		{
			while (i-- > 0)
			{
				if (new[i])
				{
					if (i == 0 && new[i]->prev)
						new[i]->prev->next = NULL;
					free(new[i]);
				}
			}
			return (1);
		}
	}
	return (0);
}

static void	*ft_add_roots_aux(t_gc_list *new_root, char *categ)
{
	t_list			*new;
	t_root_list		*roots;
	t_gcext_list	*gc;
	t_gc_list		*aux;

	gc = ft_gc_start();
	if (!gc || !gc->head)
		return (NULL);
	aux = gc->head;
	while (aux)
	{
		roots = aux->content;
		if ((aux->type == GC_ROOT || aux->type == GC_SYSROOT)
			&& !ft_strcmp(roots->categ, categ))
			break ;
		aux = aux->next;
	}
	if (!aux)
		return (NULL);
	new = ft_calloc(1, sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = new_root;
	ft_lstadd_back(&(roots->lst), new);
	return (new);
}
