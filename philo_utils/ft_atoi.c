/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:20:03 by moel-asr          #+#    #+#             */
/*   Updated: 2023/01/22 08:12:35 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	if (!str[i])
		return (print_errors(1));
	else if (str[i] == '-' && ++i)
		return (print_errors(2));
	else if (str[i] == '+')
		i++;
	while (str[i] || str[i - 1] == '+')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (print_errors(3));
		num = num * 10 + (str[i] - 48);
		if (sign == 1 && num != 0 && (INT_MAX / num) < 1)
			return (print_errors(4));
		i++;
	}
	if (num * sign == 0)
		return (print_errors(5));
	return (num * sign);
}
