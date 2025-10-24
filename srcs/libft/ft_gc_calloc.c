/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_calloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:24:58 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/09 17:09:07 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gc_list	*ft_gc_calloc(size_t nmemb, size_t size, t_gc_type type)
{
	t_gc_list		*new;
	unsigned int	i_nmemb;
	unsigned int	i_size;
	t_gcext_list	*lst;

	lst = ft_gc_start();
	i_nmemb = nmemb;
	i_size = size;
	if (!lst || ((i_nmemb * i_size) / i_size) != nmemb)
		return (NULL);
	new = ft_calloc(1, sizeof(t_gc_list));
	if (!new)
		return (NULL);
	new->type = type;
	new->content = ft_calloc(nmemb, size);
	if (!new->content)
	{
		free(new);
		return (NULL);
	}
	ft_gclstadd_back(&lst, new);
	return (new);
}
