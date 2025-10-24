/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:39:13 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/07/31 20:10:53 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenint_base(unsigned int n, unsigned int len)
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

char	*ft_uitoa_base(unsigned int n, char *base)
{
	unsigned int	i;
	char			*nbr;
	unsigned int	len_b;

	if (!base || !ft_verify_base(base))
		return (NULL);
	len_b = ft_strlen(base);
	i = ft_lenint_base(n, len_b);
	nbr = (char *)ft_calloc(1, i + 1);
	nbr[i] = 0;
	while (i-- > 0)
	{
		if (n >= len_b)
			nbr[i] = base[(n % len_b)];
		else
			nbr[i] = base[n];
		n /= len_b;
	}
	return (nbr);
}
