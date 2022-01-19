/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:21:10 by leng-chu          #+#    #+#             */
/*   Updated: 2022/01/16 16:43:22 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define COLOR_CYAN		0x00FFFF
#define COLOR_BLUE		0x0000FF
#define COLOR_RED		0xFF0000
#define COLOR_GREEN		0x00FF00
#define COLOR_PURPLE	0x7F00FF

//unsigned long	rgbtohex(int r, int g, int b)
//{
//	r = (r & 0xff) << 16;
//	g = (g & 0xff) << 8;
//	b = b & 0xff;
//	return (r + g + b);
//}

//int	rgb_to_int(double r, double g, double b)
//{
//	int	color;
//
//	color = 0;
//	color |= (int)(b * 255);
//	color |= (int)(g * 255) << 8;
//	color |= (int)(r * 255) << 16;
//	return (color);
//}

// this is similar to my_mlx_pixel_put function for the object drawing
// but this is effect within the object's area, do not cross the menu's area
void	ft_write_pixel(t_fdf *data, int x, int y, int color)
{
	int	i;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT - MENU_H)
	{
		i = (x * data->bt / 8) + (y * data->by);
		data->addr[i] = color;
		data->addr[++i] = color >> 8;
		data->addr[++i] = color >> 16;
	}
}

// Check out Color Gradient Algorithm
static int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

// This function is setting a color gradient. 
int	get_color(int z, t_fdf *data)
{
	double	percentage;

	percentage = percent(data->min, data->max, z);
	if (percentage < 0.2)
		return (COLOR_CYAN);
	else if (percentage < 0.4)
		return (COLOR_BLUE);
	else if (percentage < 0.6)
		return (COLOR_RED);
	else if (percentage < 0.8)
		return (COLOR_GREEN);
	else
		return (COLOR_PURPLE);
}

// This function is giving a color code to paint
int	ft_color(t_coord current, t_coord start, t_coord end, t_coord delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	red = get_light((start.color >> 16) & 0xFF,
			(end.color >> 16) & 0xFF, percentage);
	green = get_light((start.color >> 8) & 0xFF,
			(end.color >> 8) & 0xFF, percentage);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

// Drawing an object however it can even draw on the menu's area.
// So i dont use this function because it draws on the menu's area. 
void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->by + x * (data->bt / 8));
	*(unsigned int *)dst = color;
}
