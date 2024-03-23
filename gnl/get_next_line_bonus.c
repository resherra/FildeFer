/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:14:10 by recherra          #+#    #+#             */
/*   Updated: 2024/02/22 11:55:47 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*freed(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

static char	*ne_line(char **line, int truncated)
{
	char	*next_line;
	char	*tmp;

	next_line = malloc(truncated + 2);
	if (!next_line)
		return (freed(line));
	ft_strlcpy(next_line, *line, truncated + 2);
	tmp = *line;
	*line = ft_strdup((*line) + truncated + 1);
	freed(&tmp);
	return (next_line);
}

static char	*last_line(char **line)
{
	char	*tmp;

	tmp = ft_strdup(*line);
	freed(line);
	return (tmp);
}

static void	initial(t_utils *utils)
{
	utils->buffer = NULL;
	utils->next_line = NULL;
	utils->tmp = NULL;
	utils->readed = BUFFER_SIZE;
	utils->truncated = -1;
}

char	*get_next_line(int fd)
{
	t_utils		utils;
	static char	*line[OPEN_MAX];

	initial(&utils);
	if (BUFFER_SIZE <= 0 || (read(fd, utils.buffer, 0)) < 0)
		return (freed(&line[fd]));
	utils.buffer = malloc(BUFFER_SIZE + 1);
	if (!utils.buffer)
		return (freed(&line[fd]));
	while (utils.readed == BUFFER_SIZE && utils.truncated == -1)
	{
		utils.readed = read(fd, utils.buffer, BUFFER_SIZE);
		utils.buffer[utils.readed] = '\0';
		utils.tmp = line[fd];
		line[fd] = ft_strjoin(line[fd], utils.buffer);
		freed(&utils.tmp);
		utils.truncated = ft_trunc(line[fd]);
	}
	freed(&utils.buffer);
	if (utils.truncated == -1)
		return (utils.tmp = last_line(&line[fd]));
	else
		utils.next_line = ne_line(&line[fd], utils.truncated);
	return (utils.next_line);
}
