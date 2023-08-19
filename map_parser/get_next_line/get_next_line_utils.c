/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:29:31 by yabad             #+#    #+#             */
/*   Updated: 2022/10/27 16:01:38 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	ls;

	i = 0;
	ls = ft_strlen(s);
	while (i < ls)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, int len)
{
	int		i;
	char	*dstp;
	char	*srcp;

	if (!dst && !src)
		return (NULL);
	dstp = dst;
	srcp = (char *)src;
	i = 0;
	while (i < len)
	{
		dstp[i] = srcp[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	s = (char *)malloc((i + j + 1) * sizeof(char));
	if (!s)
	{
		free(s1);
		return (NULL);
	}
	ft_memcpy(s, s1, i);
	ft_memcpy(s + i, s2, j);
	s[i + j] = '\0';
	return (s);
}
