/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:16:21 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/11/12 15:56:16 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*waiter_routine(void *content)
{
	t_philo	**philo;
	int		aux;

	philo = content;
	while (1)
	{
		sem_wait(philo[0]->prot_fork);
		aux = philo[0]->args[1] - (time_now_ms() - philo[0]->last_time_eat);
		if (philo[0]->on_times_eat == 1
			&& philo[0]->times_eat == philo[0]->args[4])
		{
			sem_wait(philo[0]->end_eat);
			philo[0]->on_times_eat = 0;
		}
		sem_post(philo[0]->prot_fork);
		if (aux <= 0)
			print_function(M_DIED, philo);
		sem_wait(philo[0]->prot_finish);
		if (aux <= 0 || philo[0]->finish_sem->__align == 0)
			break ;
		sem_post(philo[0]->prot_finish);
		usleep(convert_ms_u(1));
	}
	sem_post(philo[0]->prot_finish);
	return (NULL);
}

void	eat_routine(t_philo *philo_t)
{
	if (philo_t->args[0] == 1)
	{
		print_function(M_FORK, &philo_t);
		usleep(convert_ms_u(philo_t->args[1]) + 1);
		return ;
	}
	sem_wait(philo_t->forks);
	print_function(M_FORK, &philo_t);
	sem_wait(philo_t->forks);
	sem_wait(philo_t->prot_finish);
	if (philo_t->finish_sem->__align != 0)
	{
		sem_post(philo_t->prot_finish);
		print_function(M_FORK, &philo_t);
		print_function(M_EAT, &philo_t);
		usleep(convert_ms_u(philo_t->args[2]));
	}
	else
		sem_post(philo_t->prot_finish);
	sem_post(philo_t->forks);
	sem_post(philo_t->forks);
}

void	*philo_routine(t_philo *philo_t)
{
	if (philo_t->id_philo % 2 == 0 && philo_t->args[0] % 2 == 0)
		usleep(convert_ms_u(philo_t->args[2] - 1));
	else if (philo_t->id_philo % 2 == 1 && philo_t->args[0] % 2 == 1)
		usleep(convert_ms_u(philo_t->args[2] - 1));
	while (1)
	{
		sem_wait(philo_t->prot_finish);
		if (philo_t->finish_sem->__align == 0)
			break ;
		sem_post(philo_t->prot_finish);
		eat_routine(philo_t);
		sem_wait(philo_t->prot_finish);
		if (philo_t->finish_sem->__align == 0)
			break ;
		sem_post(philo_t->prot_finish);
		post_eat_routine(philo_t);
	}
	sem_post(philo_t->prot_finish);
	return (NULL);
}

void	post_eat_routine(t_philo *philo_t)
{
	float	think;

	sem_wait(philo_t->prot_finish);
	if (philo_t->finish_sem->__align != 0)
	{
		sem_post(philo_t->prot_finish);
		print_function(M_SLEEP, &philo_t);
		usleep(convert_ms_u(philo_t->args[3]));
	}
	else
		sem_post(philo_t->prot_finish);
	think = philo_t->args[1] - (time_now_ms() - philo_t->last_time_eat);
	think = (think - ((think / 100) * 33));
	sem_wait(philo_t->prot_finish);
	if (philo_t->finish_sem->__align != 0)
	{
		sem_post(philo_t->prot_finish);
		print_function(M_THINK, &philo_t);
		if (think > 0)
			usleep(convert_ms_u(think));
		else
			usleep(convert_ms_u(1));
	}
	else
		sem_post(philo_t->prot_finish);
}

int	print_function(int type, t_philo **philo)
{
	sem_wait(philo[0]->prot_fork);
	if (type != M_DIED && philo[0]->args[1] - (time_now_ms()
			- philo[0]->last_time_eat) <= 0)
	{
		sem_post(philo[0]->prot_fork);
		return (1);
	}
	if (type == M_EAT)
	{
		philo[0]->last_time_eat = time_now_ms();
		philo[0]->times_eat++;
	}
	sem_wait(philo[0]->prot_finish);
	if ((type == M_DIED && philo[0]->finish_sem->__align)
		|| (philo[0]->finish_sem->__align == 1 && philo[0]->last_time_eat))
		printf(philo[0]->msg[type], time_now_ms() - philo[0]->start,
			philo[0]->id_philo);
	if (type == M_DIED && philo[0]->finish_sem->__align)
		sem_wait(philo[0]->finish_sem);
	sem_post(philo[0]->prot_finish);
	sem_post(philo[0]->prot_fork);
	return (0);
}
