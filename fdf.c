/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:02:31 by leng-chu          #+#    #+#             */
/*   Updated: 2021/12/02 12:22:28 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SRC/fdf.h"

// keycode ESC: 53

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	draw_line(t_data *data, int beginX, int beginY, int endX, int endY, int color)
{
	double	deltaX;
	double	deltaY;
	int		pixels;
	double	pixelX;
	double	pixelY;
	
	deltaX = endX - beginX;
	deltaY = endY - beginY;
	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	pixelX = beginX;
	pixelY = beginY;
	while (pixels)
	{
		my_mlx_pixel_put(data, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
	return (0);
}

int	square(int x, int y, t_data *data, int color)
{
	int	a;
	int	b;

//	a = x - 10;
//	b = y - 10;
	a = x;
	b = y;
	x = a;
	while (x <= (a + 20))
	{
		y = b;
		while (y <= (b + 20))
			my_mlx_pixel_put(data, x, y++, color);
		x++;
	}
	return (1);
}

int	add(int count)
{
	static int	c;

	c += count + 1;
	return (c);
}

int	mouse_event(int button, int x, int y, t_data *data)
{
	if (!data || !x || !y)
		return (0);
	if (button == 5)
	{
		printf("hello from mouse\n");
	}
	return (1);
}

int	key_hook(int keycode, t_data *data)
{
	static int	count;
	int	x;
	int	y;

	x = 0;
	y = 0;
	count = 0;
	if (!data)
		return (0);
	if (keycode == 1)
	{
		mlx_mouse_get_pos(data->win, &x, &y);
		count = add(count);
		printf("Total square: %d\n", count);
		if (count > 20)
			square(x, y, data, 0xFFFFFF);
		else if (count > 10)
			square(x, y, data, 0xFFFF00);
		else
			square(x, y, data, 0xFF0000);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	return (1);
}

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 700, 700, "Hello world!");
	data.img = mlx_new_image(data.mlx, 700, 700);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
//	my_mlx_pixel_put(&data, 100, 10, 0xFF0000);	
	mlx_mouse_hook(data.win, &mouse_event, &data);
	mlx_key_hook(data.win, &key_hook, &data);
//	draw_line(&data, 700, 700, 0 , 0, 0xFFFFFF);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_loop(data.mlx);
}
