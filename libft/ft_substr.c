/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 19:17:51 by ael-maar          #+#    #+#             */
/*   Updated: 2023/03/17 17:18:12 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	len_s;
	size_t	i;

	if (!s)
		return (0);
	len_s = ft_strlen(s);
	if (start >= len_s || len == 0)
		return (ft_strdup(""));
	else if (len_s > len && ft_strlen(&s[start]) >= len)
		sub_str = malloc((len + 1) * sizeof(char));
	else
		sub_str = malloc((ft_strlen(&s[start]) + 1) * sizeof(char));
	if (!sub_str)
		return (0);
	i = 0;
	while (s[start] && i < len)
	{
		sub_str[i] = s[start];
		i++;
		start++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
