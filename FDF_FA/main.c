/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:33:51 by leng-chu          #+#    #+#             */
/*   Updated: 2022/01/16 17:18:42 by leng-chu         ###   ########.fr       */
/*   Updated: 2021/12/07 11:48:40 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// initizate fdf setting, window size
void	ft_set(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "FDF");
	data->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bt, &data->by, &data->en);
	data->height = 0;
	data->width = 0;
	data->pos_m = 0;
	data->pos_c = 0;
	data->range = 0;
	data->max = INT_MIN;
	data->min = INT_MAX;
}

//	initizate zoom setting, it is similar to camera view

void	ft_setzoom(t_fdf *data)
{
	int	x;
	int	y;

	x = (WIDTH - MENU_H) / data->width / 2;
	y = HEIGHT / data->height / 2;
	if (x < y)
		data->zm.zoom = x;
	else
		data->zm.zoom = y;
	data->zm.alpha = 0;
	data->zm.beta = 0;
	data->zm.gamma = -1;
	data->zm.z = 1.5;
	data->zm.x = 0;
	data->zm.y = 0;
	data->zm.projection = 0;
}

int	main(int argc, char **argv)
{
	t_fdf	data;

	errno = 0;
	if (argc <= 1)
		return (0);
	ft_set(&data);
	read_file(argv[1], &data);
	ft_setzoom(&data);
	ft_draw(&data);
	mlx_key_hook(data.win_ptr, ft_keyboard, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
