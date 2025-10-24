/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:15:24 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/05 12:30:16 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_extension(const char *str, const char *ext)
{
	int	len_str;
	int	i;

	i = 0;
	if (!str || !ext || ft_strlen(str) < ft_strlen(ext) || !ext[0] || !str[0])
		return (1);
	len_str = ft_strlen(str) - ft_strlen(ext);
	while (str[len_str + i] || ext[i])
	{
		if (str[len_str + i] != ext[i])
			return (1);
		i++;
	}
	return (0);
}
