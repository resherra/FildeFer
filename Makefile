# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: recherra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/23 17:11:45 by recherra          #+#    #+#              #
#    Updated: 2024/03/23 17:11:47 by recherra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = joe.c hell.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJ = ${SRC:.c=.o}
NAME = testing.a

all: ${NAME}

${NAME}: ${OBJ}
	ar -rcs ${NAME} ${OBJ}

clean:
		rm -rf ${OBJ} ${OBONUS}
fclean: clean
	rm -rf ${NAME}
	
re: fclean all