/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death_and_meals.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 22:11:15 by moel-asr          #+#    #+#             */
/*   Updated: 2023/01/27 22:17:08 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_death_and_meals(t_vars *args, int argc)
{
	if (check_death(args) == 0)
	{
		free(args->philosophers);
		free(args->forks);
		return (0);
	}
	if (argc == 6)
	{
		if (check_meals_eaten(args) == 0)
		{
			free(args->philosophers);
			free(args->forks);
			return (0);
		}
	}
	usleep(50);
	return (1);
}
