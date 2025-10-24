/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:21:45 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/09 16:30:43 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gcext_list	*ft_gc_start(void)
{
	static t_gcext_list	*all_alocs = NULL;

	if (!all_alocs)
	{
		all_alocs = ft_calloc(1, sizeof(t_ext_list));
		if (!all_alocs)
			return (NULL);
	}
	return (all_alocs);
}
