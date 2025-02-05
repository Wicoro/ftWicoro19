/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fragmented_sleep.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:05:35 by norban            #+#    #+#             */
/*   Updated: 2025/02/04 15:38:14 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	frag_sleep(int duration)
{
	struct timeval	tv;
	long			time_start;
	long			time;

	if (duration <= 0)
		duration = 1;
	gettimeofday(&tv, NULL);
	time_start = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	time = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	while (time < time_start + duration)
	{
		usleep(100);
		gettimeofday(&tv, NULL);
		time = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	}
}
