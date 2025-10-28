/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 21:11:13 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/10/27 20:56:23 by rgomes-d         ###   ########.fr       */
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
	int				id_philo;
	pthread_mutex_t	fork_l;
	pthread_mutex_t	fork_r;

}					t_philo;

typedef struct s_sim
{
	int				times_eat;
	int				args[5];
	pthread_mutex_t	death;
	pthread_mutex_t	status;
}					t_sim;

int					parsing_args(int argc, char **argv, t_sim **sim);

#endif
