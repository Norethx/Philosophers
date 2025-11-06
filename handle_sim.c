/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:45:46 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/11/06 14:47:12 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_sim(t_memman **mainmem)
{
	pthread_mutex_init(&mainmem[0]->sim->status_w, NULL);
	pthread_mutex_init(&mainmem[0]->sim->finish_sim, NULL);
	mainmem[0]->philo = ft_calloc(mainmem[0]->sim->args[0], sizeof(t_philo *));
	if (!mainmem[0]->philo)
		return (1);
	mainmem[0]->allocs |= C_PHILO;
	mainmem[0]->forks = ft_calloc(mainmem[0]->sim->args[0],
			sizeof(pthread_mutex_t));
	if (!mainmem[0]->forks)
		return (1);
	mainmem[0]->allocs |= C_FORKS;
	if (create_philos(mainmem))
		return (1);
	if (handle_sim(mainmem))
		return (1);
	clean_philos(mainmem, mainmem[0]->sim->args[0]);
	return (0);
}

int	handle_sim(t_memman **mem)
{
	int	i;
	int	status;

	i = 0;
	while (i < mem[0]->sim->args[0])
	{
		if (i == 0)
			mem[0]->sim->start = time_now_ms();
		mem[0]->philo[i]->start = mem[0]->sim->start;
		status = pthread_create(&mem[0]->philo[i]->philo_exec, NULL,
				philo_routine, (void *)&mem[0]->philo[i]);
		if (status != 0)
			return (1);
		i++;
	}
	status = pthread_create(&mem[0]->sim->sim_exec, NULL, run_sim, (void *)mem);
	if (status != 0)
		return (1);
	pthread_join(mem[0]->sim->sim_exec, NULL);
	while (--i >= 0)
		pthread_join(mem[0]->philo[i]->philo_exec, NULL);
	return (0);
}

void	*run_sim(void *mainmem)
{
	t_memman	**mem;

	mem = mainmem;
	usleep(convert_ms_u(5));
	pthread_mutex_lock(&mem[0]->philo[0]->last_time_m);
	mem[0]->less_time = mem[0]->sim->args[1] - (time_now_ms()
			- mem[0]->philo[0]->last_time_eat);
	pthread_mutex_unlock(&mem[0]->philo[0]->last_time_m);
	while (1)
	{
		pthread_mutex_lock(&mem[0]->sim->finish_sim);
		if (mem[0]->sim->stop == 1)
		{
			pthread_mutex_unlock(&mem[0]->sim->finish_sim);
			break ;
		}
		pthread_mutex_unlock(&mem[0]->sim->finish_sim);
		if (mem[0]->sim->times_eat == 1)
			mem[0]->minor_time_eat = mem[0]->sim->args[4];
		routine_sentinel(mem);
		if (verify_end_sim(mem) == 1)
			break ;
	}
	return (NULL);
}

int	verify_end_sim(t_memman **mem)
{
	if (mem[0]->less_time <= 0)
	{
		print_function(M_DIED, &mem[0]->philo[mem[0]->i_philo]);
		return (1);
	}
	else if (mem[0]->sim->times_eat == 1
		&& mem[0]->minor_time_eat == mem[0]->sim->args[4])
	{
		pthread_mutex_lock(&mem[0]->sim->finish_sim);
		mem[0]->sim->stop = 1;
		pthread_mutex_unlock(&mem[0]->sim->finish_sim);
		return (1);
	}
	else
		usleep(convert_ms_u(mem[0]->less_time));
	return (0);
}

int	create_philos(t_memman **mem)
{
	int	i;

	i = 0;
	while (i < mem[0]->sim->args[0])
	{
		mem[0]->philo[i] = ft_calloc(1, sizeof(t_philo));
		if (!mem[0]->philo[i])
			return (clean_philos(mem, i));
		pthread_mutex_init(&mem[0]->forks[i], NULL);
		pthread_mutex_init(&mem[0]->philo[0]->last_time_m, NULL);
		mem[0]->philo[i]->msg = mem[0]->sim->msg;
		mem[0]->philo[i]->stop = &mem[0]->sim->stop;
		mem[0]->philo[i]->fork_r = &mem[0]->forks[i];
		mem[0]->philo[i]->args = mem[0]->sim->args;
		mem[0]->philo[i]->status_sim = &mem[0]->sim->finish_sim;
		mem[0]->philo[i]->status_w = &mem[0]->sim->status_w;
		if (i != 0)
			mem[0]->philo[i]->fork_l = &mem[0]->forks[i - 1];
		mem[0]->philo[i]->id_philo = i + 1;
		i++;
	}
	mem[0]->philo[0]->fork_l = mem[0]->philo[0]->fork_r;
	mem[0]->philo[0]->fork_r = &mem[0]->forks[mem[0]->sim->args[0] - 1];
	return (0);
}
