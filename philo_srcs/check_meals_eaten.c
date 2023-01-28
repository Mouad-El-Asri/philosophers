/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_meals_eaten.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:18:17 by moel-asr          #+#    #+#             */
/*   Updated: 2023/01/27 22:38:00 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_meals_eaten(t_vars *args)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < args->philosopher_num)
	{
		if (pthread_mutex_lock(&args->meals_eaten) != 0)
			print_errors(9);
		if (args->philosophers[i++].meals_eaten >= args->meals_number)
			count++;
		if (pthread_mutex_unlock(&args->meals_eaten) != 0)
			print_errors(10);
	}
	if (count == args->philosopher_num)
	{
		if (pthread_mutex_lock(&args->meals_eaten) != 0)
			print_errors(9);
		if (pthread_mutex_lock(&args->log_message) != 0)
			print_errors(9);
		if (pthread_mutex_lock(&args->last_meal) != 0)
			print_errors(9);
		return (0);
	}
	return (1);
}
