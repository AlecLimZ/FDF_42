/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:26:19 by leng-chu          #+#    #+#             */
/*   Updated: 2022/01/07 17:45:42 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "error_message.h"

/*
 * ---> LINUX KEYBOARD CODE <---
 * ESC = 65307
 * Plus = 61
 * Plus(Numpad) = 65451
 * Minus = 45
 * Minus(Numpad) = 65453
 * Arrow Left = 65361
 * Arrow Up = 65362
 * Arrow Right = 65363
 * Arrow Down = 65364
 * A = 97
 * D = 100
 * W = 119
 * S = 115
 * < = 44
 * > = 46
 * I = 105
 * P = 112
 * Q = 113
 * E = 101
 */

int	key_linux(int keycode, t_fdf *fdf)
{
	if (!fdf)
		return (0);
	if (keycode == 65307)
		exit(0);
	if (keycode == 61 || keycode == 65451
		|| keycode == 45 || keycode == 65453)
		zoom(keycode, fdf);
	else if (keycode == 65361 || keycode == 65362
		|| keycode == 65363 || keycode == 65364)
		move(keycode, fdf);
	else if (keycode == 97 || keycode == 100 || keycode == 119
		|| keycode == 115 || keycode == 113 || keycode == 101)
		rotate(keycode, fdf);
	else if (keycode == 44 || keycode == 46)
		flatten(keycode, fdf);
	else if (keycode == 105 || keycode == 112)
		change_projection(keycode, fdf);
	return (0);
}

int	main(int argc, char **argv)
{
	int			fd;
	t_map		map;
	t_coord_val	*coords_stack;
	t_fdf		*fdf;

	errno = 0;
	coords_stack = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			terminate("Map file does not exist");
		map_init(&map);
		if (read_map(fd, &coords_stack, &map) == -1)
			terminate(ERR_MAP_READING);
		fdf = fdf_init(&map);
		stack_to_arrays(&coords_stack, &map);
		fdf->camera = camera_init(fdf);
		draw(fdf->map, fdf);
		setup_controls(fdf);
		mlx_key_hook(fdf->win, key_linux, fdf);
		mlx_loop(fdf->mlx);
	}
	terminate("Incorrect command. Please use: ./fdf MAP");
	return (0);
}
