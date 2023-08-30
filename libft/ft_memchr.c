/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:14:46 by ael-maar          #+#    #+#             */
/*   Updated: 2022/10/01 16:28:43 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_cast;
	size_t				i;

	i = 0;
	s_cast = s;
	while (i < n)
	{
		if (s_cast[i] == (unsigned char)c)
			return ((void *)&s_cast[i]);
		i++;
	}
	return (0);
}
