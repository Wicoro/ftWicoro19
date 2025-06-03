/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:15:47 by norban            #+#    #+#             */
/*   Updated: 2025/05/28 10:39:35 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	fill_philo(t_list *list, char **av, long time_ms, int i)
{
	list->philosophers[i] = malloc(sizeof(t_phil));
	if (!list->philosophers[i])
		return (0);
	list->philosophers[i]->timers = malloc(sizeof(t_timers));
	if (!list->philosophers)
		return (0);
	list->philosophers[i]->timers->die_time = ft_atoi(av[2]);
	list->philosophers[i]->timers->sleep_time = ft_atoi(av[4]);
	list->philosophers[i]->timers->eat_time = ft_atoi(av[3]);
	if (ft_atoi(av[2]) <= 0 || ft_atoi(av[3]) <= 0 || ft_atoi(av[4]) <= 0)
		return (print_error(2), 0);
	list->philosophers[i]->eat_nb = 0;
	list->philosophers[i]->time_start = time_ms;
	return (1);
}

t_list	*create_list(char **av, long time_ms)
{
	t_list	*list;
	int		i;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->philo_nb = ft_atoi(av[1]);
	if (list->philo_nb <= 0)
		return (free(list), print_error(2), NULL);
	list->philosophers = malloc(sizeof(t_phil *) * (list->philo_nb + 1));
	if (!list->philosophers)
		return (free(list), print_error(2), NULL);
	list->philosophers[list->philo_nb] = NULL;
	i = -1;
	while (++i < list->philo_nb)
	{
		if (fill_philo(list, av, time_ms, i) == 0)
			return (free(list->philosophers[i]->timers),
				free(list->philosophers[i]),
				free(list->philosophers), free(list), NULL);
	}
	list->eat_nb = -1;
	if (av[5] && ft_atoi(av[5]) > 0)
		list->eat_nb = ft_atoi(av[5]);
	return (list);
}

void	create_philosopher(t_list *list, int i)
{
	struct timeval	tv;
	long			time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	list->philosophers[i]->id = i + 1;
	list->philosophers[i]->last_eat = time;
	list->philosophers[i]->end_status = 0;
	if (pthread_mutex_init(&list->philosophers[i]->fork, NULL) != 0)
		return (free_all(list), print_error(3));
	if (pthread_mutex_init(&list->philosophers[i]->lock_eat_nb, NULL) != 0)
		return (free_all(list), print_error(3));
	if (pthread_mutex_init(&list->philosophers[i]->lock_last_eat, NULL) != 0)
		return (free_all(list), print_error(3));
	if (pthread_mutex_init(&list->philosophers[i]->lock_end, NULL) != 0)
		return (free_all(list), print_error(3));
}

void	create_philosophers(t_list *list)
{
	int	i;

	i = 0;
	while (i < list->philo_nb)
	{
		create_philosopher(list, i);
		i++;
	}
}
