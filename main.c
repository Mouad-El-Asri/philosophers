/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:31:43 by moel-asr          #+#    #+#             */
/*   Updated: 2023/01/14 18:09:31 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int x = 0;

void	*routinee()
{
	for (int i = 0; i < 2000000000; i++)
		x++;
}

int	main(int argc, char **argv)
{
	pthread_t	t1, t2;
	pthread_create(&t1, NULL, &routinee, NULL);
	pthread_join(t1, NULL);
	pthread_create(&t2, NULL, &routinee, NULL);
	pthread_join(t2, NULL);
	printf("x == %lu\n", t1);
	// if (check_errors(argc, argv))
	// 	return (1);
}
