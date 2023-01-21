# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 13:36:04 by moel-asr          #+#    #+#              #
#    Updated: 2023/01/21 23:00:29 by moel-asr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -Wall -Wextra -Werror

SRCS = philo_utils/ft_atoi.c \
	philo_utils/ft_putchar_fd.c \
	philo_utils/ft_putstr_fd.c \
	philo_srcs/check_errors.c \
	philo_srcs/get_time_in_ms.c \
	philo_srcs/log_message.c \
	philo_srcs/structs_init.c \
	main.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -fsanitize=address -o  $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean