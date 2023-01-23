/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:54:19 by moel-asr          #+#    #+#             */
/*   Updated: 2023/01/23 12:03:42 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	mutex_init(t_vars *args)
{
	int	i;

	i = 0;
	while (i < args->philosopher_num)
	{
		if (pthread_mutex_init(&args->forks[i], NULL) != 0)
			return (print_errors(6));
		i++;
	}
	if (pthread_mutex_init(&args->last_meal, NULL) != 0)
		return (print_errors(6));
	if (pthread_mutex_init(&args->log_message, NULL) != 0)
		return (print_errors(6));
	if (pthread_mutex_init(&args->sleep, NULL) != 0)
		return (print_errors(6));
	return (0);
}
