/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 00:59:06 by anshimiy          #+#    #+#             */
/*   Updated: 2022/11/24 15:27:55 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	write_status(char *str, t_philo *philos)
{
	long int		time;

	time = actual_time() - philos->philo_arg->start_time;
	if (time >= 0 && time <= 2147483647 && !check_death(philos, 0))
	{
		printf("%ld ", time);
		printf("%d %s", philos->id, str);
	}
}

/*
	Continuation of activity() for norm reasons
*/
void	sleep_think(t_philo *philos)
{
	pthread_mutex_lock(&philos->philo_arg->write_mutex);
	write_status("is sleeping\n", philos);
	pthread_mutex_unlock(&philos->philo_arg->write_mutex);
	ft_usleep(philos->philo_arg->time_to_sleep);
	pthread_mutex_lock(&philos->philo_arg->write_mutex);
	write_status("is thinking\n", philos);
	pthread_mutex_unlock(&philos->philo_arg->write_mutex);
}

/*
	Since the cylcle is the same, I write a linear way
	the philo status by mutex_lock each situations
*/
void	activity(t_philo *philos)
{
	pthread_mutex_lock(&philos->left_fork);
	pthread_mutex_lock(&philos->philo_arg->write_mutex);
	write_status("has taken a fork\n", philos);
	pthread_mutex_unlock(&philos->philo_arg->write_mutex);
	if (!philos->right_fork)
	{
		ft_usleep(philos->philo_arg->time_to_die * 2);
		return ;
	}
	pthread_mutex_lock(philos->right_fork);
	pthread_mutex_lock(&philos->philo_arg->write_mutex);
	write_status("has taken a fork\n", philos);
	pthread_mutex_unlock(&philos->philo_arg->write_mutex);
	pthread_mutex_lock(&philos->philo_arg->write_mutex);
	write_status("is eating\n", philos);
	pthread_mutex_lock(&philos->philo_arg->time_eat);
	philos->ms_last_eat = actual_time();
	pthread_mutex_unlock(&philos->philo_arg->time_eat);
	pthread_mutex_unlock(&philos->philo_arg->write_mutex);
	ft_usleep(philos->philo_arg->time_to_eat);
	pthread_mutex_unlock(philos->right_fork);
	pthread_mutex_unlock(&philos->left_fork);
	sleep_think(philos);
}
