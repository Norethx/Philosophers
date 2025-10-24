/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 19:03:22 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/03 14:27:10 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_cleanls(t_ext_list **lst)
{
	t_list	*aux;

	if (!lst[0])
		return ((void *)0);
	while (lst[0]->head)
	{
		aux = lst[0]->head;
		lst[0]->head = aux->next;
		free(aux->content);
		free(aux);
	}
	free(lst[0]);
	aux = NULL;
	lst[0] = NULL;
	return ((void *)0);
}

int	ft_lst_content_substr(t_list **lst, int loc, char *sec)
{
	int		i;
	int		len;
	char	*new_str;
	t_list	*aux;

	i = 0;
	aux = *lst;
	len = ft_strlen((char *)aux->content);
	new_str = ft_calloc((size_t)((len - loc) + 1), 1);
	if (!new_str)
		free(sec);
	if (!new_str)
		return (1);
	while (((char *)aux->content)[i + loc] != 0)
	{
		new_str[i] = ((char *)aux->content)[loc + i];
		i++;
	}
	free(aux->content);
	aux->content = new_str;
	return (0);
}
