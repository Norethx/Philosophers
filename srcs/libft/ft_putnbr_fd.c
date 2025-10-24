/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:11:19 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/03 14:28:09 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	*str;
	int		rtn;

	str = ft_itoa(n);
	if (!str)
		return (0);
	rtn = ft_putstr_fd(str, fd);
	free(str);
	return (rtn);
}
