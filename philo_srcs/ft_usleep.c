/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 23:31:06 by moel-asr          #+#    #+#             */
/*   Updated: 2023/01/21 23:43:16 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_usleep(int time_in_ms)
{
	long	current_time;
	long	desired_time;

	current_time = get_time_in_ms();
	while (1)
	{
		desired_time = get_time_in_ms();
		if (desired_time == current_time + time_in_ms)
			return ;
	}
}
