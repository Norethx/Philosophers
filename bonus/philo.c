/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 21:12:55 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/11/10 17:03:04 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// void	routine_sentinel(t_memman **mem)
// {
// 	int	aux;
// 	int	i;

// 	i = 0;
// 	while (i < mem[0]->sim->args[0])
// 	{
// 		pthread_mutex_lock(&mem[0]->philo[i]->last_time_m);
// 		aux = mem[0]->sim->args[1] - (time_now_ms()
// 				- mem[0]->philo[i]->last_time_eat);
// 		if (mem[0]->sim->times_eat == 1
// 			&& mem[0]->minor_time_eat > mem[0]->philo[i]->times_eat)
// 			mem[0]->minor_time_eat = -1;
// 		pthread_mutex_unlock(&mem[0]->philo[i]->last_time_m);
// 		if (mem[0]->less_time > aux)
// 			mem[0]->less_time = aux;
// 		if (mem[0]->less_time > aux)
// 			mem[0]->i_philo = i;
// 		if (mem[0]->less_time <= 0)
// 		{
// 			pthread_mutex_lock(&mem[0]->sim->finish_sim);
// 			mem[0]->sim->stop = 1;
// 			pthread_mutex_unlock(&mem[0]->sim->finish_sim);
// 		}
// 		i++;
// 	}
// }

// int	print_function(int type, t_philo **philo)
// {
// 	pthread_mutex_lock(&philo[0]->last_time_m);
// 	if (type != M_DIED && philo[0]->args[1] - (time_now_ms()
// 			- philo[0]->last_time_eat) <= 0)
// 	{
// 		pthread_mutex_unlock(&philo[0]->last_time_m);
// 		return (1);
// 	}
// 	if (type == M_EAT)
// 	{
// 		philo[0]->last_time_eat = time_now_ms();
// 		philo[0]->times_eat++;
// 	}
// 	pthread_mutex_lock(philo[0]->status_sim);
// 	if (type == M_DIED || (philo[0]->stop[0] == 0 && philo[0]->last_time_eat))
// 	{
// 		pthread_mutex_lock(philo[0]->status_w);
// 		printf(philo[0]->msg[type], time_now_ms() - philo[0]->start,
// 			philo[0]->id_philo);
// 		pthread_mutex_unlock(philo[0]->status_w);
// 	}
// 	pthread_mutex_unlock(philo[0]->status_sim);
// 	pthread_mutex_unlock(&philo[0]->last_time_m);
// 	return (0);
// }

// int create_sems(t_sim **sim)
// {
// 	int i;

// 	i = 0;
// 	while (i < sim[0]->args[0])
// 		sim[0]->end_eat_child[i] = sem_open()
// 	sem_open()
// }

int	init_sim(t_sim **sim)
{
	// t_philo *philo;

	sim[0]->philos_id = ft_calloc(sim[0]->args[0], sizeof(pid_t *));
	if (!sim[0]->philos_id)
		return (1);
	// create_sems(sim);
	return (0);
}
int	main(int argc, char **argv)
{
	t_sim	*sim_philo;

	if (argc < 5 || argc > 6)
		return (1);
	sim_philo = ft_calloc(1, sizeof(t_sim));
	if (!sim_philo)
		return (1);
	if (!parsing_args(argc, argv, &sim_philo))
		init_sim(&sim_philo);
	// free_mem(&sim_philo);
	free(sim_philo);
}
