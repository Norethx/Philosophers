/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:46:05 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/07/24 10:28:41 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned long	i;
	unsigned long	len_s1;
	unsigned long	len_s2;
	char			*new_str;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = 0;
	new_str = ft_calloc(1, ((len_s1 + len_s2 + 1)));
	if (!new_str)
		return (NULL);
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		new_str[len_s1 + i] = s2[i];
		i++;
	}
	new_str[len_s1 + i] = '\0';
	return (new_str);
}
