/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_rm_root.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 10:03:44 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/09 16:30:34 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_gc_rm_root(t_ext_list **root, t_list *rm_root)
{
	if (!*root || !rm_root)
		return ;
	if (root[0]->head == rm_root)
		root[0]->head = root[0]->head->next;
	if (root[0]->tail == rm_root)
		root[0]->tail = root[0]->tail->prev;
	if (rm_root->prev)
		rm_root->prev->next = rm_root->next;
	if (rm_root->next)
		rm_root->next->prev = rm_root->prev;
	free(rm_root);
}
