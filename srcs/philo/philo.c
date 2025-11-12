/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 21:12:55 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/11/12 19:33:49 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine_sentinel(t_memman **mem)
{
	int	aux;
	int	i;

	i = 0;
	while (i < mem[0]->sim->args[0])
	{
		pthread_mutex_lock(&mem[0]->philo[i]->last_time_m);
		aux = mem[0]->sim->args[1] - (time_now_ms()
				- mem[0]->philo[i]->last_time_eat);
		if (mem[0]->sim->times_eat == 1
			&& mem[0]->minor_time_eat > mem[0]->philo[i]->times_eat)
			mem[0]->minor_time_eat = -1;
		pthread_mutex_unlock(&mem[0]->philo[i]->last_time_m);
		if (mem[0]->less_time > aux)
			mem[0]->less_time = aux;
		if (mem[0]->less_time > aux)
			mem[0]->i_philo = i;
		if (mem[0]->less_time <= 0)
		{
			pthread_mutex_lock(&mem[0]->sim->finish_sim);
			mem[0]->sim->stop = 1;
			pthread_mutex_unlock(&mem[0]->sim->finish_sim);
		}
		i++;
	}
}

int	print_function(int type, t_philo **philo)
{
	pthread_mutex_lock(&philo[0]->last_time_m);
	if (type != M_DIED && philo[0]->args[1] - (time_now_ms()
			- philo[0]->last_time_eat) <= 0)
	{
		pthread_mutex_unlock(&philo[0]->last_time_m);
		return (1);
	}
	if (type == M_EAT)
	{
		philo[0]->last_time_eat = time_now_ms();
		philo[0]->times_eat++;
	}
	pthread_mutex_lock(philo[0]->status_sim);
	if (type == M_DIED || (philo[0]->stop[0] == 0 && philo[0]->last_time_eat))
	{
		pthread_mutex_lock(philo[0]->status_w);
		printf(philo[0]->msg[type], time_now_ms() - philo[0]->start,
			philo[0]->id_philo);
		pthread_mutex_unlock(philo[0]->status_w);
	}
	pthread_mutex_unlock(philo[0]->status_sim);
	pthread_mutex_unlock(&philo[0]->last_time_m);
	return (0);
}

int	main(int argc, char **argv)
{
	t_memman	*main_mem;

	if (argc < 5 || argc > 6)
		return (1);
	main_mem = ft_calloc(1, sizeof(t_memman));
	if (!main_mem)
		return (1);
	main_mem->allocs |= C_MEM;
	main_mem->sim = ft_calloc(1, sizeof(t_sim));
	if (!main_mem->sim)
		return (1);
	main_mem->allocs |= C_SIM;
	if (parsing_args(argc, argv, &main_mem->sim))
		return (1);
	init_sim(&main_mem);
	free_mem(&main_mem);
}
