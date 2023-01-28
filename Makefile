# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 13:36:04 by moel-asr          #+#    #+#              #
#    Updated: 2023/01/27 23:02:35 by moel-asr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -Wall -Wextra -Werror

SRCS = philo_utils/ft_atoi.c \
	philo_utils/ft_putchar_fd.c \
	philo_utils/ft_putstr_fd.c \
	philo_srcs/check_death_and_meals.c \
	philo_srcs/check_death.c \
	philo_srcs/check_errors.c \
	philo_srcs/check_meals_eaten.c \
	philo_srcs/ft_usleep.c \
	philo_srcs/get_time_in_ms.c \
	philo_srcs/log_message.c \
	philo_srcs/mutex_init.c \
	philo_srcs/mutex_last_meal.c \
	philo_srcs/mutex_log_message.c \
	philo_srcs/mutex_meals_eaten.c \
	philo_srcs/print_errors.c \
	philo_srcs/routine.c \
	philo_srcs/structs_init.c \
	main.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean