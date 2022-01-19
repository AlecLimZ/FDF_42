/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:41:58 by leng-chu          #+#    #+#             */
/*   Updated: 2022/01/17 10:18:32 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// this animate function works well on my linux***
//static void	ft_animate(t_fdf *data)
//{
//	int	active;
//	int	flat;
//
//	active = 0;
//	flat = 0;
//	while (active < 42)
//	{
//		data->zm.alpha -= 0.02;
//		data->zm.beta -= 0.02;
//		data->zm.gamma -= 0.02;
//		if (flat == 0)
//			data->zm.z -= 0.01;
//		else
//			data->zm.z += 0.01;
//		if (data->zm.z < 0.5)
//			flat = 1;
//		else if (data->zm.z > 3)
//			flat = 0;
//		ft_draw(data);
//		active++;
//	}
//}

// The function above didnt work well on 42kl Macos so i recode
// this as manual animate function... 
static void	ft_animate(t_fdf *data)
{
	int	i;

	i = 0;
	while (i++ < 4)
	{
		if (data->zm.z < 0.5)
			data->zm.z += 0.01;
		else if (data->zm.z > 2.5)
			data->zm.z -= 0.01;
		data->zm.alpha -= 0.02;
		data->zm.beta -= 0.02;
		data->zm.gamma -= 0.02;
		ft_draw(data);
	}
}

// this function contains all menu botton for both linux & mac
// except linux's ">" code.
// Macos = KEY_XX
// Linux = L_XX
int	ft_keyboard(int key, t_fdf *data)
{
	if (!data)
		return (0);
	if (key == ESC || key == L_ESC)
		exit(0);
	if (key == KEY_PLUS || key == KEY_MINUS || key == L_PLUS || key == L_MINUS)
		ft_zoom(key, data);
	else if (key == UP || key == DOWN || key == LEFT || key == RIGHT
		|| key == L_UP || key == L_DOWN || key == L_LEFT || key == L_RIGHT)
		ft_move(key, data);
	else if (key == KEY_A || key == KEY_D || key == KEY_W
		|| key == KEY_S || key == KEY_Q || key == KEY_E
		|| key == L_A || key == L_D || key == L_W
		|| key == L_S || key == L_Q || key == L_E)
		ft_rotate(key, data);
	else if (key == KEY_LESS || key == KEY_MORE
		|| key == L_LESS)
		ft_flat(key, data);
	else if (key == KEY_P || key == KEY_I || key == L_P || key == L_I)
		ft_change(key, data);
	else if (key == KEY_M || key == L_M)
		ft_animate(data);
	return (0);
}
