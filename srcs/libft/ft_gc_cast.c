/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_cast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 20:26:54 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/09 16:29:43 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_gc_list	*ft_to_gc_list(void *x)
{
	return ((t_gc_list *)x);
}

inline t_root_list	*ft_to_root_list(void *x)
{
	return ((t_root_list *)((t_gc_list *)x)->content);
}
