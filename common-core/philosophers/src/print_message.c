/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:19:10 by norban            #+#    #+#             */
/*   Updated: 2025/01/31 14:02:04 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_error(int error_code)
{
	if (error_code == 0)
		printf("Invalid args numbers : error code 0");
	if (error_code == 1)
		printf("Invalid args : error code 1");
}

void	print_log(int code, int id, long time_start)
{
	struct timeval	tv;
	long			time_ms;

	gettimeofday(&tv, NULL);
	time_ms = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	if (code == THINKING)
		printf("[%ld] %d is thinking\n", time_ms - time_start, id);
	if (code == EATING)
		printf("[%ld] %d is eating\n", time_ms - time_start, id);
	if (code == SLEEPING)
		printf("[%ld] %d is sleeping\n", time_ms - time_start, id);
	if (code == 3)
		printf("[%ld] %d has taken a fork\n", time_ms - time_start, id);
}
