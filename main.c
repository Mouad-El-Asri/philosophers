/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:31:43 by moel-asr          #+#    #+#             */
/*   Updated: 2023/01/27 20:02:38 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo(void *philo)
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
				NULL, &philo, &args.philosophers[i]) != 0)
			return (print_errors(7));
		pthread_detach(args.philosophers[i].philosopher);
		i++;
		usleep(50);
	}
	// usleep(50);
	// i = 1;
	// while (i < args.philosopher_num)
	// {
	// 	if (pthread_create(&args.philosophers[i].philosopher,
	// 			NULL, &philo, &args.philosophers[i]) != 0)
	// 		return (print_errors(7));
	// 	i += 2;
	// }
	while (1)
	{
		if (check_death(&args) == 0)
		{
			free(args.philosophers);
			free(args.forks);
			return (0);
		}
		if (argc == 6)
		{
			if (check_meals_eaten(&args) == 0)
			{
				free(args.philosophers);
				free(args.forks);
				return (0);
			}
		}
		usleep(50);
	}
	return (0);
}
