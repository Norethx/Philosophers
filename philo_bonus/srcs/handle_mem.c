/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:54:28 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/11/12 15:54:41 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	handle_unlink_sem(void)
{
	sem_unlink("fork");
	sem_unlink("p_fork");
	sem_unlink("end");
	sem_unlink("p_end");
	sem_unlink("eat");
	sem_unlink("p_eat");
	return (0);
}

int	control_clean_child(t_sim **sim)
{
	free(sim[0]->philos_id);
	handle_close_sem(sim);
	free(sim[0]);
	exit(EXIT_SUCCESS);
}
