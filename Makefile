# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: recherra <recherra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/23 17:11:45 by recherra          #+#    #+#              #
#    Updated: 2024/04/25 19:12:23 by recherra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRAMEWORKS=-lmlx -framework OpenGL -framework AppKit
FLAGS=-Wall -Wextra -Werror
SRC=main.c\
	get_next_line/get_next_line.c\
	get_next_line/get_next_line_utils.c\
	utils/adjusting_utils.c\
	utils/checking_utils.c\
	utils/drawing_utils.c\
	utils/parsing_utils.c\
	utils/projection_utils.c\
	utils/rotation_utils.c\
	utils/get_color.c\
	utils/map_parse.c\
	 utils/bonus/miscs.c
SRC_BONUS=main_bonus.c\
 	get_next_line/get_next_line.c\
 	get_next_line/get_next_line_utils.c\
 	utils/adjusting_utils.c\
 	utils/checking_utils.c\
 	utils/bonus/drawing_utils_bonus.c\
 	utils/parsing_utils.c\
 	utils/bonus/projection_utils_bonus.c\
 	utils/bonus/rotation_utils_bonus.c\
 	utils/get_color.c\
 	utils/map_parse.c\
 	utils/bonus/rotation_hooking.c\
 	utils/bonus/miscs.c
OBJS=${SRC:.c=.o}
OBJS_BONUS=${SRC_BONUS:.c=.o}
LIBFT=libft/libft.a
NAME=fdf
BONUS_NAME=fdf_bonus


all: ${NAME}

${NAME}: ${LIBFT} ${OBJS} fdf.h
	cc ${OBJS} -o ${NAME} ${FLAGS} ${LIBFT} ${FRAMEWORKS}

${LIBFT}:
	make -C libft/

bonus: ${BONUS_NAME}

${BONUS_NAME}: ${LIBFT} ${OBJS_BONUS} fdf_bonus.h
	cc ${OBJS_BONUS} -o ${BONUS_NAME} ${FLAGS} ${LIBFT} ${FRAMEWORKS}

clean:
	make -C libft/ clean
	rm -rf ${OBJS} ${OBJS_BONUS}

fclean: clean
	make -C libft/ fclean
	rm ${NAME} ${BONUS_NAME}

re: fclean all