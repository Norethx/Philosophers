/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:32:27 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/07/25 11:09:27 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	index;

	i = 0;
	index = 0;
	if (*little == 0)
		return (&((char *)big)[i]);
	while (big[i] != '\0' && i < len)
	{
		while ((big[i + index] == little[index]) && (i + index) < len)
		{
			index++;
			if (little[index] == '\0' && (i + index))
				return (&((char *)big)[i]);
		}
		i++;
		index = 0;
	}
	return ((void *)0);
}
