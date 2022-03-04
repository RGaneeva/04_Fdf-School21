/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarmeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 09:11:11 by pcarmeli          #+#    #+#             */
/*   Updated: 2021/12/26 13:58:56 by pcarmeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_numbs(char *line, t_data **matrix, int y)
{
	char	**numbs;
	int		x;

	numbs = ft_split(line, ' ');
	x = 0;
	while (numbs[x])
	{
		matrix[y][x].z = ft_atoi(numbs[x]);
		matrix[y][x].x = x;
		matrix[y][x].y = y;
		matrix[y][x].last = 0;
		free(numbs[x]);
		x++;
	}
	free(numbs);
	free(line);
	matrix[y][--x].last = 1;
}

void	ft_error(int err_nb)
{
	if (err_nb == 1)
	{
		ft_putstr("file does not exist\n");
		exit(1);
	}
	else if (err_nb == 0)
	{
		ft_putstr("usage: ./fdf map.fdf OR ./fdf ./folder/map.fdf\n");
		exit(1);
	}
}

t_data	**mem_alloc(char *file)
{
	t_data	**matrix;
	int		x;
	int		y;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY, 0);
	if (fd <= 0)
		ft_error(1);
	get_next_line(fd, &line);
	x = ft_numb_count(line, ' ');
	free(line);
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		y++;
		free(line);
	}
	free(line);
	matrix = (t_data **) malloc (sizeof(t_data *) * (++y + 1));
	while (y > 0)
		matrix[--y] = (t_data *) malloc (sizeof(t_data) * (x + 1));
	close(fd);
	return (matrix);
}

t_data	**map_reading(char *file)

{
	t_data	**matrix;
	int		y;
	int		fd;
	char	*line;

	matrix = mem_alloc(file);
	fd = open(file, O_RDONLY, 0);
	if (fd <= 0)
		ft_error(1);
	y = 0;
	while (get_next_line(fd, &line) > 0)
		get_numbs(line, matrix, y++);
	free(line);
	matrix[y] = NULL;
	close(fd);
	return (matrix);
}
