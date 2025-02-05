/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:17:54 by norban            #+#    #+#             */
/*   Updated: 2025/01/29 17:37:13 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_philo(t_phil *philo)
{
	free(philo->timers);
	pthread_mutex_destroy(&philo->fork);
	pthread_mutex_destroy(&philo->lock_eat_nb);
	pthread_mutex_destroy(&philo->lock_last_eat);
	pthread_mutex_destroy(&philo->lock_end);
	free(philo);
}

void	free_all(t_list *list)
{
	int	i;

	i = 0;
	while (i < list->philo_nb)
	{
		free_philo(list->philosophers[i]);
		i++;
	}
	free(list->philosophers);
	free(list);
	return ;
}
