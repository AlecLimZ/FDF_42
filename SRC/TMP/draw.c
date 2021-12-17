/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:12:00 by leng-chu          #+#    #+#             */
/*   Updated: 2021/12/07 11:42:02 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	ft_stepcount(t_zoom *zoom)
{
	zoom->x_step = zoom->zx1 - zoom->zx;
	zoom->y_step = zoom->zy1 - zoom->zy;
	if (zoom->x_step < 0)
		zoom->x_step = -zoom->x_step;
	if (zoom->y_step < 0)
		zoom->y_step = -zoom->y_step;
	if (zoom->x_step > zoom->y_step)
		zoom->max = zoom->x_step;
	else
		zoom->max = zoom->y_step;
	zoom->x_step /= zoom->max;
	zoom->y_step /= zoom->max;
}

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.3);
	*y = (*x + *y) * sin(0.3) - z;
}

void	ft_bresenham(t_line *line, t_fdf *data)
{
	t_zoom	zoom;

//	printf("y: %f\n", line->y);
	zoom.c = data->z_matrix[(int)line->y][(int)line->x];
	zoom.c1 = data->z_matrix[(int)line->y1][(int)line->x1];
	if (zoom.c || zoom.c1)
		data->color = 0xff00ff;
	else
		data->color = 0xffffff;
	zoom.zx = line->x * data->zoom;
	zoom.zy = line->y * data->zoom;
	zoom.zx1 = line->x1 * data->zoom;
	zoom.zy1 = line->y1 * data->zoom;

	/*=====3D====== */
	//isometric(&zoom.zx, &zoom.zy, zoom.c);
	//isometric(&zoom.zx1, &zoom.zy1, zoom.c1);
	/*shift*/
	zoom.zx += data->addx;
	zoom.zy += data->addy;
	zoom.zx1 += data->addx;
	zoom.zy1 += data->addy;

	ft_stepcount(&zoom);
	while ((int)(zoom.zx - zoom.zx1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, zoom.zx, zoom.zy, data->color);
		zoom.zx += zoom.x_step;
	}
	//zoom.zx -= data->zoom;
	float tmp = zoom.zy;
	while ((int)(zoom.zy - zoom.zy1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, zoom.zx, zoom.zy, data->color);
		zoom.zy += zoom.y_step;
	}
	zoom.zx -= data->zoom;
	zoom.zy = tmp;
	while ((int)(zoom.zy - zoom.zy1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, zoom.zx, zoom.zy, data->color);
		zoom.zy += zoom.y_step;
	}
}

void	draw_floor(t_line *line, t_fdf *data)
{
	line->y = 0;
	while (line->y < data->height)
	{
		line->x = 0;
		while (line->x < data->width)
		{
			if (line->x < data->width - 1)
				line->x1 = line->x + 1;
			if (line->y < data->height - 1)
				line->y1 = line->y + 1;
			ft_bresenham(line, data);
			line->x++;
		}
		line->y++;
	}
	//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}
