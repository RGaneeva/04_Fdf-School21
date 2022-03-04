/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarmeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 09:20:16 by pcarmeli          #+#    #+#             */
/*   Updated: 2021/12/26 14:09:18 by pcarmeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>
# include <fcntl.h>

# define W_WIDTH	(1280)
# define W_HEIGHT	(720)

typedef struct s_data
{
	float	x;
	float	y;
	float	z;
	int		last;
	int		scale;
	int		z_scale;
	double	angle;
	int		is_isometric;
	int		shift_x;
	int		shift_y;
	void	*init;
	void	*window;
}			t_data;

void	drawing(t_data **matrix);
void	bresenham(t_data a, t_data b, t_data *data);
void	set_data(t_data *a, t_data *b, t_data *data);
void	isometric(t_data *dot, double angle);
void	set_default(t_data *data);
void	ft_error(int err_nb);
void	get_numbs(char *line, t_data **matrix, int y);
t_data	**map_reading(char *file);
t_data	**mem_alloc(char *file);
int		deal_key(int key, t_data **matrix);

#endif
