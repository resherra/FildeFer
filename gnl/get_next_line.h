/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:20:30 by recherra          #+#    #+#             */
/*   Updated: 2024/02/16 17:21:41 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_utils
{
	char	*buffer;
	char	*next_line;
	char	*tmp;
	ssize_t	readed;
	int		truncated;

}			t_utils;

char		*get_next_line(int fd);
char		*ft_strjoin(char *line, char *buffer);
char		*ft_strdup(char *str);
void		ft_strlcpy(char *dst, char *src, int dstsize);
int			ft_trunc(char *str);

#endif
