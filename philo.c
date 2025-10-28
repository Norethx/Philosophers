/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 21:12:55 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/10/27 19:57:11 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "string.h"

void init_sim(void)
{
	ft_printf("vamo caralho!");
}

int	main(int argc, char **argv)
{
	t_sim	*sim;

	ft_gc_init();
	sim = ft_gc_calloc_root(1, sizeof(t_sim),GC_DATA, "sim");
	if (argc < 5 || argc > 6)
		return (1);
	if (parsing_args(argc, argv, &sim))
	{
		ft_gc_end();
		return (1);
	}
	init_sim();
	ft_gc_end();
}
