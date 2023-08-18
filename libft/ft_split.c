/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:05:37 by ael-maar          #+#    #+#             */
/*   Updated: 2023/03/17 19:26:41 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_delimiter(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static size_t	calc_size_strs(char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		while (*s && check_delimiter(*s, c))
			s++;
		if (*s && !check_delimiter(*s, c))
			len++;
		while (*s && !check_delimiter(*s, c))
			s++;
	}
	return (len);
}

static char	*ft_word(char *s, char delimiter)
{
	char	*word;
	size_t	len;
	size_t	i;

	len = 0;
	while (s[len] && !check_delimiter(s[len], delimiter))
		len++;
	word = malloc((len + 1) * sizeof(char));
	i = 0;
	if (word)
	{
		while (i < len)
		{
			word[i] = s[i];
			i++;
		}
		word[i] = '\0';
	}
	return (word);
}

char	**fill_str(char *s, char **strs, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s && check_delimiter(*s, c))
			s++;
		if (*s && !check_delimiter(*s, c))
		{
			strs[i] = ft_word((char *)s, c);
			if (strs[i] == NULL)
			{
				while ((i - 1) >= 0)
					free(strs[(i--) - 1]);
				free(strs);
				return (NULL);
			}
			i++;
		}
		while (*s && !check_delimiter(*s, c))
			s++;
	}
	strs[i] = NULL;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	size_strs;

	if (!s)
		return (0);
	size_strs = calc_size_strs((char *)s, c);
	strs = (char **)malloc((size_strs + 1) * sizeof(char *));
	if (strs)
		strs = fill_str((char *)s, strs, c);
	return (strs);
}
