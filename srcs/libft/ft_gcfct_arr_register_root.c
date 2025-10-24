/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gcfct_arr_register_root.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:07:46 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/29 11:17:58 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_gcfct_arr_register_root(void **content, t_gc_type type, char *root)
{
	t_gc_list		*new;
	t_gcext_list	*lst;
	int				i;

	i = 0;
	lst = ft_gc_start();
	if (!content || !lst)
		return (NULL);
	new = ft_calloc(1, sizeof(t_gc_list));
	if (!new)
	{
		free(content);
		return (NULL);
	}
	new->content = content;
	new->type = type;
	ft_gclstadd_back(&lst, new);
	while (content[i])
		ft_gcfct_register_root(content[i++], type, root);
	ft_gc_register_root(new, root);
	return (new->content);
}
