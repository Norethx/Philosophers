/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 21:11:13 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/11/11 19:23:45 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
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
	C_SIM = 1 << 0,
	C_PID = 1 << 1,
	C_FORKS = 1 << 2,
	C_PFORKS = 1 << 3,
	C_END = 1 << 4,
	C_PEND = 1 << 5,
	C_EAT = 1 << 6,
	C_PEAT = 1 << 7,
}					t_clear;

/* Struct philo iudqhuigryuqryuweqg*/
typedef struct s_philo
{
	sem_t			*forks;
	sem_t			*prot_fork;
	sem_t			*finish_sem;
	sem_t			*prot_finish;
	sem_t			*end_eat;
	sem_t			*prot_end_eat;
	pid_t			philo_exec;
	int				id_philo;
	int				times_eat;
	long long		last_time_eat;
	int				*stop;
	char			**msg;
	int				*args;
	long long		start;
	pthread_t		waiter;
}					t_philo;

/*Struct of the simulation*/
typedef struct s_sim
{
	pthread_t		judge;
	int				times_eat;
	int				args[5];
	char			*msg[5];
	long long		start;
	unsigned char	control_mem;
	sem_t			*forks;
	sem_t			*prot_fork;
	sem_t			*finish_sem;
	sem_t			*prot_finish;
	sem_t			*end_eat;
	sem_t			*prot_end_eat;
	pid_t			*philos_id;
	int				is_child;
}					t_sim;

/*Struct of the management of memory*/
// typedef struct manmem_sim
// {
// 	t_sim			*sim;
// 	unsigned char	allocs;
// }					t_memman;

void				*waiter_routine(void *content);
int					init_routine(t_philo *philo);
void				*judge_routine(void *content);
int					handle_unlink_sem(t_sim **sim);
int					handle_close_sem(t_sim **sim);
int					control_clean_child(t_sim **sim);
int					build_philo(t_sim **sim, t_philo **philo, int id);
int					init_philos(t_sim **sim);
int					create_sem(sem_t **sem, int n_arg, const char *categ);
int					handle_sem(t_sim **sim, int verify);
int					handle_unlink_sem(t_sim **sim);
size_t				ft_strlen(const char *str);
char				*ft_itoa(int n);
char				*ft_strdup(const char *s);
char				*ft_strjnbr(char const *s1, int s2);
int					parsing_args(int argc, char **argv, t_sim **sim);
int					ft_atoi(const char *nptr);
long long			ft_atoll(const char *nptr);
int					ft_isspace(char c);
long long			convert_u_ms(long long u);
long long			convert_ms_u(long long ms);
void				*philo_routine(void *philo);
void				post_eat_routine(t_philo *philo_t);
void				*run_sim(void *mainmem);
long long			time_now_ms(void);
int					print_function(int type, t_philo **philo);
void				*ft_calloc(size_t nmemb, size_t size);

#endif
