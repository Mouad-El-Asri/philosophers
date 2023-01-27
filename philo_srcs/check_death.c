/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:27:54 by moel-asr          #+#    #+#             */
/*   Updated: 2023/01/27 20:03:30 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_death(t_vars *args)
{
	int	i;

	i = 0;
	while (i < args->philosopher_num)
	{
		if (pthread_mutex_lock(&args->last_meal) != 0)
			print_errors(9);
		if (get_time_in_ms() - args->philosophers[i].last_meal >= \
			args->time_to_die)
		{
			if (pthread_mutex_lock(&args->log_message) != 0)
				print_errors(9);
			log_message(&args->philosophers[i], "died");
			return (0);
		}
		if (pthread_mutex_unlock(&args->last_meal) != 0)
			print_errors(10);
		i++;
	}
	return (1);
}
