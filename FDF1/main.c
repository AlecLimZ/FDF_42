/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:33:51 by leng-chu          #+#    #+#             */
/*   Updated: 2021/12/07 11:48:40 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SRC/fdf.h"

int	deal_key(int key, t_fdf *data)
{
	t_line line;

	if (!data)
		return (0);
	printf("%d\n", key);
	if (key == 126)
		data->addy -= 20;
	if (key == 125)
		data->addy += 20;
	if (key == 124)
		data->addx += 20;
	if (key == 123)
		data->addx -= 20;
	draw_floor(&line, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

void	ft_set(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->img = mlx_new_image(data->mlx_ptr, 1000, 1000);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	data->zoom = 20;
}

void	ft_setline(t_line *line)
{
	line->x = 10;
	line->y = 10;
	line->x1 = 600;
	line->y1 = 300;
}

int	main(int argc, char **argv)
{
	t_fdf	data;
	t_line	line;

	if (argc <= 1)
		return (0);
	read_file(argv[1], &data);
	ft_set(&data);
//	ft_setline(&line);
//	ft_bresenham(&line, &data);
	draw_floor(&line, &data);
	mlx_key_hook(data.win_ptr, deal_key, &data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, 0,0);
	mlx_loop(data.mlx_ptr);
}
