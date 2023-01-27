/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_last_meal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:46:10 by moel-asr          #+#    #+#             */
/*   Updated: 2023/01/25 18:56:55 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	mutex_last_meal(t_philosopher	*philosopher)
{
	if (pthread_mutex_lock(&philosopher->args->last_meal))
		print_errors(9);
	philosopher->last_meal = get_time_in_ms();
	if (pthread_mutex_unlock(&philosopher->args->last_meal))
		print_errors(10);
}
