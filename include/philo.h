/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 21:11:13 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/10/28 20:42:48 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft.h"
# include <pthread.h>
# include <sys/time.h>

/* Struct philo*/
typedef struct s_philo
{
	pthread_t		philo_exec;
	int				id_philo;
	int				last_time_eat;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*status_sim;

}					t_philo;

/*Struct of the simulation*/
typedef struct s_sim
{
	int				times_eat;
	int				args[5];
	int				stop;
	pthread_mutex_t	finish_sim;
	pthread_mutex_t	status;
	struct timeval	tv;
}					t_sim;

int					parsing_args(int argc, char **argv, t_sim **sim);

#endif
