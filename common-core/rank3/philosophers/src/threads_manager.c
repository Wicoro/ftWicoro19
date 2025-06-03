/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:37:22 by norban            #+#    #+#             */
/*   Updated: 2025/05/28 11:55:44 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	eat_all(t_list *list)
{
	int	i;
	int	eat;

	if (list->eat_nb == -1)
		return (0);
	i = 0;
	while (i < list->philo_nb)
	{
		pthread_mutex_lock(&list->philosophers[i]->lock_eat_nb);
		eat = list->philosophers[i]->eat_nb;
		pthread_mutex_unlock(&list->philosophers[i]->lock_eat_nb);
		if (eat < list->eat_nb)
			return (0);
		i++;
	}
	return (1);
}

void	end_threads(t_list *list)
{
	int	i;

	i = 0;
	while (i < list->philo_nb)
	{
		pthread_mutex_lock(&list->philosophers[i]->lock_end);
		list->philosophers[i]->end_status = 1;
		pthread_mutex_unlock(&list->philosophers[i]->lock_end);
		i++;
	}
}

int	wait_end(t_list *list, t_phil **philosophers, int i)
{
	struct timeval	tv;
	long			time;
	int				id_end;

	id_end = -1;
	while (eat_all(list) == 0 && id_end == -1)
	{
		i = 0;
		while (i < list->philo_nb)
		{
			gettimeofday(&tv, NULL);
			time = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
			pthread_mutex_lock(&philosophers[i]->lock_last_eat);
			if (time - philosophers[i]->last_eat
				> philosophers[i]->timers->die_time)
			{
				pthread_mutex_unlock(&philosophers[i]->lock_last_eat);
				id_end = philosophers[i]->id;
				break ;
			}
			pthread_mutex_unlock(&philosophers[i]->lock_last_eat);
			i++;
		}
	}
	return (id_end);
}

int	start_threads(pthread_t **t_id, t_list *list, t_thread_arg **args)
{
	int				i;

	i = 0;
	*args = malloc(sizeof(t_thread_arg) * list->philo_nb);
	if (!*args)
		return (1);
	while (i < list->philo_nb)
	{
		(*args)[i].index = i;
		(*args)[i].philosophers = list->philosophers;
		pthread_create(&(*t_id)[i], NULL, routine, &(*args)[i]);
		i++;
	}
	return (0);
}

void	create_threads(t_list *list)
{
	pthread_t		*t_id;
	t_thread_arg	*args;
	int				id;
	int				i;

	t_id = malloc(sizeof(pthread_t) * list->philo_nb);
	if (!t_id)
		return ;
	if (start_threads(&t_id, list, &args) == 1)
		return (free(t_id));
	id = wait_end(list, list->philosophers, 0);
	end_threads(list);
	if (id != -1)
		print_log(4, id, list->philosophers[id - 1]->time_start);
	i = 0;
	while (i < list->philo_nb)
	{
		pthread_join(t_id[i], NULL);
		i++;
	}
	free(t_id);
	free(args);
}
