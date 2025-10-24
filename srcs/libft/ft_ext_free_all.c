/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ext_free_all.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:31:18 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/02 11:57:07 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ext_free_all(t_ext_list **lst)
{
	t_list	*aux;

	if (!lst[0])
		return ;
	while (lst[0]->head)
	{
		aux = lst[0]->head;
		lst[0]->head = aux->next;
		ft_lstdelone(&aux, &free);
	}
	lst[0]->tail = NULL;
	free(lst[0]);
	lst[0] = NULL;
	return ;
}
