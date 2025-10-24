/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:39:13 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/07/31 20:11:06 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenint_base(unsigned long long n, unsigned int len)
{
	unsigned int	qt_char;

	qt_char = 0;
	while (n >= len)
	{
		qt_char++;
		n /= len;
	}
	qt_char += 1;
	return (qt_char);
}

static int	ft_verify_base(char *base)
{
	int	i;
	int	scn_i;

	i = 0;
	while (base[i] != '\0')
	{
		scn_i = 0;
		while (base[scn_i] != '\0')
		{
			if ((base[i] == base[scn_i] && i != scn_i) || (base[scn_i] == '+'
					|| base[scn_i] == '-') || (base[scn_i] <= 32
					|| base[scn_i] > 126))
				return (0);
			scn_i++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	else
		return (1);
}

char	*ft_ulltoa_base(unsigned long long n, char *base)
{
	unsigned int	i;
	char			*nbr;
	unsigned int	len_b;

	if (!base || !ft_verify_base(base))
		return (NULL);
	len_b = ft_strlen(base);
	i = ft_lenint_base(n, len_b);
	nbr = (char *)calloc(1, i + 1);
	nbr[i] = 0;
	while (n > 0)
	{
		i--;
		if (n >= len_b)
			nbr[i] = base[(n % len_b)];
		else
			nbr[i] = base[n];
		n /= len_b;
	}
	return (nbr);
}
