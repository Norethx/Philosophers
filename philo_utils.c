/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:29:58 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/11/06 14:40:42 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

long long	ft_atoll(const char *nptr)
{
	int			i;
	long long	result;
	long long	multiplier;

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
		result = (nptr[i++] - '0') + (result * 10);
	return (result * multiplier);
}

int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

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
		memset(n_arr, 0, 1);
		return (n_arr);
	}
	if (((i_nmemb * i_size) / i_size) != nmemb)
		return ((void *)0);
	n_arr = malloc(size * nmemb);
	if (!n_arr)
		return (NULL);
	memset(n_arr, 0, (nmemb * size));
	return (n_arr);
}
