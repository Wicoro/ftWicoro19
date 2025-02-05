/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:37:22 by norban            #+#    #+#             */
/*   Updated: 2025/02/05 23:39:21 by norban           ###   ########.fr       */
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

int	wait_end(t_list *list)
{
	t_phil			*philosopher;
	struct timeval	tv;
	long			time;
	int				id_end;

	id_end = -1;
	philosopher = list->philosophers[0];
	while (eat_all(list) == 0)
	{
		gettimeofday(&tv, NULL);
		time = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
		pthread_mutex_lock(&philosopher->lock_last_eat);
		if (time - philosopher->last_eat > philosopher->timers->die_time)
		{
			pthread_mutex_unlock(&philosopher->lock_last_eat);
			id_end = philosopher->id;
			break ;
		}
		pthread_mutex_unlock(&philosopher->lock_last_eat);
		philosopher = philosopher->next;
		usleep(1000);
	}
	return (id_end);
}

void	create_threads(t_list *list)
{
	int			i;
	pthread_t	*t_id;
	int			id;

	i = 0;
	t_id = malloc(sizeof(pthread_t) * list->philo_nb);
	while (i < list->philo_nb)
	{
		pthread_create(&t_id[i], NULL, routine, list->philosophers[i]);
		i++;
	}
	id = wait_end(list);
	end_threads(list);
	i = 0;
	while (i < list->philo_nb)
	{
		pthread_join(t_id[i], NULL);
		i++;
	}
	if (id != -1)
		print_log(4, id, list->philosophers[id]->time_start);
	free(t_id);
}
