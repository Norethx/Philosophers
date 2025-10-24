/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:47:47 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/29 11:17:48 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_include_nnode(t_ext_list **lst, char *str);
static char	*ft_fillnl(t_ext_list **lst, int size_nl);
static int	ft_verify_nlend(t_list **lst);
static int	ft_fillstock(int fd, t_ext_list **head);

char	*get_next_line(int fd)
{
	static t_ext_list	*stock[FILE_DESCRIPTORS] = {0};
	char				*rtn;
	int					size_nl;

	rtn = NULL;
	size_nl = 0;
	if (fd < 0)
	{
		ft_cleanls(&stock[fd]);
		stock[fd] = NULL;
		return (NULL);
	}
	while (size_nl == 0)
	{
		if (ft_fillstock(fd, &stock[fd]))
			return (ft_cleanls(&stock[fd]));
		size_nl = ft_verify_nlend(&stock[fd]->head);
	}
	rtn = ft_fillnl(&stock[fd], size_nl);
	if (!rtn)
		return (ft_cleanls(&stock[fd]));
	if (stock[fd] && (!stock[fd]->head || (stock[fd]->head
				&& ((char *)stock[fd]->head->content)[0] == 0)))
		ft_cleanls(&stock[fd]);
	return (rtn);
}

static int	ft_fillstock(int fd, t_ext_list **head)
{
	int		size_read;
	char	*b_read;

	b_read = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!b_read)
		return (1);
	size_read = read(fd, b_read, BUFFER_SIZE);
	if ((size_read < 0) || (size_read == 0 && !*head))
		free(b_read);
	if ((size_read < 0) || (size_read == 0 && !*head))
		return (1);
	if (!head[0])
		head[0] = ft_calloc(sizeof(t_ext_list), 1);
	if (!head[0])
	{
		free(b_read);
		return (1);
	}
	if (ft_include_nnode(head, b_read))
	{
		free(b_read);
		return (1);
	}
	return (0);
}

static int	ft_include_nnode(t_ext_list **lst, char *str)
{
	t_list	*aux[2];

	aux[0] = ft_calloc(sizeof(t_list), 1);
	if (!aux[0])
		return (1);
	aux[0]->content = str;
	if (lst[0] && lst[0]->head)
	{
		aux[1] = lst[0]->tail;
		if (aux[1] && ((char *)aux[1]->content)[0] == str[0] && str[0] == 0)
		{
			free(str);
			free(aux[0]);
			return (0);
		}
		aux[0]->prev = aux[1];
		aux[1]->next = aux[0];
		lst[0]->tail = aux[0];
		return (0);
	}
	lst[0]->head = aux[0];
	lst[0]->tail = aux[0];
	return (0);
}

static char	*ft_fillnl(t_ext_list **lst, int size_nl)
{
	t_list	*aux;
	int		i[2];
	char	*rtn;

	i[0] = 0;
	rtn = ft_calloc(size_nl + 1, 1);
	if (!rtn)
		return (NULL);
	while (i[0] < size_nl)
	{
		i[1] = 0;
		aux = lst[0]->head;
		while (i[0] < size_nl && (((char *)aux->content)[i[1]] != 0
			|| ((char *)aux->content)[0] == 0))
			rtn[i[0]++] = ((char *)aux->content)[i[1]++];
		if (((char *)aux->content)[i[1]] == 0 && aux == lst[0]->tail)
			lst[0]->tail = NULL;
		if (((char *)aux->content)[i[1]] == 0)
			lst[0]->head = aux->next;
		if (((char *)aux->content)[i[1]] == 0)
			ft_lstdelone(&aux, &free);
		else if (ft_lst_content_substr(&lst[0]->head, i[1], rtn))
			return (NULL);
	}
	return (rtn);
}

static int	ft_verify_nlend(t_list **lst)
{
	t_list	*tail;
	t_list	*aux;
	int		i;
	int		count;

	count = 0;
	tail = *lst;
	while (tail)
	{
		i = 0;
		while (((char *)tail->content)[i] != 0)
			if (((char *)tail->content)[i++] == '\n')
				return (count + i);
		count += i;
		aux = tail;
		tail = tail->next;
	}
	if (((char *)aux->content)[0] == 0)
		return (count);
	return (0);
}
