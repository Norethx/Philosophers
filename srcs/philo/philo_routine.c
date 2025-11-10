/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:44:37 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/11/10 18:27:40 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_routine(t_philo *philo_t)
{
	if (philo_t->fork_r == philo_t->fork_l)
	{
		print_function(M_FORK, &philo_t);
		usleep(convert_ms_u(philo_t->args[1]) + 1);
		return ;
	}
	pthread_mutex_lock(philo_t->fork_r);
	print_function(M_FORK, &philo_t);
	pthread_mutex_lock(philo_t->fork_l);
	pthread_mutex_lock(philo_t->status_sim);
	if (philo_t->stop[0] == 0)
	{
		pthread_mutex_unlock(philo_t->status_sim);
		print_function(M_FORK, &philo_t);
		print_function(M_EAT, &philo_t);
		usleep(convert_ms_u(philo_t->args[2]));
	}
	else
		pthread_mutex_unlock(philo_t->status_sim);
	pthread_mutex_unlock(philo_t->fork_r);
	pthread_mutex_unlock(philo_t->fork_l);
}

void	*philo_routine(void *philo)
{
	t_philo	**philo_t;

	philo_t = philo;
	pthread_mutex_lock(&philo_t[0]->last_time_m);
	philo_t[0]->last_time_eat = time_now_ms();
	pthread_mutex_unlock(&philo_t[0]->last_time_m);
	if (philo_t[0]->id_philo % 2 == 0)
		usleep(convert_ms_u(1));
	while (1)
	{
		pthread_mutex_lock(philo_t[0]->status_sim);
		if (philo_t[0]->stop[0] == 1)
			break ;
		pthread_mutex_unlock(philo_t[0]->status_sim);
		eat_routine(philo_t[0]);
		pthread_mutex_lock(philo_t[0]->status_sim);
		if (philo_t[0]->stop[0] == 1)
			break ;
		pthread_mutex_unlock(philo_t[0]->status_sim);
		post_eat_routine(philo_t[0]);
	}
	pthread_mutex_unlock(philo_t[0]->status_sim);
	return (NULL);
}

void	post_eat_routine(t_philo *philo_t)
{
	float	think;

	pthread_mutex_lock(philo_t->status_sim);
	if (philo_t->stop[0] == 0)
	{
		pthread_mutex_unlock(philo_t->status_sim);
		print_function(M_SLEEP, &philo_t);
		usleep(convert_ms_u(philo_t->args[3]));
	}
	else
		pthread_mutex_unlock(philo_t->status_sim);
	think = philo_t->args[1] - (time_now_ms() - philo_t->last_time_eat);
	think = (think - ((think / 100) * 33));
	pthread_mutex_lock(philo_t->status_sim);
	if (philo_t->stop[0] == 0)
	{
		pthread_mutex_unlock(philo_t->status_sim);
		print_function(M_THINK, &philo_t);
		if (think > 0)
			usleep(convert_ms_u(think));
		else
			usleep(convert_ms_u(1));
	}
	else
		pthread_mutex_unlock(philo_t->status_sim);
}
