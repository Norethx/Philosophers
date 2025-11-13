/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 21:12:55 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/11/13 11:22:49 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_sim(t_sim **sim)
{
	sim[0]->philos_id = ft_calloc(sim[0]->args[0], sizeof(pid_t *));
	if (!sim[0]->philos_id)
		return (1);
	sim[0]->control_mem |= C_PID;
	handle_unlink_sem();
	if (handle_sem(sim, 0) == 1)
	{
		handle_close_sem(sim);
		return (1);
	}
	init_philos(sim);
	control_clean_child(sim);
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
	sim_philo->control_mem |= C_SIM;
	if (parsing_args(argc, argv, &sim_philo))
		return (1);
	init_sim(&sim_philo);
	free(sim_philo);
}
