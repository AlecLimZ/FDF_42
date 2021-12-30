/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 19:14:35 by leng-chu          #+#    #+#             */
/*   Updated: 2021/12/30 15:44:29 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math.h"

static void	rotate_x(int *y, int *z, double alpha)
{
	int	previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

static void	rotate_y(int *x, int *z, double beta)
{
	int	previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
}

static void	rotate_z(int *x, int *y, double gamma)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
}

static void	iso(int *x, int *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

t_point	project(t_point p, t_fdf *fdf)
{
	p.x *= fdf->camera->zoom;
	p.y *= fdf->camera->zoom;
	p.z *= fdf->camera->zoom / fdf->camera->z_divisor;
	p.x -= (fdf->map->width * fdf->camera->zoom) / 2;
	p.y -= (fdf->map->height * fdf->camera->zoom) / 2;
	rotate_x(&p.y, &p.z, fdf->camera->alpha);
	rotate_y(&p.x, &p.z, fdf->camera->beta);
	rotate_z(&p.x, &p.y, fdf->camera->gamma);
	if (fdf->camera->projection == ISO)
		iso(&p.x, &p.y, p.z);
	p.x += (WIDTH - MENU_WIDTH) / 2 + fdf->camera->x_offset + MENU_WIDTH;
	p.y += (HEIGHT + fdf->map->height * fdf->camera->zoom) / 2
		+ fdf->camera->y_offset;
	return (p);
}
