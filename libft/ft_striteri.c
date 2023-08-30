/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:53:56 by ael-maar          #+#    #+#             */
/*   Updated: 2022/10/08 16:12:13 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	len_s;
	size_t	i;

	if (s && f)
	{
		len_s = ft_strlen(s);
		i = 0;
		while (i < len_s)
		{
			f(i, &s[i]);
			i++;
		}
	}
}
