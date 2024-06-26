/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:22:17 by recherra          #+#    #+#             */
/*   Updated: 2024/02/22 11:55:27 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	get_ft_strlcpy(next_line, *line, truncated + 2);
	tmp = *line;
	*line = get_ft_strdup((*line) + truncated + 1);
	freed(&tmp);
	return (next_line);
}

static char	*last_line(char **line)
{
	char	*tmp;

	tmp = get_ft_strdup(*line);
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
	static char	*line;

	initial(&utils);
	if (BUFFER_SIZE <= 0 || (read(fd, utils.buffer, 0)) < 0)
		return (freed(&line));
	utils.buffer = malloc(BUFFER_SIZE + 1);
	if (!utils.buffer)
		return (freed(&line));
	while (utils.readed == BUFFER_SIZE && utils.truncated == -1)
	{
		utils.readed = read(fd, utils.buffer, BUFFER_SIZE);
		utils.buffer[utils.readed] = '\0';
		utils.tmp = line;
		line = get_ft_strjoin(line, utils.buffer);
		freed(&utils.tmp);
		utils.truncated = ft_trunc(line);
	}
	freed(&utils.buffer);
	if (utils.truncated == -1)
		return (utils.tmp = last_line(&line));
	else
		utils.next_line = ne_line(&line, utils.truncated);
	return (utils.next_line);
}
