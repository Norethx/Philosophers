/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:38:52 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/02 11:58:57 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_ext_list **lst, void (*del)(void *))
{
	t_list	*aux;

	if (!*lst || !del || !lst[0]->head)
		return ;
	while (lst[0]->head)
	{
		aux = lst[0]->head;
		lst[0]->head = aux->next;
		ft_lstdelone(&aux, (del));
	}
	lst[0]->tail = NULL;
	free(lst[0]);
	lst[0] = NULL;
	return ;
}
