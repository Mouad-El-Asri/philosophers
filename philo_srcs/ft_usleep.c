/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 23:31:06 by moel-asr          #+#    #+#             */
/*   Updated: 2023/01/27 20:04:10 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_usleep(long time_in_ms)
{
	long	current_time;

	current_time = get_time_in_ms();
	usleep ((time_in_ms - 20) * 1000);
	while (get_time_in_ms() <= current_time + time_in_ms)
		;
}
