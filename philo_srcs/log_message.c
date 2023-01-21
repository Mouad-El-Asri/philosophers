/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_message.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:25:21 by moel-asr          #+#    #+#             */
/*   Updated: 2023/01/21 15:32:33 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	log_message(t_philosopher *philo, char *message)
{
	long	time_passed_in_ms;

	time_passed_in_ms = get_time_in_ms() - philo->args->start_time;
	printf("%ld ms %d %s\n", time_passed_in_ms, philo->id, message);
}
