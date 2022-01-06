/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:12:57 by leng-chu          #+#    #+#             */
/*   Updated: 2022/01/06 16:17:32 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "error_message.h"

void	stack_to_arrays(t_coord_val **coords_stack, t_map *map)
{
	t_coord_val	*coord;
	ssize_t		i;
	size_t		arr_size;

	arr_size = map->width * map->height * sizeof(int);
	map->coords_arr = (int *)ft_memalloc(arr_size);
	map->colors_arr = (int *)ft_memalloc(arr_size);
	if (!map->coords_arr || !map->colors_arr)
		terminate(ERR_CONV_TO_ARR);
	i = map->width * map->height - 1;
	coord = pop(coords_stack);
	while (coord && i >= 0)
	{
		map->coords_arr[i] = coord->z;
		map->colors_arr[i] = coord->color;
		if (coord->z > map->z_max)
			map->z_max = coord->z;
		if (coord->z < map->z_min)
			map->z_min = coord->z;
		i--;
		free(coord);
		coord = pop(coords_stack);
	}
	free(coord);
	map->z_range = map->z_max - map->z_min;
}
