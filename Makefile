# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: recherra <recherra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/23 17:11:45 by recherra          #+#    #+#              #
#    Updated: 2025/02/21 17:38:08 by recherra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# FRAMEWORKS=-lmlx -framework OpenGL -framework AppKit
FRAMEWORKS=-lmlx_Linux -lXext -lX11 -lm -lz
FLAGS=-Wall -Wextra -Werror
SRC=main.c\
 	get_next_line/get_next_line.c\
 	get_next_line/get_next_line_utils.c\
 	utils/adjusting_utils.c\
 	utils/checking_utils.c\
 	utils//drawing_utils.c\
 	utils/parsing_utils.c\
 	utils//projection_utils.c\
 	utils//rotation_utils.c\
 	utils/get_color.c\
 	utils/map_parse.c\
 	utils//rotation_hooking.c\
 	utils//miscs.c
OBJS=${SRC:.c=.o}
LIBFT=libft/libft.a
NAME=fdf


all: ${NAME}

${NAME}: ${LIBFT} ${OBJS} fdf.h
	cc ${OBJS} -o ${NAME} ${FLAGS} ${LIBFT} ${FRAMEWORKS}

${LIBFT}:
	make -C libft/

clean:
	make -C libft/ clean
	rm -rf ${OBJS}

fclean: clean
	make -C libft/ fclean
	rm ${NAME}

re: fclean all