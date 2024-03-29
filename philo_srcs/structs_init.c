/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:36:18 by moel-asr          #+#    #+#             */
/*   Updated: 2023/01/27 22:18:28 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	stucts_init(t_vars *args, char **argv)
{
	int	i;

	i = 0;
	args->philosopher_num = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	args->philosophers = (t_philosopher *)malloc(args->philosopher_num * \
					sizeof(t_philosopher));
	args->forks = (pthread_mutex_t *)malloc(args->philosopher_num * \
					sizeof(pthread_mutex_t));
	if (argv[5])
		args->meals_number = ft_atoi(argv[5]);
	while (i < args->philosopher_num)
	{
		args->philosophers[i].id = i + 1;
		args->philosophers[i].last_meal = get_time_in_ms();
		args->philosophers[i].rfork = i;
		if (i + 1 == args->philosopher_num)
			args->philosophers[i].lfork = 0;
		else
			args->philosophers[i].lfork = i + 1;
		args->philosophers[i].args = args;
		args->philosophers[i++].meals_eaten = 0;
	}
}
