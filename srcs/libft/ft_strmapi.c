/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:16:31 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/07/24 10:29:52 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*n_str;

	i = 0;
	if (!s)
		return ((void *)0);
	n_str = (char *)ft_calloc(ft_strlen(s) + 1, 1);
	if (!n_str)
		return (NULL);
	while (s[i] != '\0')
	{
		n_str[i] = f(i, s[i]);
		i++;
	}
	n_str[i] = '\0';
	return (n_str);
}
