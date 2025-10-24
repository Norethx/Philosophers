/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:06:53 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/03 14:27:39 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	rtn;

	rtn = ft_putstr_fd(s, fd);
	rtn += ft_putchar_fd('\n', fd);
	return (rtn);
}
