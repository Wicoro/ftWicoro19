/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:16:30 by norban            #+#    #+#             */
/*   Updated: 2025/01/28 18:31:05 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_list			*list;
	struct timeval	tv;
	long			time_ms;

	gettimeofday(&tv, NULL);
	time_ms = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	if (ac != 5 && ac != 6)
		return (print_error(0), 0);
	list = create_list(av, time_ms);
	if (!list)
		return (1);
	if (list->philosophers[0]->timers->die_time == 0
		|| list->philosophers[0]->timers->eat_time == 0
		|| list->philosophers[0]->timers->sleep_time == 0
		|| list->philo_nb == 0 || list->eat_nb == 0)
		return (print_error(1), 1);
	create_philosophers(list);
	create_threads(list);
	free_all(list);
}
