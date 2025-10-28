/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 21:12:55 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/10/28 20:41:46 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*create_philos(t_sim *sim);
void	*philo_routine(void *philo);

int	init_sim(t_sim *sim)
{
	t_philo	*philos;
	int		i;

	i = 0;
	pthread_mutex_init(&sim->status, NULL);
	philos = create_philos(sim);
	if (!philos)
		return (1);
	while (i < sim->args[0])
	{
		pthread_create(&philos[i].philo_exec, NULL, philo_routine,
			(void *)&philos[i]);
		pthread_join(philos[i++].philo_exec, NULL);
	}
	return (0);
}

void	*philo_routine(void *philo)
{
	t_philo *philo_232;

	philo_232 = philo;

	while (1)
	{

	}
	return(NULL);
}

t_philo	*create_philos(t_sim *sim)
{
	t_philo			*philos;
	pthread_mutex_t	*forks;
	int				i;

	i = 0;
	philos = ft_gc_calloc_root(sim->args[0], sizeof(t_philo), GC_DATA,
			"philos");
	forks = ft_gc_calloc_root(sim->args[0], sizeof(pthread_mutex_t), GC_DATA,
			"forks");
	if (!philos || !forks)
		return (NULL);
	while (i < sim->args[0])
	{
		pthread_mutex_init(&forks[i], NULL);
		philos[i].fork_r = &forks[i];
		if (i != 0)
			philos[i].fork_l = &forks[i - 1];
		philos[i].id_philo = i + 1;
		i++;
	}
	philos[0].fork_l = &forks[sim->args[0] - 1];
	return (philos);
}

int	main(int argc, char **argv)
{
	t_sim	*sim;

	if (argc < 5 || argc > 6)
		return (1);
	ft_gc_init();
	sim = ft_gc_calloc_root(1, sizeof(t_sim), GC_DATA, "sim");
	if (sim && parsing_args(argc, argv, &sim))
	{
		ft_gc_end();
		return (1);
	}
	init_sim(sim);
	ft_gc_end();
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
