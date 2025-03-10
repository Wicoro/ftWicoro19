/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:47:22 by norban            #+#    #+#             */
/*   Updated: 2025/03/10 15:03:48 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	end_routine(t_phil	*philosopher)
{
	pthread_mutex_lock(&philosopher->lock_end);
	if (philosopher->end_status == 1
		|| philosopher->next->id == philosopher->id)
	{
		pthread_mutex_unlock(&philosopher->lock_end);
		return (1);
	}
	pthread_mutex_unlock(&philosopher->lock_end);
	return (0);
}

void	philo_eat(t_phil *philosopher)
{
	struct timeval	tv;
	long			time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	pthread_mutex_lock(&philosopher->lock_last_eat);
	if (end_routine(philosopher) == 0)
		print_log(EATING, philosopher->id, philosopher->time_start);
	philosopher->last_eat = time;
	pthread_mutex_unlock(&philosopher->lock_last_eat);
	frag_sleep(philosopher->timers->eat_time);
	pthread_mutex_unlock(&philosopher->fork);
	pthread_mutex_unlock(&philosopher->next->fork);
	pthread_mutex_lock(&philosopher->lock_eat_nb);
	philosopher->eat_nb += 1;
	pthread_mutex_unlock(&philosopher->lock_eat_nb);
}

void	philo_eat_setup(t_phil *philosopher)
{
	if (philosopher->id < philosopher->next->id)
	{
		pthread_mutex_lock(&philosopher->fork);
		if (end_routine(philosopher) == 0)
			print_log(3, philosopher->id, philosopher->time_start);
		pthread_mutex_lock(&philosopher->next->fork);
		if (end_routine(philosopher) == 0)
			print_log(3, philosopher->id, philosopher->time_start);
	}
	else
	{
		pthread_mutex_lock(&philosopher->next->fork);
		if (end_routine(philosopher) == 0)
			print_log(3, philosopher->id, philosopher->time_start);
		pthread_mutex_lock(&philosopher->fork);
		if (end_routine(philosopher) == 0)
			print_log(3, philosopher->id, philosopher->time_start);
	}
	philo_eat(philosopher);
}

void	philo_sleep_think(t_phil *philosopher, int i)
{
	if (i == 0)
	{
		print_log(SLEEPING, philosopher->id, philosopher->time_start);
		frag_sleep(philosopher->timers->sleep_time);
	}
	if (i == 1)
	{
		print_log(THINKING, philosopher->id, philosopher->time_start);
		frag_sleep(1);
	}
}

void	*routine(void *arg)
{
	t_phil	*philosopher;

	philosopher = arg;
	if (philosopher->id % 2 == 0)
		frag_sleep(philosopher->timers->eat_time - 10);
	while (1)
	{
		if (end_routine(philosopher) == 0)
			philo_eat_setup(philosopher);
		if (end_routine(philosopher) == 0)
			philo_sleep_think(philosopher, 0);
		if (end_routine(philosopher) == 0)
			philo_sleep_think(philosopher, 1);
		else
			break ;
	}
	return (NULL);
}
