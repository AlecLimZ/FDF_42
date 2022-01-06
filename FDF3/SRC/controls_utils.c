/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 20:16:23 by leng-chu          #+#    #+#             */
/*   Updated: 2022/01/03 21:09:15 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key_macos.h"

void	zoom(int key, t_fdf *fdf)
{
	if (key == NUM_PAD_PLUS || key == MAIN_PAD_PLUS
		|| key == 61 || key == 65451
		|| key == MOUSE_SCROLL_UP)
		fdf->camera->zoom++;
	else if (key == NUM_PAD_MINUS || key == MAIN_PAD_MINUS
		|| key == 45 || key == 65453
		|| key == MOUSE_SCROLL_DOWN)
		fdf->camera->zoom--;
	if (fdf->camera->zoom < 1)
		fdf->camera->zoom = 1;
	draw(fdf->map, fdf);

}

void	move(int key, t_fdf *fdf)
{
	if (key == ARROW_LEFT || key == 65361)
		fdf->camera->x_offset -= 10;
	else if (key == ARROW_RIGHT || key == 65363)
		fdf->camera->x_offset += 10;
	else if (key == ARROW_UP || key == 65362)
		fdf->camera->y_offset -= 10;
	else
		fdf->camera->y_offset += 10;
	draw(fdf->map, fdf);
}

void	rotate(int key, t_fdf *fdf)
{
	if (key == NUM_PAD_2 || key == MAIN_PAD_2 || key == 115)
		fdf->camera->alpha += 0.05;
	else if (key == NUM_PAD_8 || key == MAIN_PAD_8 || key == 119)
		fdf->camera->alpha -= 0.05;
	else if (key == NUM_PAD_4 || key == MAIN_PAD_4 || key == 97)
		fdf->camera->beta -= 0.05;
	else if (key == NUM_PAD_6 || key == MAIN_PAD_6 || key == 100)
		fdf->camera->beta += 0.05;
	else if (key == NUM_PAD_1 || key == MAIN_PAD_1
		|| key == NUM_PAD_3 || key == MAIN_PAD_3 || key == 113)
		fdf->camera->gamma += 0.05;
	else if (key == NUM_PAD_7 || key == MAIN_PAD_7
		|| key == NUM_PAD_9 || key == MAIN_PAD_9 || key == 101)
		fdf->camera->gamma -= 0.05;
	draw(fdf->map, fdf);
}

void	flatten(int key, t_fdf *fdf)
{
	if (key == MAIN_PAD_LESS || key == 44)
		fdf->camera->z_divisor -= 0.1;
	else if (key == MAIN_PAD_MORE || key == 46)
		fdf->camera->z_divisor += 0.1;
	if (fdf->camera->z_divisor < 0.1)
		fdf->camera->z_divisor = 0.1;
	else if (fdf->camera->z_divisor > 10)
		fdf->camera->z_divisor = 10;
	draw(fdf->map, fdf);
}

void	change_projection(int key, t_fdf *fdf)
{
	fdf->camera->alpha = 0;
	fdf->camera->beta = 0;
	fdf->camera->gamma = 0;
	if (key == MAIN_PAD_I || key == 105)
		fdf->camera->projection = ISO;
	else if (key == MAIN_PAD_P || key == 112)
		fdf->camera->projection = PARALLEL;
	draw(fdf->map, fdf);
}
