/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarmeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 13:42:03 by pcarmeli          #+#    #+#             */
/*   Updated: 2021/12/26 13:42:47 by pcarmeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_next_line(int fd, char **line)
{
	int	readed;
	int	i;

	i = 0;
	*line = malloc(4 * 1024 * 1024);
	if (!line)
		return (-1);
	readed = read(fd, *line + i, 1);
	while (readed > 0)
	{
		if ((*line)[i] == '\n')
			break ;
		i++;
		readed = read(fd, *line + i, 1);
	}
	(*line)[i] = '\0';
	return (readed);
}
