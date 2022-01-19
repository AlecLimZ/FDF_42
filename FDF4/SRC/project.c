/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:53:37 by leng-chu          #+#    #+#             */
/*   Updated: 2022/01/16 17:06:04 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* This function is rotating with X
 * as center without change X's position
 */
static void	rotate_x(int *y, int *z, double alpha)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(alpha) + *z * sin(alpha);
	*z = -prev_y * sin(alpha) + *z * cos(alpha);
}

/* This function is rotating with Y 
 * as center without change Y's position
 */
static void	rotate_y(int *x, int *z, double beta)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(beta) + *z * sin(beta);
	*z = -prev_x * sin(beta) + *z * cos(beta);
}

/* This function is rotating with Z 
 * as center without change Z's position
 */
static void	rotate_z(int *x, int *y, double gamma)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(gamma) - prev_y * sin(gamma);
	*y = prev_x * sin(gamma) + prev_y * cos(gamma);
}

// this function is basically isometric formula
static void	iso(int *x, int *y, int z)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.523599);
	*y = -z + (prev_x + prev_y) * sin(0.523599);
}

/* This project is setting a point's x,y & z 
 * coordination and the object's position before draw
 *
 * Check out the Euler Angles for rotation formula
 * Alpha symbol - α 
 * Beta symbol - β
 * Gamma symbol - γ
 */
t_coord	project(t_coord p, t_fdf *data)
{
	p.x *= data->zm.zoom;
	p.y *= data->zm.zoom;
	p.z *= data->zm.zoom / data->zm.z;
	p.x -= (data->width * data->zm.zoom) / 2;
	p.y -= (data->height * data->zm.zoom) / 2;
	rotate_x(&p.y, &p.z, data->zm.alpha);
	rotate_y(&p.x, &p.z, data->zm.beta);
	rotate_z(&p.x, &p.y, data->zm.gamma);
	if (data->zm.projection != 1)
		iso(&p.x, &p.y, p.z);
	p.x += WIDTH / 2 + data->zm.x;
	p.y += ((HEIGHT - MENU_H) + data->height * data->zm.zoom) / 3 + data->zm.y;
	return (p);
}
