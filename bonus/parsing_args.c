/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:54:34 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/11/10 15:32:54 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	is_number(char **argv);
static int	is_valid_number(t_sim **sim);

int	parsing_args(int argc, char **argv, t_sim **sim)
{
	int	i;

	i = 0;
	if (argc == 6)
		sim[0]->times_eat = 1;
	sim[0]->msg[0] = TAKEN_FORK;
	sim[0]->msg[1] = EATING;
	sim[0]->msg[2] = SLEEPING;
	sim[0]->msg[3] = THINKING;
	sim[0]->msg[4] = DIED;
	if (!is_number(argv))
	{
		argv++;
		while (*argv)
		{
			sim[0]->args[i] = ft_atoi(*argv);
			if (sim[0]->args[i++] != ft_atoll(*argv++))
				return (1);
		}
	}
	else
		return (1);
	if (is_valid_number(sim))
		return (1);
	return (0);
}

static int	is_valid_number(t_sim **sim)
{
	int	i;

	if (sim[0]->times_eat)
		i = 4;
	else
		i = 3;
	while (i >= 0)
		if (sim[0]->args[i--] <= 0)
			return (1);
	return (0);
}

static int	is_number(char **argv)
{
	int	i[2];

	i[0] = 1;
	while (argv[i[0]])
	{
		i[1] = 0;
		while (ft_isspace(argv[i[0]][i[1]]))
			i[1]++;
		if (argv[i[0]][i[1]] == '+' || argv[i[0]][i[1]] == '-')
			i[1]++;
		while (argv[i[0]][i[1]])
		{
			if (argv[i[0]][i[1]] < '0' || argv[i[0]][i[1]] > '9')
				return (1);
			i[1]++;
		}
		i[0]++;
	}
	return (0);
}
