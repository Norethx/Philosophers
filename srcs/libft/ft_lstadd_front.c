/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:35:06 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/02 11:57:49 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_ext_list **lst, t_list *new)
{
	if (!new || !*lst)
		return ;
	if (!lst[0]->head && !lst[0]->tail)
	{
		lst[0]->head = new;
		lst[0]->tail = new;
		return ;
	}
	new->next = lst[0]->head;
	lst[0]->head->prev = new;
	lst[0]->head = new;
}
