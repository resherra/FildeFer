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
#define INIT_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"
#include "libft/libft.h"


// open, close, read, write, malloc, free, perror, strerror, exit, ft_printf


//0 0 0 0
//0 1 42 0
//0 0 0 0


typedef struct s_pcord
{
	int x;
	int y;
	int z;
	int col;
} t_pcord;

typedef struct s_map_size {
	int x;
	int y;
} t_map_size;


#endif