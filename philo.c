/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 21:12:55 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/11/04 21:21:11 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int					create_philos(t_memman **mem);
void				*philo_routine(void *philo);
void				post_eat_routine(t_philo *philo_t);
int					handle_sim(t_memman **mem);
void				*run_sim(void *mainmem);
long long			time_now_ms(void);
int					print_function(int type, t_philo **philo);

inline long long	convert_u_ms(long long u)
{
	return (u / 1000);
}

inline long long	convert_ms_u(long long ms)
{
	return (1000L * ms);
}

// int	set_logs(t_sim **sim)
// {
// 	void	**msg;

// 	msg = ft_calloc(5, 8);
// }

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*n_arr;
	unsigned int	i_nmemb;
	unsigned int	i_size;

	i_nmemb = nmemb;
	i_size = size;
	if (nmemb == 0 || size == 0)
	{
		n_arr = malloc(1);
		if (!n_arr)
			return (NULL);
		memset(n_arr, 0, 1);
		return (n_arr);
	}
	if (((i_nmemb * i_size) / i_size) != nmemb)
		return ((void *)0);
	n_arr = malloc(size * nmemb);
	if (!n_arr)
		return (NULL);
	memset(n_arr, 0, (nmemb * size));
	return (n_arr);
}

int	init_sim(t_memman **mainmem)
{
	pthread_mutex_init(&mainmem[0]->sim->status_w, NULL);
	pthread_mutex_init(&mainmem[0]->sim->finish_sim, NULL);
	mainmem[0]->philo = ft_calloc(mainmem[0]->sim->args[0], sizeof(t_philo *));
	if (!mainmem[0]->philo)
		return (1);
	mainmem[0]->forks = ft_calloc(mainmem[0]->sim->args[0],
			sizeof(pthread_mutex_t));
	if (!mainmem[0]->forks)
		return (2);
	create_philos(mainmem);
	if (!mainmem[0]->philo)
		return (1);
	handle_sim(mainmem);
	return (0);
}

int	handle_sim(t_memman **mem)
{
	int	i;

	i = 0;
	while (i < mem[0]->sim->args[0])
	{
		pthread_create(&mem[0]->philo[i]->philo_exec, NULL, philo_routine,
			(void *)&mem[0]->philo[i]);
		i++;
	}
	pthread_create(&mem[0]->sim->sim_exec, NULL, run_sim, (void *)mem);
	pthread_join(mem[0]->sim->sim_exec, NULL);
	while (--i >= 0)
		pthread_join(mem[0]->philo[i]->philo_exec, NULL);
	return (0);
}

void	*run_sim(void *mainmem)
{
	t_memman	**mem;
	int			i;
	int			less_time;
	int			aux;
	int			i_philo;

	mem = mainmem;
	less_time = 0;
	usleep(convert_ms_u(5));
	while (1)
	{
		pthread_mutex_lock(&mem[0]->sim->finish_sim);
		if (mem[0]->sim->stop == 1)
		{
			pthread_mutex_unlock(&mem[0]->sim->finish_sim);
			break ;
		}
		pthread_mutex_unlock(&mem[0]->sim->finish_sim);
		i = 0;
		while (i < mem[0]->sim->args[0])
		{
			/*
				TEM QUE PROTEGER ESSA VARIAVEL COM MUTEX E DENTRO DO PRINTF TBM
			*/
			aux = mem[0]->sim->args[1] - (time_now_ms()
					- mem[0]->philo[i]->last_time_eat);
			if (less_time > aux)
			{
				less_time = aux;
				i_philo = i;
			}
			// if (aux < 0)
			// {
			// 	i = 0;
			// 	while (i < mem[0]->sim->args[0])
			// 		pthread_mutex_unlock(&mem[0]->forks[i++]);
			// 	break ;
			// }
			i++;
		}
		if (less_time < 0)
		{
			pthread_mutex_lock(&mem[0]->sim->finish_sim);
			mem[0]->sim->stop = 1;
			pthread_mutex_unlock(&mem[0]->sim->finish_sim);
			print_function(M_DIED, &mem[0]->philo[i_philo]);
			break ;
		}
		else
			usleep(convert_ms_u(less_time));
	}
	return (NULL);
}

long long	time_now_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (long long)1000) + (tv.tv_usec / 1000));
}

int	print_function(int type, t_philo **philo)
{
	int	size;

	size = 0;
	if (type != M_DIED && philo[0]->args[1] - (time_now_ms()
			- philo[0]->last_time_eat) < 0)
		return (1);
	if (type == M_EAT)
		philo[0]->last_time_eat = time_now_ms();
	pthread_mutex_lock(philo[0]->status_sim);
	if (type == M_DIED || (philo[0]->stop[0] == 0 && philo[0]->last_time_eat))
	{
		pthread_mutex_unlock(philo[0]->status_sim);
		pthread_mutex_lock(philo[0]->status_w);
		size = printf(philo[0]->msg[type], time_now_ms(), philo[0]->id_philo);
		pthread_mutex_unlock(philo[0]->status_w);
	}
	else
		pthread_mutex_unlock(philo[0]->status_sim);
	return (size);
}

void	eat_routine(t_philo *philo_t)
{
	// pthread_mutex_lock(philo_t->status_w);
	// printf("%d %d\n", think, philo_t->id_philo);
	// pthread_mutex_unlock(philo_t->status_w);
	pthread_mutex_lock(philo_t->fork_r);
	print_function(M_FORK, &philo_t);
	pthread_mutex_lock(philo_t->fork_l);
	print_function(M_FORK, &philo_t);
	print_function(M_EAT, &philo_t);
	usleep(convert_ms_u(philo_t->args[2]));
	pthread_mutex_unlock(philo_t->fork_r);
	pthread_mutex_unlock(philo_t->fork_l);
}

void	*philo_routine(void *philo)
{
	t_philo	**philo_t;

	philo_t = philo;
	philo_t[0]->last_time_eat = time_now_ms();
	if (philo_t[0]->id_philo % 2 == 0)
		usleep(convert_ms_u(10));
	while (1)
	{
		pthread_mutex_lock(philo_t[0]->status_sim);
		if (philo_t[0]->stop[0] == 1)
		{
			pthread_mutex_unlock(philo_t[0]->status_sim);
			break ;
		}
		pthread_mutex_unlock(philo_t[0]->status_sim);
		eat_routine(philo_t[0]);
		post_eat_routine(philo_t[0]);
	}
	return (NULL);
}

// void	eat_routine(t_philo *philo_t)
// {
// 	pthread_mutex_lock(philo_t->fork_r);
// 	print_function(M_FORK, &philo_t);
// 	pthread_mutex_lock(philo_t->fork_l);
// 	print_function(M_FORK, &philo_t);
// 	print_function(M_EAT, &philo_t);
// 	usleep(convert_u_ms(philo_t->args[2]));
// 	pthread_mutex_unlock(philo_t->fork_r);
// 	pthread_mutex_unlock(philo_t->fork_l);
// }

void	post_eat_routine(t_philo *philo_t)
{
	int	think;

	print_function(M_SLEEP, &philo_t);
	usleep(convert_ms_u(philo_t->args[3]));
	think = philo_t->args[1] - (time_now_ms() - philo_t->last_time_eat) - 1;
	think = think - ((think / 100) * 10);
	// pthread_mutex_lock(philo_t->status_w);
	// printf("%d %d\n", think, philo_t->id_philo);
	// pthread_mutex_unlock(philo_t->status_w);
	print_function(M_THINK, &philo_t);
	if (think > 0)
		usleep(convert_ms_u(think));
	else
		usleep(convert_ms_u(1));
}

int	create_philos(t_memman **mem)
{
	int	i;

	i = 0;
	while (i < mem[0]->sim->args[0])
	{
		mem[0]->philo[i] = ft_calloc(1, sizeof(t_philo));
		pthread_mutex_init(&mem[0]->forks[i], NULL);
		mem[0]->philo[i]->msg = mem[0]->sim->msg;
		mem[0]->philo[i]->stop = &mem[0]->sim->stop;
		mem[0]->philo[i]->fork_r = &mem[0]->forks[i];
		mem[0]->philo[i]->args = mem[0]->sim->args;
		mem[0]->philo[i]->status_sim = &mem[0]->sim->finish_sim;
		mem[0]->philo[i]->status_w = &mem[0]->sim->status_w;
		if (i != 0)
			mem[0]->philo[i]->fork_l = &mem[0]->forks[i - 1];
		mem[0]->philo[i]->id_philo = i + 1;
		i++;
	}
	mem[0]->philo[0]->fork_l = mem[0]->philo[0]->fork_r;
	mem[0]->philo[0]->fork_r = &mem[0]->forks[mem[0]->sim->args[0] - 1];
	return (0);
}

int	free_mem(t_memman **main_mem)
{
	int	i;

	i = 0;
	while (i < main_mem[0]->sim->args[0])
		free(main_mem[0]->philo[i++]);
	free(main_mem[0]->forks);
	free(main_mem[0]->sim);
	free(main_mem[0]->philo);
	free(main_mem[0]);
	return (0);
}

int	main(int argc, char **argv)
{
	t_memman	*main_mem;

	if (argc < 5 || argc > 6)
		return (1);
	main_mem = ft_calloc(1, sizeof(t_memman));
	main_mem->sim = ft_calloc(1, sizeof(t_sim));
	if (main_mem->sim && parsing_args(argc, argv, &main_mem->sim))
		return (1);
	init_sim(&main_mem);
	free_mem(&main_mem);
}

/*
parsear os args - feito
startar todos os philos - feito
distribuir os garfos - feito
pegar "time" inicial1
ininiar todos as threads
pausar todas as threads
iniciar o monitor
usleep(5000)
despausar todas os philos
atrasar a primeira passada dos philos pares em 1
GG
*/
