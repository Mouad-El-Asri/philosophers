/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:31:43 by moel-asr          #+#    #+#             */
/*   Updated: 2023/01/23 18:08:14 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo(void *philo)
{
	t_philosopher *philosopher;

	philosopher = (t_philosopher *)philo;
	while (1)
	{
		if (pthread_mutex_lock(&philosopher->args->forks[philosopher->right_fork]) != 0)
			print_errors(9);
		// if (pthread_mutex_lock(&philosopher->args->log_message) != 0)
		// 	print_errors(9);
		log_message(philosopher, "has taken a fork");
		// if (pthread_mutex_unlock(&philosopher->args->log_message) != 0)
		// 	print_errors(10);
		if (pthread_mutex_lock(&philosopher->args->forks[philosopher->left_fork]) != 0)
			print_errors(9);
		// if (pthread_mutex_lock(&philosopher->args->log_message) != 0)
		// 	print_errors(9);
		log_message(philosopher, "has taken a fork");
		// if (pthread_mutex_unlock(&philosopher->args->log_message) != 0)
		// 	print_errors(10);
		// if (pthread_mutex_lock(&philosopher->args->last_meal) != 0)
		// 	print_errors(9);
		philosopher->last_meal = get_time_in_ms();
		// if (pthread_mutex_unlock(&philosopher->args->last_meal) != 0)
		// 	print_errors(10);
		// if (pthread_mutex_lock(&philosopher->args->log_message) != 0)
		// 	print_errors(9);
		log_message(philosopher, "is  eating");
		// if (pthread_mutex_unlock(&philosopher->args->log_message) != 0)
		// 	print_errors(10);
		// if (pthread_mutex_lock(&philosopher->args->sleep) != 0)
		// 	print_errors(9);
		ft_msleep(philosopher->args->time_to_eat);
		// if (pthread_mutex_unlock(&philosopher->args->sleep) != 0)
		// 	print_errors(10);
		if (pthread_mutex_unlock(&philosopher->args->forks[philosopher->right_fork]) != 0)
			print_errors(10);
		if (pthread_mutex_unlock(&philosopher->args->forks[philosopher->left_fork]) != 0)
			print_errors(10);
		// if (pthread_mutex_lock(&philosopher->args->log_message) != 0)
		// 	print_errors(9);
		log_message(philosopher, "is  sleeping");
		// if (pthread_mutex_unlock(&philosopher->args->log_message) != 0)
		// 	print_errors(10);
		// if (pthread_mutex_lock(&philosopher->args->sleep) != 0)
		// 	print_errors(9);
		ft_msleep(philosopher->args->time_to_sleep);
		// if (pthread_mutex_unlock(&philosopher->args->sleep) != 0)
		// 	print_errors(10);
		// if (pthread_mutex_lock(&philosopher->args->log_message) != 0)
		// 	print_errors(9);
		log_message(philosopher, "is  thinking");
		// if (pthread_mutex_unlock(&philosopher->args->log_message) != 0)
		// 	print_errors(10);
	}
}

int main(int argc, char **argv)
{
	int i;
	t_vars args;

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
		ft_msleep(50);
		i++;
	}
	while (1)
	{
		i = 0;
		while (i < args.philosopher_num)
		{
			// if (pthread_mutex_lock(&args.last_meal) != 0)
			// 	print_errors(9);
			if (get_time_in_ms() - args.philosophers[i].last_meal >= args.time_to_die)
			{
				// if (pthread_mutex_lock(&args.log_message) != 0)
				// 	print_errors(9);
				log_message(&args.philosophers[i], "died");
				// if (pthread_mutex_unlock(&args.log_message) != 0)
				// 	print_errors(10);
				return (0);
			}
			// if (pthread_mutex_unlock(&args.last_meal) != 0)
			// 	print_errors(10);
			i++;
		}
	}
	// i = 0;
	// while (i < args.philosopher_num)
	// {
	// 	if (pthread_mutex_destroy(&args.forks[i]) != 0)
	// 		return (print_errors(8));
	// 	i++;
	// }
	// if (pthread_mutex_destroy(&args.last_meal) != 0)
	// 	return (print_errors(8));
	// if (pthread_mutex_destroy(&args.log_message) != 0)
	// 	return (print_errors(8));
	// if (pthread_mutex_destroy(&args.sleep) != 0)
	// 	return (print_errors(8));
	// free(args.philosophers);
	// free(args.forks);
	return (0);
}
