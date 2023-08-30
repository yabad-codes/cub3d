/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:13:35 by ael-maar          #+#    #+#             */
/*   Updated: 2023/08/23 13:06:16 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*join_strs(char *s1, char *s2)
{
	char	*join;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	if (join)
	{
		while (s1 && s1[i])
		{
			join[i] = s1[i];
			i++;
		}
		while (s2 && *s2)
			join[i++] = *s2++;
		join[i] = '\0';
	}
	free(s1);
	return (join);
}

char	*read_from_file(int fd, char *left)
{
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	size_t		i;
	int			r;

	line = NULL;
	line = join_strs(line, left);
	free(left);
	r = read(fd, buf, BUFFER_SIZE);
	while (r > 0)
	{
		buf[r] = '\0';
		line = join_strs(line, buf);
		i = 0;
		while (buf[i] && buf[i] != '\n')
			i++;
		if (buf[i] == '\n')
			break ;
		i = 0;
		buf[0] = 0;
		r = read(fd, buf, BUFFER_SIZE);
	}
	return (line);
}

char	*check_nl_and_alloc_left(char *line)
{
	size_t	i;
	size_t	j;
	char	*left;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	j = 0;
	left = NULL;
	if (line[i] == '\n')
	{
		if (line[++i])
		{
			left = malloc(ft_strlen(&line[i]) + 1);
			while (line[i])
				left[j++] = line[i++];
			left[j] = '\0';
		}
	}
	line[i - j] = '\0';
	return (left);
}
