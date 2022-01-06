/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:39:23 by leng-chu          #+#    #+#             */
/*   Updated: 2022/01/06 16:59:22 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "error_message.h"

t_map	*map_init(void)
{
	t_map	*map;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	if (!map)
		terminate(ERR_MAP_INIT);
	map->width = 0;
	map->height = 0;
	map->coords_arr = NULL;
	map->colors_arr = NULL;
	map->z_min = INT_MAX;
	map->z_max = INT_MIN;
	map->z_range = 0;
	return (map);
}

t_fdf	*fdf_init(t_map *map)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf));
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FdF");
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf || !fdf->mlx || !fdf->win || !fdf->img)
		terminate(ERR_FDF_INIT);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
			&(fdf->size_line), &(fdf->endian));
	fdf->map = map;
	fdf->mouse = (t_mouse *)ft_memalloc(sizeof(t_mouse));
	if (!fdf->mouse)
		terminate(ERR_FDF_INIT);
	return (fdf);
}

t_camera	*camera_init(t_fdf *fdf)
{
	t_camera	*camera;
	int			x;
	int			y;

	camera = (t_camera *)ft_memalloc(sizeof(t_camera));
	if (!camera)
		terminate(ERR_CAMERA_INIT);
	x = (WIDTH - MENU_WIDTH) / fdf->map->width / 2;
	y = HEIGHT / fdf->map->height / 2;
	if (x < y)
		camera->zoom = x;
	else
		camera->zoom = y;
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->z_divisor = 1;
	camera->x_offset = 0;
	camera->y_offset = 0;
	return (camera);
}
