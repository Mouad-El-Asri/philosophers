/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:31:43 by moel-asr          #+#    #+#             */
/*   Updated: 2023/01/28 16:48:37 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int		i;
	t_vars	args;

	if (check_errors(argc, argv) != 0)
		return (1);
	stucts_init(&args, argv);
	if (mutex_init(&args) != 0)
		return (1);
	i = 0;
	args.start_time = get_time_in_ms();
	while (i < args.philosopher_num)
	{
		if (pthread_create(&args.philosophers[i].philosopher,
				NULL, &routine, &args.philosophers[i]) != 0)
			return (print_errors(7));
		i++;
		usleep(50);
	}
	while (1)
	{
		if (check_death_and_meals(&args, argc) == 0)
			return (0);
	}
	return (0);
}
