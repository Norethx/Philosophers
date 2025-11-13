/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 21:11:13 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/11/12 19:20:51 by rgomes-d         ###   ########.fr       */
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

# define TAKEN_FORK "%lld %d has taken a fork.\n"
# define EATING "%lld %d is eating.\n"
# define SLEEPING "%lld %d is sleeping.\n"
# define THINKING "%lld %d is thinking.\n"
# define DIED "%lld %d died.\n"

typedef enum e_type
{
	M_FORK,
	M_EAT,
	M_SLEEP,
	M_THINK,
	M_DIED
}					t_type;

typedef enum e_clear
{
	C_MEM = 1 << 0,
	C_FORKS = 1 << 1,
	C_PHILO = 1 << 2,
	C_SIM = 1 << 3,
}					t_clear;

/* Struct philo*/
typedef struct s_philo
{
	pthread_t		philo_exec;
	int				id_philo;
	int				times_eat;
	long long		last_time_eat;
	int				*stop;
	char			**msg;
	int				*args;
	long long		start;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	last_time_m;
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
	long long		start;
	pthread_mutex_t	finish_sim;
	pthread_mutex_t	status_w;
}					t_sim;

/*Struct of the management of memory*/
typedef struct manmem_sim
{
	pthread_mutex_t	*forks;
	t_philo			**philo;
	t_sim			*sim;
	unsigned char	allocs;
	int				less_time;
	int				i_philo;
	int				minor_time_eat;
}					t_memman;

void				control_destroy_mutex(t_memman **mem);
int					parsing_args(int argc, char **argv, t_sim **sim);
int					ft_atoi(const char *nptr);
long long			ft_atoll(const char *nptr);
int					ft_isspace(char c);
long long			convert_u_ms(long long u);
long long			convert_ms_u(long long ms);
int					create_philos(t_memman **mem);
void				*philo_routine(void *philo);
void				post_eat_routine(t_philo *philo_t);
int					handle_sim(t_memman **mem);
void				*run_sim(void *mainmem);
long long			time_now_ms(void);
int					print_function(int type, t_philo **philo);
int					clean_philos(t_memman **mem, int size);
void				routine_sentinel(t_memman **mem);
int					verify_end_sim(t_memman **mem);
void				*ft_calloc(size_t nmemb, size_t size);
int					init_sim(t_memman **mainmem);
int					free_mem(t_memman **main_mem);

#endif
