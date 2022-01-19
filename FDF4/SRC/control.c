/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:18:13 by leng-chu          #+#    #+#             */
/*   Updated: 2022/01/17 10:00:59 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(int key, t_fdf *data)
{
	if (key == KEY_PLUS || key == L_PLUS)
		data->zm.zoom++;
	else if (key == KEY_MINUS || key == L_MINUS)
		data->zm.zoom--;
	if (data->zm.zoom < 1)
		data->zm.zoom = 1;
	ft_draw(data);
}

void	ft_move(int key, t_fdf *data)
{
	if (key == LEFT || key == L_LEFT)
		data->zm.x -= 10;
	else if (key == RIGHT || key == L_RIGHT)
		data->zm.x += 10;
	else if (key == UP || key == L_UP)
		data->zm.y -= 10;
	else
		data->zm.y += 10;
	ft_draw(data);
}

void	ft_rotate(int key, t_fdf *data)
{
	if (key == KEY_W || key == L_W)
		data->zm.alpha -= 0.05;
	else if (key == KEY_S || key == L_S)
		data->zm.alpha += 0.05;
	else if (key == KEY_A || key == L_A)
		data->zm.beta -= 0.05;
	else if (key == KEY_D || key == L_D)
		data->zm.beta += 0.05;
	else if (key == KEY_Q || key == L_Q)
		data->zm.gamma += 0.05;
	else if (key == KEY_E || key == L_E)
		data->zm.gamma -= 0.05;
	ft_draw(data);
}

void	ft_flat(int key, t_fdf *data)
{
	if (key == KEY_LESS || key == L_LESS)
		data->zm.z += 0.1;
	else if (key == KEY_MORE)
		data->zm.z -= 0.1;
	if (data->zm.z < 0.3)
		data->zm.z = 0.3;
	else if (data->zm.z > 10)
		data->zm.z = 10;
	ft_draw(data);
}

void	ft_change(int key, t_fdf *data)
{
	data->zm.alpha = 0;
	data->zm.beta = 0;
	if (key == KEY_I || key == L_I)
	{
		data->zm.projection = ISO;
		data->zm.gamma = -1;
	}
	else if (key == KEY_P || key == L_P)
	{
		data->zm.projection = PARALLEL;
		data->zm.gamma = 0;
	}
	ft_draw(data);
}
