/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:48:25 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/03 14:28:40 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ext_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*new;
	t_ext_list	*head;

	head = ft_calloc(1, sizeof(t_ext_list));
	if (!lst || !f || !del)
		return ((void *)0);
	new = ft_lstnew((f)(lst->content));
	if (!new)
		return ((void *)0);
	head->head = new;
	head->tail = new;
	lst = lst->next;
	while (lst)
	{
		ft_lstadd_back(&head, ft_lstnew((f)(lst->content)));
		lst = lst->next;
	}
	return (head);
}
