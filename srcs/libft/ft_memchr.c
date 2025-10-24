/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:57:03 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/07/25 10:48:55 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long	i;

	if (n == 0)
		return ((void *)0);
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)&((unsigned char *) s)[i]);
		i++;
	}
	return ((void *)0);
}
