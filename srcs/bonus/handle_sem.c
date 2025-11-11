/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:33:40 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/11/11 19:12:55 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	create_sem(sem_t **sem, int n_arg, const char *categ)
{
	sem[0] = sem_open(categ, O_CREAT, 0644, n_arg);
	if (!sem[0])
		return (1);
	return (0);
}

int	handle_sem(t_sim **sim, int verify)
{
	verify = create_sem(&sim[0]->forks, sim[0]->args[0], "fork");
	if (verify == 1)
		return (1);
	sim[0]->control_mem |= C_FORKS;
	verify = create_sem(&sim[0]->prot_fork, 1, "p_fork");
	if (verify == 1)
		return (1);
	sim[0]->control_mem |= C_PFORKS;
	verify = create_sem(&sim[0]->finish_sem, 1, "end");
	if (verify == 1)
		return (1);
	sim[0]->control_mem |= C_END;
	verify = create_sem(&sim[0]->prot_finish, 1, "p_end");
	if (verify == 1)
		return (1);
	sim[0]->control_mem |= C_PEND;
	verify = create_sem(&sim[0]->end_eat, sim[0]->args[0], "eat");
	if (verify == 1)
		return (1);
	sim[0]->control_mem |= C_EAT;
	verify = create_sem(&sim[0]->prot_end_eat, 1, "p_eat");
	if (verify == 1)
		return (1);
	sim[0]->control_mem |= C_PEAT;
	return (0);
}

int	handle_close_sem(t_sim **sim)
{
	if (sim[0]->control_mem & C_FORKS)
		sem_close(sim[0]->forks);
	if (sim[0]->control_mem & C_PFORKS)
		sem_close(sim[0]->prot_fork);
	if (sim[0]->control_mem & C_EAT)
		sem_close(sim[0]->end_eat);
	if (sim[0]->control_mem & C_PEAT)
		sem_close(sim[0]->prot_end_eat);
	if (sim[0]->control_mem & C_END)
		sem_close(sim[0]->finish_sem);
	if (sim[0]->control_mem & C_PEND)
		sem_close(sim[0]->prot_finish);
	return (0);
}

int	handle_unlink_sem(t_sim **sim)
{
	if (sim[0]->control_mem & C_FORKS)
		sem_unlink("fork");
	if (sim[0]->control_mem & C_PFORKS)
		sem_unlink("p_fork");
	if (sim[0]->control_mem & C_EAT)
		sem_unlink("end");
	if (sim[0]->control_mem & C_PEAT)
		sem_unlink("p_end");
	if (sim[0]->control_mem & C_END)
		sem_unlink("eat");
	if (sim[0]->control_mem & C_PEND)
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
