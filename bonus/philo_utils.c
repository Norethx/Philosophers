/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:29:58 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/11/10 17:01:32 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int			ft_lenint(int n);

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

char	*ft_strjnbr(char const *s1, int s2)
{
	int				i;
	unsigned int	len_s[2];
	char			*nbr;
	char			*new_str;

	i = 0;
	nbr = ft_itoa(s2);
	if (!nbr)
		return (NULL);
	len_s[0] = ft_strlen(s1);
	len_s[1] = ft_strlen(nbr);
	new_str = ft_calloc(1, ((len_s[0] + len_s[1] + 1)));
	if (!new_str)
		return (NULL);
	while (s1[i])
		new_str[i] = s1[i++];
	i = 0;
	while (nbr[i])
		new_str[len_s[0] + i] = nbr[i++];
	free(nbr);
	return (new_str);
}

static int	ft_lenint(int n)
{
	int	i;

	i = 1;
	while ((n >= 10 || n <= -10) && i++)
		n /= 10;
	if (n < 0)
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t			size;
	unsigned long	i;
	char			*new_str;

	size = ft_strlen(s);
	i = 0;
	new_str = ft_calloc(1, size + 1);
	if (!new_str)
		return (NULL);
	while (i <= size)
	{
		new_str[i] = s[i];
		i++;
	}
	return (new_str);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*nbr;

	if (n == -2147483648)
		return (ft_strdup((char *)"-2147483648"));
	i = ft_lenint(n);
	nbr = ft_calloc(1, i + 1);
	if (!nbr)
		return (NULL);
	while (i-- > 0)
	{
		if (n < 0)
			nbr[0] = '-';
		if (n < 0)
			n *= -1;
		if (n >= 10)
			nbr[i] = (n % 10) + '0';
		else
			nbr[i] = n + '0';
		n /= 10;
	}
	return (nbr);
}
