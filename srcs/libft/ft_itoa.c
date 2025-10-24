/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:39:13 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/29 18:44:06 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenint(int n)
{
	int		qt_char;

	qt_char = 0;
	while (n >= 10 || n <= -10)
	{
		qt_char++;
		n /= 10;
	}
	if (n < 0)
		qt_char += 2;
	else
		qt_char += 1;
	return (qt_char);
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
	nbr[i] = 0;
	while (i-- > 0 && nbr[i] != '-')
	{
		if (n < 0)
		{
			n *= -1;
			nbr[0] = '-';
		}
		if (n >= 10)
			nbr[i] = (n % 10) + '0';
		else
			nbr[i] = n + '0';
		n /= 10;
	}
	return (nbr);
}
