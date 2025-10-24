/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 20:03:25 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/24 16:06:22 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int			i;
	int			r_result;
	long long	result;
	int			multiplier;

	i = 0;
	result = 0;
	multiplier = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			multiplier *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (nptr[i++] - '0') + (result * 10);
		r_result = result * (long long)multiplier;
		if (r_result != (result * multiplier))
			return (0);
	}
	return (r_result);
}
