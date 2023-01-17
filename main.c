/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:31:43 by moel-asr          #+#    #+#             */
/*   Updated: 2023/01/17 16:41:59 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo()
{
	
}

int	main(int argc, char **argv)
{
	int				i;
	pthread_t		philosophers[ft_atoi(argv[1])];
	pthread_mutex_t	forks[ft_atoi(argv[1])];

	i = 0;
	check_errors(argc, argv);
	while (i < ft_atoi(argv[1]))
	{
		if (pthread_mutex_init(&forks[i++], NULL) != 0)
			ft_putstr_fd("Error\n", 2);
		i++;
	}
	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		if (pthread_create(&philosophers[i], NULL, &philo, NULL) != 0)
			ft_putstr_fd("Error\n", 2);
		i++;
	}
	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		if (pthread_join(&philosophers[i], NULL) != 0)
			ft_putstr_fd("Error\n", 2);
		i++;
	}
	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		if (pthread_mutex_destroy(&forks[i]) != 0)
			ft_putstr_fd("Error\n", 2);
		i++;
	}
	return (0);
}
