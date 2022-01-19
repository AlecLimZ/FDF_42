/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:49:57 by leng-chu          #+#    #+#             */
/*   Updated: 2022/01/16 15:14:36 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_menu(t_fdf *data)
{
	int		y;
	int		x;
	void	*mlx;
	void	*win;

	x = 200;
	y = HEIGHT - MENU_H;
	mlx = data->mlx_ptr;
	win = data->win_ptr;
	mlx_string_put(mlx, win, x, y += 30, TEXT_COLOR, "===INSTRUCTION===");
	mlx_string_put(mlx, win, x += 15, y += 30, TEXT_COLOR, "Zoom: +/-");
	mlx_string_put(mlx, win, x, y += 20, TEXT_COLOR, "Flatten: </>");
	mlx_string_put(mlx, win, x, y += 20, TEXT_COLOR, "Move: Arrows key");
	mlx_string_put(mlx, win, x, y += 20, TEXT_COLOR, "Animate: M");
	mlx_string_put(mlx, win, x += 250, y -= 90, TEXT_COLOR, "===ROTATE===");
	mlx_string_put(mlx, win, x += 15, y += 30, TEXT_COLOR, "X-Axis: A/D");
	mlx_string_put(mlx, win, x, y += 20, TEXT_COLOR, "Y-Axis: W/S");
	mlx_string_put(mlx, win, x, y += 20, TEXT_COLOR, "Z-Axis: Q/W");
	mlx_string_put(mlx, win, x += 200, y -= 70, TEXT_COLOR, "===PROJECTION===");
	mlx_string_put(mlx, win, x += 15, y += 30, TEXT_COLOR, "ISO: I Key");
	mlx_string_put(mlx, win, x, y += 20, TEXT_COLOR, "Parallel: P key");
}
