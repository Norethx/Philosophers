/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:45:00 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/07/16 19:10:09 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned long	i;
	size_t			size_src;

	size_src = ft_strlen(src);
	i = 0;
	while ((i < size) && src[i] != '\0')
	{
		if (i == (size - 1))
			break ;
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (size_src);
}
