/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 21:11:13 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/11/04 17:18:45 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define TAKEN_FORK "\033[0;32m%lld %d has taken a fork. 🍴\n\033[0m"
# define EATING "\033[0;34m%lld %d is eating. 🍝\n\033[0m"
# define SLEEPING "\033[0;36m%lld %d is sleeping. 🛌\n\033[0m"
# define THINKING "\033[0;33m%lld %d is thinking. 🤔\n\033[0m"
# define DIED "\033[0;31m%lld %d died. 💀\n\033[0m"

typedef enum e_type
{
	M_FORK,
	M_EAT,
	M_SLEEP,
	M_THINK,
	M_DIED
}					t_type;

/* Struct philo*/
typedef struct s_philo
{
	pthread_t		philo_exec;
	int				id_philo;
	long long		last_time_eat;
	int				*stop;
	char			**msg;
	int				*args;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*status_sim;
	pthread_mutex_t	*status_w;
}					t_philo;

/*Struct of the simulation*/
typedef struct s_sim
{
	pthread_t		sim_exec;
	int				times_eat;
	int				args[5];
	char			*msg[5];
	int				stop;
	pthread_mutex_t	finish_sim;
	pthread_mutex_t	status_w;
}					t_sim;

/*Struct of the management of memory*/
typedef struct manmem_sim
{
	pthread_mutex_t	*forks;
	t_philo			**philo;
	t_sim			*sim;
}					t_memman;

int					parsing_args(int argc, char **argv, t_sim **sim);
int					ft_atoi(const char *nptr);
long long			ft_atoll(const char *nptr);
int					ft_isspace(char c);
long long			convert_u_ms(long long u);
long long			convert_ms_u(long long ms);

#endif
