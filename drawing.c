/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarmeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 11:46:15 by pcarmeli          #+#    #+#             */
/*   Updated: 2021/12/26 14:01:55 by pcarmeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_data *dot, double angle)
{
	dot->x = (dot->x - dot->y) * cos(angle);
	dot->y = (dot->x + dot->y) * sin(angle) - dot->z;
}

void	zoom(t_data *a, t_data *b, t_data *data)
{
	a->x *= data->scale;
	a->y *= data->scale;
	b->x *= data->scale;
	b->y *= data->scale;
	a->z *= data->z_scale;
	b->z *= data->z_scale;
}

void	set_data(t_data *a, t_data *b, t_data *data)
{
	zoom(a, b, data);
	if (data->is_isometric)
	{
		isometric(a, data->angle);
		isometric(b, data->angle);
	}
	a->x += data->shift_x;
	a->y += data->shift_y;
	b->x += data->shift_x;
	b->y += data->shift_y;
}

void	bresenham(t_data a, t_data b, t_data *data)
{
	float	step_x;
	float	step_y;
	float	max;
	int		color;

	set_data(&a, &b, data);
	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = maximum(ft_module(step_x), ft_module(step_y));
	step_x /= max;
	step_y /= max;
	if (b.z || a.z)
		color = 0xff00ff;
	else
		color = 0xd3d3d3;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(data->init, data->window, a.x, a.y, color);
		a.x += step_x;
		a.y += step_y;
		if (a.x > W_WIDTH || a.y > W_HEIGHT || a.y < 0 || a.x < 0)
			break ;
	}
}

void	drawing(t_data **matrix)
{
	int	x;
	int	y;

	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (1)
		{
			if (matrix[y + 1])
				bresenham(matrix[y][x], matrix[y + 1][x], &matrix[0][0]);
			if (!matrix[y][x].last)
				bresenham(matrix[y][x], matrix[y][x + 1], &matrix[0][0]);
			if (matrix[y][x].last)
				break ;
			x++;
		}
		y++;
	}
}
