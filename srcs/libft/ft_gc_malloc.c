/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:09:14 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/09 16:30:14 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gc_list	*ft_gc_malloc(size_t size, t_gc_type type)
{
	t_gc_list		*new_gc;
	void			*new_c;
	t_gcext_list	*lst;

	lst = ft_gc_start();
	if (!lst || size > 2147483647)
		return (NULL);
	new_gc = malloc(sizeof(t_list));
	if (!new_gc)
		return (NULL);
	new_gc->type = type;
	new_c = malloc(size);
	new_gc->content = new_c;
	if (!new_gc->content)
	{
		free(new_gc);
		return (NULL);
	}
	ft_gclstadd_back(&lst, new_gc);
	return (new_gc);
}
