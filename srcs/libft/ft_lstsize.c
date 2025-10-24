/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 22:06:09 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/07/21 15:47:31 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*aux;

	i = 1;
	aux = lst;
	if (!lst)
		return (0);
	while (aux->next != ((void *)0))
	{
		aux = aux->next;
		i++;
	}
	return (i);
}
