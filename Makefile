# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/26 15:28:45 by lyie              #+#    #+#              #
#    Updated: 2021/04/29 09:42:28 by lyie             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =		ft_read.s \
			ft_write.s \
		       	ft_strcpy.s \
		       	ft_strcmp.s \
		       	ft_strlen.s \
			ft_strdup.s

SRCS_BONUS = $(wildcard ./*.s)

OBJS = ${SRCS:.s=.o}
OBJS_BONUS = ${SRCS_BONUS:.s=.o}

NAME = libasm.a

CC = clang
NA = nasm
RM = rm -f

CFLAGS = -Wall -Wextra -Werror
NFLAGS = -f elf64
.s.o:
		${NA} ${NFLAGS} $<
.c.o:
		${CC} ${CFLAGS} $<
			
$(NAME) : ${OBJS}
		$ ar rc libasm.a ${OBJS}

bonus: ${OBJS_BONUS}
	$ ar rc libasm.a ${OBJS_BONUS}

all: ${NAME}

test: 
	$ clang -Wall -Wextra -Werror -g3 main.c -L. -lasm -o run_tests

test_bonus:
	$ clang -Wall -Wextra -Werror -g3 main_bonus.c testing_bonus.c -L. -lasm -o run_tests

clean:
			${RM} ${OBJS}

fclean: clean
			${RM} ${NAME} ./run_tests

clean_bonus: fclean
			${RM} ${OBJS_BONUS} ./run_tests

re: fclean all

.PHONY: all clean fclean re bonus
