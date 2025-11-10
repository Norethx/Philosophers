/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_allocs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:28:38 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/11/10 11:46:13 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	clean_philos(t_memman **mem, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(mem[0]->philo[i++]);
	return (1);
}

/*
RECEBER FLAGS PARA LIMPAR CORETAMENTE OS MALLOCS
*/
int	free_mem(t_memman **main_mem)
{
	if (main_mem[0]->allocs & C_FORKS)
	{
		free(main_mem[0]->forks);
		main_mem[0]->allocs &= ~C_FORKS;
	}
	if (main_mem[0]->allocs & C_SIM)
	{
		free(main_mem[0]->sim);
		main_mem[0]->allocs &= ~C_SIM;
	}
	if (main_mem[0]->allocs & C_PHILO)
	{
		free(main_mem[0]->philo);
		main_mem[0]->allocs &= ~C_PHILO;
	}
	free(main_mem[0]);
	return (0);
}
