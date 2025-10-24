/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:55:52 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/07/18 20:56:17 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set_value(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != 0)
		if (set[i++] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	len_s1;
	unsigned int	rm_begin;
	unsigned int	rm_end;

	rm_begin = 0;
	len_s1 = ft_strlen(s1) - 1;
	rm_end = 0;
	if (*s1 == '\0')
		return (ft_calloc(1, 0));
	while (ft_set_value(set, s1[rm_begin]))
		rm_begin++;
	while (ft_set_value(set, s1[len_s1]))
	{
		rm_end++;
		if (len_s1 <= 0)
			break ;
		len_s1--;
	}
	if (((rm_begin == rm_end) && (rm_begin == ft_strlen(s1))) || *s1 == '\0')
		return (ft_calloc(1, 0));
	return (ft_substr(s1, rm_begin, (len_s1 - rm_begin) + 1));
}
