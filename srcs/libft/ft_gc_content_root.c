/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_content_root.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:00:26 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/29 11:18:02 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_gc_content_root(char *categ)
{
	void	*root;

	root = ft_gc_call_root(categ);
	if (!root)
		return (NULL);
	return (ft_to_root_list(root)->lst->head);
}
