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
#include "gnl/get_next_line.h"
#include ""


// open, close, read, write, malloc, free, perror, strerror, exit, ft_printf


typedef struct s_pcord
{
	int x;
	int y;
	int z;
	int col;
} t_pcord;


#endif