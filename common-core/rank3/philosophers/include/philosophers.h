/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:27:12 by norban            #+#    #+#             */
/*   Updated: 2025/01/31 14:51:21 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define STD_IN 0
# define STD_OUT 1
# define STD_ERR 2

# define THINKING 0
# define EATING 1
# define SLEEPING 2

typedef struct s_timers
{
	int		die_time;
	int		eat_time;
	int		sleep_time;
}	t_timers;

typedef struct s_philosophers
{
	int						id;
	int						status;
	long					last_eat;
	long					time_start;
	int						eat_nb;
	pthread_mutex_t			fork;
	pthread_mutex_t			lock_eat_nb;
	pthread_mutex_t			lock_last_eat;
	pthread_mutex_t			lock_end;
	int						end_status;
	struct s_philosophers	*next;
	struct s_philosophers	*prev;
	t_timers				*timers;
}	t_phil;

typedef struct s_list
{
	int		philo_nb;
	int		eat_nb;
	t_phil	**philosophers;
}	t_list;

t_list	*create_list(char **av, long time_ms);
void	create_philosophers(t_list *list);
void	*routine(void *phil);
void	print_error(int error_code);
void	print_log(int code, int id, long time_start);
int		ft_atoi(const char *str);
void	create_threads(t_list *list);
void	free_all(t_list *list);
void	frag_sleep(int duration);

#endif