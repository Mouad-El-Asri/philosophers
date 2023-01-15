/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:25:12 by moel-asr          #+#    #+#             */
/*   Updated: 2023/01/13 23:33:43 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_errors(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 5 || argc > 6)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	while (argv[++i])
	{
		if (ft_atoi(argv[i]) == -1 || ft_atoi(argv[i]) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
	}
	return (0);
}
