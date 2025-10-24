/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:40:29 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/09 16:30:11 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_gc_init(void)
{
	t_gcext_list	*gc;

	gc = ft_gc_start();
	if (!gc)
		return (1);
	if (!ft_gc_new_root("gc_meta") || !ft_gc_new_root("gc_roots"))
		return (1);
	return (0);
}
