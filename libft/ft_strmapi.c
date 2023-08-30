/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:06:42 by ael-maar          #+#    #+#             */
/*   Updated: 2022/10/08 15:56:03 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len_s;
	size_t	i;
	char	*str_res;

	if (!s || !f)
		return (0);
	len_s = ft_strlen(s);
	str_res = ft_calloc(len_s + 1, sizeof(char));
	if (str_res)
	{
		i = 0;
		while (i < len_s)
		{
			str_res[i] = f(i, s[i]);
			i++;
		}
	}
	return (str_res);
}
