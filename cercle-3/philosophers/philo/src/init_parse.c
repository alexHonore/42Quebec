/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 00:59:11 by anshimiy          #+#    #+#             */
/*   Updated: 2022/11/19 18:22:18 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	is_valid_digits(char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (ft_nb_out_bounds(argv))
		return (0);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	parse_args(int argc, char **argv, t_table *table)
{
	if ((argc == 5 || argc == 6) && (is_valid_digits(argv)))
	{
		table->arg.total_philos = ft_atoi(argv[1]);
		table->arg.time_to_die = ft_atoi(argv[2]);
		table->arg.time_to_eat = ft_atoi(argv[3]);
		table->arg.time_to_sleep = ft_atoi(argv[4]);
		table->arg.must_eat = -1;
		if (argc == 6)
			table->arg.must_eat = ft_atoi(argv[5]);
		if (table->arg.total_philos <= 0 || table->arg.time_to_die <= 0 \
			|| table->arg.time_to_eat <= 0 || table->arg.time_to_sleep <= 0)
			return (0);
		return (1);
	}
	return (0);
}

void	init_mutex(t_table *table)
{
	pthread_mutex_init(&table->arg.write_mutex, NULL);
	pthread_mutex_init(&table->arg.dead, NULL);
	pthread_mutex_init(&table->arg.time_eat, NULL);
	pthread_mutex_init(&table->arg.finish, NULL);
}

/*
	init the start time which is a timestamp with actual_time()
	init a mutex for write_mutex, dead, time_eat, finish
	init for each philos an id, a mutex for the left fork
	and its right fork which is the one of the next philo except
	the last that'll take the 1st one 
*/
int	init_table(t_table *table)
{
	int	i;
	int	last_philo;

	i = -1;
	last_philo = table->arg.total_philos - 1;
	table->arg.start_time = actual_time();
	table->arg.stop_sig = 0;
	table->arg.nb_philos_finish_eat = 0;
	init_mutex(table);
	while (++i < table->arg.total_philos)
	{
		table->philos[i].id = i + 1;
		table->philos[i].ms_last_eat = table->arg.start_time;
		table->philos[i].nb_ate = 0;
		table->philos[i].finish_eat = 0;
		table->philos[i].right_fork = NULL;
		pthread_mutex_init(&table->philos[i].left_fork, NULL);
		if (table->arg.total_philos == 1)
			return (1);
		if (i == last_philo)
			table->philos[i].right_fork = &table->philos[0].left_fork;
		else
			table->philos[i].right_fork = &table->philos[i + 1].left_fork;
	}
	return (1);
}
