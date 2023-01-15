/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:20:03 by moel-asr          #+#    #+#             */
/*   Updated: 2023/01/13 22:29:22 by moel-asr         ###   ########.fr       */
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
		return (-1);
	else if (str[i] == '-' && ++i)
		return (-1);
	else if (str[i] == '+')
		i++;
	while (str[i] || str[i - 1] == '+')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		num = num * 10 + (str[i] - 48);
		if (sign == 1 && num != 0 && (INT_MAX / num) < 1)
			return (-1);
		i++;
	}
	return (num * sign);
}
