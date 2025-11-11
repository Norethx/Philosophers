/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:48:05 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/11/11 19:24:34 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_philos(t_sim **sim)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = NULL;
	while (++i <= sim[0]->args[0])
	{
		build_philo(sim, &philo, i);
		philo->philo_exec = fork();
		if (!philo->philo_exec)
		{
			sim[0]->is_child = 1;
			init_routine(philo);
			control_clean_child(sim);
		}
		else
			sim[0]->philos_id[i - 1] = philo->philo_exec;
	}
	pthread_create(&sim[0]->judge, NULL, judge_routine, (void *)sim[0]);
	pthread_join(sim[0]->judge, NULL);
	while (--i >= 0)
		waitpid(sim[0]->philos_id[i], 0, 0);
	free(philo);
	return (1);
}

void *judge_routine(void *content)
{
	t_sim *sim;

	sim = content;
	printf("judge aqui");
	return (NULL);
}

int	build_philo(t_sim **sim, t_philo **philo, int id)
{
	if (!philo[0])
	{
		philo[0] = ft_calloc(1, sizeof(t_philo));
		if (!philo[0])
			return (1);
		philo[0]->forks = sim[0]->forks;
		philo[0]->prot_fork = sim[0]->prot_fork;
		philo[0]->finish_sem = sim[0]->finish_sem;
		philo[0]->prot_finish = sim[0]->prot_finish;
		philo[0]->end_eat = sim[0]->end_eat;
		philo[0]->prot_end_eat = sim[0]->prot_end_eat;
		philo[0]->id_philo = id;
		philo[0]->msg = sim[0]->msg;
		philo[0]->args = sim[0]->args;
		philo[0]->start = time_now_ms();
	}
	else
		philo[0]->id_philo = id;
	return (0);
}
