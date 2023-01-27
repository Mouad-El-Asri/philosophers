/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_meals_eaten.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:46:01 by moel-asr          #+#    #+#             */
/*   Updated: 2023/01/27 18:00:10 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	mutex_meals_eaten(t_philosopher	*philosopher)
{
	if (pthread_mutex_lock(&philosopher->args->meals_eaten))
		print_errors(9);
	philosopher->meals_eaten++;
	if (pthread_mutex_unlock(&philosopher->args->meals_eaten))
		print_errors(10);
}
