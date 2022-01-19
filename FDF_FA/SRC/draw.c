/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:12:00 by leng-chu          #+#    #+#             */
/*   Updated: 2022/01/16 17:17:52 by leng-chu         ###   ########.fr       */
/*   Updated: 2021/12/07 11:42:02 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// this is part of Bresenham algo
static void	ft_assign(t_coord *delta, t_coord *sign, t_coord f, t_coord s)
{
	int	num;

	num = s.x - f.x;
	if (num < 0)
		num = -num;
	delta->x = num;
	num = s.y - f.y;
	if (num < 0)
		num = -num;
	delta->y = num;
	if (f.x < s.x)
		sign->x = 1;
	else
		sign->x = -1;
	if (f.y < s.y)
		sign->y = 1;
	else
		sign->y = -1;
}

// this function is to drawing both object background & menu background
static void	draw_background(t_fdf *data)
{
	int	*image;
	int	i;

	ft_bzero(data->addr, WIDTH * HEIGHT * (data->bt / 8));
	image = (int *)(data->addr);
	i = 0;
	while (i < WIDTH * HEIGHT)
	{
		if (i < WIDTH * (HEIGHT - MENU_H))
			image[i] = MAP_BG;
		else
			image[i] = MENU_BG;
		i++;
	}
}

// this function is drawing between start and end position
// using bresenham algo formula
void	ft_bresenham(t_coord f, t_coord s, t_fdf *data)
{
	t_coord	delta;
	t_coord	cur;
	t_coord	sign;
	int		error[2];

	ft_assign(&delta, &sign, f, s);
	error[0] = delta.x - delta.y;
	cur = f;
	while (cur.x != s.x || cur.y != s.y)
	{
		ft_write_pixel(data, cur.x, cur.y, ft_color(cur, f, s, delta));
		error[1] = error[0] * 2;
		if (error[1] > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}

// this function is the main function for drawing an image
void	ft_draw(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	draw_background(data);
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x != data->width - 1)
				ft_bresenham(project(new_coord(x, y, data), data),
					project(new_coord(x + 1, y, data), data), data);
			if (y != data->height - 1)
				ft_bresenham(project(new_coord(x, y, data), data),
					project(new_coord(x, y + 1, data), data), data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	ft_menu(data);
}
