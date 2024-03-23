/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resherra <resherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:20:28 by recherra          #+#    #+#             */
/*   Updated: 2024/01/05 16:02:17 by resherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sep(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

static int	count_words(char const *s, char sep)
{
	int	words;

	words = 0;
	while (*s)
	{
		while (*s && check_sep(*s, sep))
			s++;
		if (*s)
			words++;
		while (*s && !check_sep(*s, sep))
			s++;
	}
	return (words);
}

static char	*word(const char *s, char sep)
{
	int		i;
	int		j;
	char	*re;

	i = 0;
	j = 0;
	while (s[j] && !check_sep(s[j], sep))
		j++;
	re = ft_calloc(j + 1, sizeof(char));
	if (!re)
		return (NULL);
	while (i < j)
	{
		re[i] = s[i];
		i++;
	}
	return (re);
}

static void	*ffree(char **re, int index)
{
	int	i;

	i = 0;
	while (i < index)
		free(re[i++]);
	free(re);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**re;
	char	*wrd;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	re = ft_calloc((count_words(s, c)) + 1, sizeof(char *));
	if (!re)
		return (NULL);
	while (*s)
	{
		while (*s && check_sep(*s, c))
			s++;
		if (*s)
		{
			wrd = word(s, c);
			if (!wrd)
				return (ffree(re, i));
			re[i++] = wrd;
		}
		while (*s && !check_sep(*s, c))
			s++;
	}
	return (re);
}
