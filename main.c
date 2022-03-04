/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarmeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 09:10:52 by pcarmeli          #+#    #+#             */
/*   Updated: 2021/12/26 13:59:48 by pcarmeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_default(t_data *data)
{
	data->scale = 25;
	data->z_scale = 2;
	data->is_isometric = 1;
	data->angle = 0.8;
	data->shift_x = W_WIDTH / 3;
	data->shift_y = W_HEIGHT / 3;
	data->init = mlx_init();
	data->window = mlx_new_window(data->init, W_WIDTH, W_HEIGHT, "FDF");
}

int	deal_key(int key, t_data **matrix)
{
	if (key == (0X35))
	{
		mlx_destroy_window(matrix[0][0].init, matrix[0][0].window);
		free(matrix);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	**matrix;

	if (argc == 2)
	{
		matrix = map_reading(*++argv);
		set_default(&matrix[0][0]);
		drawing(matrix);
		mlx_key_hook(matrix[0][0].window, deal_key, matrix);
		mlx_loop(matrix[0][0].init);
	}
	else
		ft_error(0);
}
