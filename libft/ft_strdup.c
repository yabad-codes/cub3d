/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:04:21 by ael-maar          #+#    #+#             */
/*   Updated: 2022/10/08 18:47:21 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s1_alloc;
	size_t	len_size;
	size_t	i;

	len_size = ft_strlen(s1);
	s1_alloc = malloc((len_size + 1) * sizeof(char));
	if (!s1_alloc)
		return (0);
	i = 0;
	while (i < len_size)
	{
		s1_alloc[i] = s1[i];
		i++;
	}
	s1_alloc[i] = '\0';
	return (s1_alloc);
}
