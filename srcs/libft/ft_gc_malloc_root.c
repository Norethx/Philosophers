/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_malloc_root.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:09:14 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/29 11:17:28 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_gc_malloc_root(size_t size, t_gc_type type, char *root)
{
	t_gc_list	*new;

	new = ft_gc_malloc(size, type);
	if (!new)
		return (NULL);
	ft_gc_register_root(new, root);
	return (new->content);
}
