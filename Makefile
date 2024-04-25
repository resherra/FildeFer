# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: recherra <recherra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/23 17:11:45 by recherra          #+#    #+#              #
#    Updated: 2024/03/23 17:11:47 by recherra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#macos
FRAEMWORKS=-lmlx -framework OpenGL -framework AppKit

FLAGS=-Wall -Wextra -Werror
SRC=main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c utils/adjusting_utils.c utils/checking_utils.c utils/drawing_utils.c utils/parsing_utils.c utils/projection_utils.c utils/rotation_utils.c utils/get_color.c utils/map_parse.c
SRC_BONUS=main_bonus.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c utils/adjusting_utils.c utils/checking_utils.c utils/bonus/drawing_utils_bonus.c utils/parsing_utils.c utils/bonus/projection_utils_bonus.c utils/bonus/rotation_utils_bonus.c utils/get_color.c utils/map_parse.c utils/bonus/rotation_hooking.c utils/bonus/miscs.c

#linux
INCLUDES=libft/libft.a
NAME=fdf

all:
	@make -C libft/ all
	cc $(SRC) -o $(NAME) $(FLAGS) $(INCLUDES) $(FRAEMWORKS)

bonus:
	@make -C libft/ all
	cc $(SRC_BONUS) -o $(NAME) $(FLAGS)  $(INCLUDES) $(FRAEMWORKS)

clean:
	@make -C libft/ clean

fclean: clean
	rm $(NAME)
	@make -C libft/ fclean

re: fclean all