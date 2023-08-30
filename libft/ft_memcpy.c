/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:03:35 by ael-maar          #+#    #+#             */
/*   Updated: 2022/10/07 12:48:46 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_cast;
	unsigned char	*src_cast;
	size_t			i;

	if (!dst && !src)
		return (0);
	dst_cast = dst;
	src_cast = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst_cast[i] = src_cast[i];
		i++;
	}
	return (dst);
}
