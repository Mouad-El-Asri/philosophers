/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 07:50:28 by moel-asr          #+#    #+#             */
/*   Updated: 2023/01/23 09:34:21 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	print_errors(int err_num)
{
	if (err_num == 0)
		ft_putstr_fd("Error\nNumber of arguments is invalid\n", 2);
	else if (err_num == 1)
		ft_putstr_fd("Error\nEmpty argument\n", 2);
	else if (err_num == 2)
		ft_putstr_fd("Error\nNegative number arguments are not valid\n", 2);
	else if (err_num == 3)
		ft_putstr_fd("Error\nNon numeric arguments are not valid\n", 2);
	else if (err_num == 4)
		ft_putstr_fd("Error\nYou have exceeded the max int\n", 2);
	else if (err_num == 5)
		ft_putstr_fd("Error\nThe number 0 is an invalid argument\n", 2);
	else if (err_num == 6)
		ft_putstr_fd("Error\nMutex initialization failed\n", 2);
	else if (err_num == 7)
		ft_putstr_fd("Error\nThread creation failed\n", 2);
	else if (err_num == 8)
		ft_putstr_fd("Error\nMutex destroy failed\n", 2);
	else if (err_num == 9)
		ft_putstr_fd("Error\nMutex lock failed\n", 2);
	else if (err_num == 10)
		ft_putstr_fd("Error\nMutex unlock failed\n", 2);
	return (-1);
}
