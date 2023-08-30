/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:02:12 by ael-maar          #+#    #+#             */
/*   Updated: 2022/10/08 15:45:21 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	i;

	if (!s1)
		return (0);
	new_str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (new_str)
	{
		i = 0;
		while (*s1)
			new_str[i++] = *(s1++);
		while (*s2)
			new_str[i++] = *(s2++);
		new_str[i] = '\0';
	}
	return (new_str);
}
