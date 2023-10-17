/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 00:59:09 by anshimiy          #+#    #+#             */
/*   Updated: 2022/11/24 15:27:42 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// check if stop_sig == 0 or not (1/2),
// if stop_sig == 0, it returns 0 otherwise, 1
int	table_over(t_table *table)
{
	pthread_mutex_lock(&table->arg.dead);
	if (table->arg.stop_sig)
	{
		pthread_mutex_unlock(&table->arg.dead);
		return (1);
	}
	pthread_mutex_unlock(&table->arg.dead);
	return (0);
}

/*
	wait until table_over != 0 (a philo died or philos finished eating)
	then, join all philos threads and destroy write_mutex
	destroy all the forks and free philos
*/
void	stop(t_table *table)
{
	int	i;

	i = -1;
	while (!table_over(table))
		ft_usleep(1);
	while (++i < table->arg.total_philos)
		pthread_join(table->philos[i].thread_id, NULL);
	pthread_mutex_destroy(&table->arg.write_mutex);
	i = -1;
	while (++i < table->arg.total_philos)
		pthread_mutex_destroy(&table->philos[i].left_fork);
	if (table->arg.stop_sig == 2)
		printf("Each philosopher ate %d time(s)\n", table->arg.must_eat);
	free(table->philos);
}

/*
	t_table	table: contains a t_philo array of philosophers and their arguments
	if (!init_table(&table) || !create_threads(&table)): 
		init the table 			make the threads 
						free philos after
	stop(&table): mutex_destroy & free everything
*/
int	main(int argc, char **argv)
{
	t_table	table;

	if (!(parse_args(argc, argv, &table)))
		return (throw_error("Invalid Arguments\n", -1));
	table.philos = malloc(sizeof(t_philo) * table.arg.total_philos);
	if (!table.philos)
		return (throw_error("Malloc failed\n", -1));
	if (!init_table(&table) || !create_threads(&table))
	{
		free(table.philos);
		return (0);
	}
	stop(&table);
}
