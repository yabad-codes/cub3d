/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:32:55 by ael-maar          #+#    #+#             */
/*   Updated: 2022/10/01 13:24:29 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;

	temp = 0;
	while (*s)
	{
		if (*s == (char)c)
			temp = (char *)s;
		s++;
	}
	if (*s == (char)c)
		temp = (char *)s;
	return (temp);
}
