/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:24:58 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/08/20 12:33:59 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*n_arr;
	unsigned int	i_nmemb;
	unsigned int	i_size;

	i_nmemb = nmemb;
	i_size = size;
	if (nmemb == 0 || size == 0)
	{
		n_arr = malloc(1);
		if (!n_arr)
			return (NULL);
		ft_bzero(n_arr, 1);
		return (n_arr);
	}
	if (((i_nmemb * i_size) / i_size) != nmemb)
		return ((void *)0);
	n_arr = malloc(size * nmemb);
	if (!n_arr)
		return (NULL);
	ft_bzero(n_arr, (nmemb * size));
	return (n_arr);
}
