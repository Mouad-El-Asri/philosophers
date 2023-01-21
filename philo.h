/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:32:00 by moel-asr          #+#    #+#             */
/*   Updated: 2023/01/21 20:33:47 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

typedef struct s_philosopher
{
	int				id;
	long			last_meal;
	int				right_fork;
	int				left_fork;
	pthread_t		philosopher;
	struct s_vars	*args;
}	t_philosopher;

typedef struct s_vars
{
	int				philosopher_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_number;
	long			start_time;
	t_philosopher	*philosophers;
	pthread_mutex_t	*forks;
}	t_vars;

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);
int		check_errors(int argc, char **argv);
long	get_time_in_ms(void);
void	log_message(t_philosopher *philo, char *message);
void	stucts_init(t_vars *args, char **argv);

void	*philo(void *philo);

#endif