/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 21:12:55 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/11/03 21:29:08 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

inline long long	convert_u_ms(long long u)
{
	return (1000L * u);
}

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

int					create_philos(manmem_sim **mem);
void				*philo_routine(void *philo);

int	init_sim(manmem_sim **mainmem)
{
	int	i;

	i = 0;
	pthread_mutex_init(&mainmem[0]->sim->status_w, NULL);
	create_philos(mainmem);
	if (!mainmem[0]->philo)
		return (1);
	while (i < mainmem[0]->sim->args[0])
	{
		pthread_create(&mainmem[0]->philo[i].philo_exec, NULL, philo_routine,
			(void *)&mainmem[0]->philo[i]);
		i++;
	}
	while (--i >= 0)
		pthread_join(mainmem[0]->philo[i].philo_exec, NULL);
	return (0);
}

long long	time_now_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (long long)1000) + (tv.tv_usec / (long long)1000));
}

void	eat_routine(t_philo *philo_t)
{
	pthread_mutex_lock(philo_t->fork_r);
	pthread_mutex_lock(philo_t->status_w);
	printf(TAKEN_FORK, time_now_ms(), philo_t->id_philo, philo_t->status_w);
	pthread_mutex_unlock(philo_t->status_w);
	pthread_mutex_lock(philo_t->fork_l);
	pthread_mutex_lock(philo_t->status_w);
	printf(TAKEN_FORK, time_now_ms(), philo_t->id_philo, philo_t->status_w);
	pthread_mutex_unlock(philo_t->status_w);
	philo_t->last_time_eat = time_now_ms();
	pthread_mutex_lock(philo_t->status_w);
	printf(EATING, philo_t->last_time_eat, philo_t->id_philo);
	pthread_mutex_unlock(philo_t->status_w);
	pthread_mutex_unlock(philo_t->fork_r);
	pthread_mutex_unlock(philo_t->fork_l);
}


print_function(type, philo)
{

}

void	*philo_routine(void *philo)
{
	t_philo	*philo_t;

	philo_t = philo;
	philo_t->last_time_eat = time_now_ms();
	if (philo_t->id_philo % 2 == 0)
		usleep(100000);
	eat_routine(philo_t);
	return (NULL);
}

int	create_philos(manmem_sim **mem)
{
	int	i;

	i = 0;
	mem[0]->philo = ft_calloc(mem[0]->sim->args[0], sizeof(t_philo));
	if (!mem[0]->philo)
		return (1);
	mem[0]->forks = ft_calloc(mem[0]->sim->args[0], sizeof(pthread_mutex_t));
	if (!mem[0]->forks)
		return (2);
	while (i < mem[0]->sim->args[0])
	{
		pthread_mutex_init(&mem[0]->forks[i], NULL);
		mem[0]->philo[i].fork_r = &mem[0]->forks[i];
		mem[0]->philo[i].status_sim = &mem[0]->sim->finish_sim;
		mem[0]->philo[i].status_w = &mem[0]->sim->status_w;
		mem[0]->philo[i].stop = &mem[0]->sim->stop;
		if (i != 0)
			mem[0]->philo[i].fork_l = &mem[0]->forks[i - 1];
		mem[0]->philo[i].id_philo = i + 1;
		i++;
	}
	mem[0]->philo[0].fork_l = mem[0]->philo[0].fork_r;
	mem[0]->philo[0].fork_r = &mem[0]->forks[mem[0]->sim->args[0] - 1];
	return (0);
}

int	free_mem(manmem_sim **main_mem)
{
	free(main_mem[0]->forks);
	free(main_mem[0]->sim);
	free(main_mem[0]->philo);
	free(main_mem[0]);
	return (0);
}

int	main(int argc, char **argv)
{
	manmem_sim	*main_mem;

	if (argc < 5 || argc > 6)
		return (1);
	main_mem = ft_calloc(1, sizeof(manmem_sim));
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
