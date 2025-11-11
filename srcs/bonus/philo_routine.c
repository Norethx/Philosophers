/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:16:21 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/11/11 19:23:53 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int init_routine(t_philo *philo)
{
	pthread_create(&philo->waiter, NULL, waiter_routine, (void *)philo);
	pthread_join(philo->waiter, NULL);
	free(philo);
	return (0);
}

void *waiter_routine(void *content)
{
	t_philo *philo;

	philo = content;
	printf("waiter aqui\n");
	return(NULL);
}
