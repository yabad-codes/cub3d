/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:13:41 by ael-maar          #+#    #+#             */
/*   Updated: 2022/10/21 17:13:47 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left;

	line = read_from_file(fd, left);
	left = NULL;
	if (line)
	{
		left = check_nl_and_alloc_left(line);
	}
	return (line);
}
