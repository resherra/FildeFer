/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:37:42 by recherra          #+#    #+#             */
/*   Updated: 2024/03/23 17:37:46 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// open, close, read, write, malloc, free, perror, strerror, exit, ft_printf

typedef struct s_pcord
{
	int	x;
	int	y;
	int	z;
	int	color;
}		t_pcord;

typedef struct s_map_size
{
	int	x;
	int	y;
}		t_map_size;

typedef struct s_vector {
    double x;
    double y;
    double z;
} t_vector;

typedef struct s_mlx
{
    void *mlx_connection;
    void *mlx_window;
} t_mlx;

int		get_color(char *point);
void	cols_rows_count(char *map, t_map_size *plan);
void	map_dots(char *file, t_map_size *plan, t_pcord ***points);
void	mem_allocation(t_map_size *plan, t_pcord ***points);
t_pcord **map_parse(char *str, t_map_size *plan);

#endif