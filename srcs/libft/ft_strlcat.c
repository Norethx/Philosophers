/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:21:39 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/07/25 12:03:51 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t			len_dest;
	size_t			len_src;
	unsigned long	i;

	if (size <= ft_strlen(dest))
		return (ft_strlen(src) + size);
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	i = 0;
	while ((i < (size - len_dest - 1)) && src[i] != '\0')
	{
		dest[i + len_dest] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_src + len_dest);
}
