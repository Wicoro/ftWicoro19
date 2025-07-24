/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:47:22 by norban            #+#    #+#             */
/*   Updated: 2025/06/28 17:06:03 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	end_routine(t_phil	**philosophers, int index)
{
	int	next;

	next = 0;
	if (philosophers[index + 1])
		next = index + 1;
	pthread_mutex_lock(&philosophers[index]->lock_end);
	if (philosophers[index]->end_status == 1
		|| philosophers[next]->id == philosophers[index]->id)
	{
		pthread_mutex_unlock(&philosophers[index]->lock_end);
		return (1);
	}
	pthread_mutex_unlock(&philosophers[index]->lock_end);
	return (0);
}

void	philo_eat(t_phil **philosophers, int index)
{
	struct timeval	tv;
	long			time;
	int				next;

	next = 0;
	if (philosophers[index + 1])
		next = index + 1;
	gettimeofday(&tv, NULL);
	time = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	pthread_mutex_lock(&philosophers[index]->lock_last_eat);
	if (end_routine(philosophers, index) == 0)
		print_log(EATING, philosophers[index]->id,
			philosophers[index]->time_start);
	philosophers[index]->last_eat = time;
	pthread_mutex_unlock(&philosophers[index]->lock_last_eat);
	frag_sleep(philosophers[index]->timers->eat_time);
	pthread_mutex_unlock(&philosophers[index]->fork);
	pthread_mutex_unlock(&philosophers[next]->fork);
	pthread_mutex_lock(&philosophers[index]->lock_eat_nb);
	philosophers[index]->eat_nb += 1;
	pthread_mutex_unlock(&philosophers[index]->lock_eat_nb);
}

void	philo_eat_setup(t_phil **philos, int index)
{
	int	next;

	next = 0;
	if (philos[index + 1])
		next = index + 1;
	if (philos[index]->id < philos[next]->id)
	{
		pthread_mutex_lock(&philos[index]->fork);
		if (end_routine(philos, index) == 0)
			print_log(3, philos[index]->id, philos[index]->time_start);
		pthread_mutex_lock(&philos[next]->fork);
		if (end_routine(philos, index) == 0)
			print_log(3, philos[index]->id, philos[index]->time_start);
	}
	else
	{
		pthread_mutex_lock(&philos[next]->fork);
		if (end_routine(philos, index) == 0)
			print_log(3, philos[index]->id, philos[index]->time_start);
		pthread_mutex_lock(&philos[index]->fork);
		if (end_routine(philos, index) == 0)
			print_log(3, philos[index]->id, philos[index]->time_start);
	}
	philo_eat(philos, index);
}

void	philo_sleep_think(t_phil **philosophers, int index, int i)
{
	if (i == 0)
	{
		print_log(SLEEPING, philosophers[index]->id,
			philosophers[index]->time_start);
		frag_sleep(philosophers[index]->timers->sleep_time);
	}
	if (i == 1)
	{
		print_log(THINKING, philosophers[index]->id,
			philosophers[index]->time_start);
		frag_sleep(1);
	}
}

void	*routine(void *arg_r)
{
	t_thread_arg	*arg;
	t_phil			**philosophers;
	int				index;

	arg = arg_r;
	index = arg->index;
	philosophers = arg->philosophers;
	if (philosophers[index]->id % 2 == 0)
		frag_sleep(philosophers[index]->timers->eat_time - 10);
	while (1)
	{
		if (end_routine(philosophers, index) == 0)
			philo_eat_setup(philosophers, index);
		if (end_routine(philosophers, index) == 0)
			philo_sleep_think(philosophers, index, 0);
		if (end_routine(philosophers, index) == 0)
			philo_sleep_think(philosophers, index, 1);
		else
			break ;
	}
	return (NULL);
}
