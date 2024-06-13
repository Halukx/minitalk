# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 13:54:22 by halozdem          #+#    #+#              #
#    Updated: 2023/12/30 13:29:15 by halozdem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_printf.c \
		ft_printf_utils1.c \
		ft_printf_utils2.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a
LIBC = ar rc
CFLAGS = -Wall -Werror -Wextra

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re