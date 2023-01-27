/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_log_message.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:30:38 by moel-asr          #+#    #+#             */
/*   Updated: 2023/01/25 18:56:42 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	mutex_log_message(char *str, t_philosopher	*philosopher)
{
	if (pthread_mutex_lock(&philosopher->args->log_message))
		print_errors(9);
	log_message(philosopher, str);
	if (pthread_mutex_unlock(&philosopher->args->log_message))
		print_errors(10);
}
