/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 00:59:17 by anshimiy          #+#    #+#             */
/*   Updated: 2022/11/23 18:14:27 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include "./includes/my_lib/mylib.h"

// stop_sig = // 0 if none philosopher is dead, 1 if a philosopher
// is dead, 2 if all philosophers ate must_eat times
//
// write_mutex: a mutex to protect the message to write
// dead: a mutex to verify the death
// time_eat: a mutex to set the time a philo ate
// finish: a mutex to verify is philos finished
typedef struct s_arg
{
	int						total_philos;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						must_eat;
	long int				start_time;
	pthread_mutex_t			write_mutex;
	pthread_mutex_t			dead;
	pthread_mutex_t			time_eat;
	pthread_mutex_t			finish;
	int						nb_philos_finish_eat;
	int						stop_sig;
}							t_arg;

// finish_eat 1 when a philosopher ate must_eat times, if not, 0
typedef struct s_philo
{
	int						id;
	pthread_t				thread_id;
	pthread_t				thread_death_id;
	pthread_mutex_t			*right_fork;
	pthread_mutex_t			left_fork;
	t_arg					*philo_arg;
	long int				ms_last_eat;
	unsigned int			nb_ate;
	int						finish_eat;
}							t_philo;

typedef struct s_p
{
	t_philo					*philos;
	t_arg					arg;
}							t_table;

int				parse_args(int argc, char **argv, t_table *table);
int				init_table(t_table *table);
void			write_status(char *str, t_philo *philos);
long int		actual_time(void);
void			ft_usleep(long int time_in_ms);
int				create_threads(t_table *table);
void			activity(t_philo *philos);
int				check_death(t_philo *philos, int i);
int				ft_death_watcher(t_table *table, t_philo *philos);

#endif