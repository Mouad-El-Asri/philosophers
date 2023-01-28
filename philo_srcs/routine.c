/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:01:53 by moel-asr          #+#    #+#             */
/*   Updated: 2023/01/28 16:50:08 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *philo)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)philo;
	while (1)
	{
		if (pthread_mutex_lock(&philosopher->args->forks[philosopher->rfork]))
			print_errors(9);
		mutex_log_message("has taken a fork", philosopher);
		if (pthread_mutex_lock(&philosopher->args->forks[philosopher->lfork]))
			print_errors(9);
		mutex_log_message("has taken a fork", philosopher);
		mutex_last_meal(philosopher);
		mutex_log_message("is eating", philosopher);
		ft_usleep(philosopher->args->time_to_eat);
		mutex_meals_eaten(philosopher);
		if (pthread_mutex_unlock(&philosopher->args->forks[philosopher->rfork]))
			print_errors(10);
		if (pthread_mutex_unlock(&philosopher->args->forks[philosopher->lfork]))
			print_errors(10);
		mutex_log_message("is sleeping", philosopher);
		ft_usleep(philosopher->args->time_to_sleep);
		mutex_log_message("is thinking", philosopher);
	}
}
