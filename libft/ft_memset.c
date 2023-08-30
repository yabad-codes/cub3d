/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:30:22 by ael-maar          #+#    #+#             */
/*   Updated: 2022/09/30 17:49:40 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b_cast;
	size_t			i;

	b_cast = b;
	i = 0;
	while (i < len)
	{
		b_cast[i] = c;
		i++;
	}
	return (b);
}
