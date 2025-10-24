/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 22:07:43 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/03 14:27:25 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list *lst)
{
	t_list	*aux;
	t_list	*aux_2;
	void	*content_aux;

	aux = lst;
	while (aux->next)
	{
		aux_2 = aux->next;
		while (aux_2)
		{
			if (ft_strncmp(aux->content, aux_2->content, 100))
			{
				content_aux = aux->content;
				aux->content = aux_2->content;
				aux_2->content = content_aux;
			}
			aux_2 = aux_2->next;
		}
		aux = aux->next;
	}
}
