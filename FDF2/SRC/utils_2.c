/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 14:06:46 by leng-chu          #+#    #+#             */
/*   Updated: 2021/12/30 16:20:45 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

void	terminate(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}

int	get_index(int x, int y, int width)
{
	return (y * width + x);
}

t_point	new_point(int x, int y, t_map *map)
{
	t_point	point;
	int		index;

	index = get_index(x, y, map->width);
	point.x = x;
	point.y = y;
	point.z = map->coords_arr[index];
	point.color = (map->colors_arr[index] == -1) ? get_default_color(point.z, map) : map->colors_arr[index];
	return (point);
}
