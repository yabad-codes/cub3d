/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:52:25 by ael-maar          #+#    #+#             */
/*   Updated: 2023/09/08 12:55:28 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*search_str(char *haystack, char *needle, size_t len)
{
	size_t	check_str;
	size_t	needle_len;
	size_t	i;
	size_t	j;

	i = 0;
	needle_len = ft_strlen(needle);
	while (*haystack && i < len)
	{
		j = i;
		check_str = 0;
		while (haystack[check_str]
			&& haystack[check_str] == needle[check_str] && j < len)
		{
			j++;
			check_str++;
		}
		if (check_str == needle_len)
			return ((char *)haystack);
		i++;
		haystack++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*check_str;

	if (!haystack && len == 0)
		return (0);
	if (needle[0] == '\0')
		return ((char *)haystack);
	check_str = search_str((char *)haystack, (char *)needle, len);
	return (check_str);
}
