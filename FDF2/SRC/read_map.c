/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:52:23 by leng-chu          #+#    #+#             */
/*   Updated: 2021/12/31 16:34:23 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "error_message.h"

void	ft_strdel(char **as)
{
	if (as && *as)
	{
		free(*as);
		*as = NULL;
	}
}

static void	free_strsplit_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static t_coord_val	*new_coord(char *s)
{
	t_coord_val	*coord;
	char		**parts;

	coord = (t_coord_val *)ft_memalloc(sizeof(t_coord_val));
	parts = ft_split(s, ',');
	if (!coord || !parts || !ft_isnumber(parts[0], 10))
		terminate(ERR_MAP_READING);
	if (parts[1] && !ft_isnumber(parts[1], 16))
		terminate(ERR_MAP_READING);
	coord->z = ft_atoi(parts[0]);
	if (parts[1])
		coord->color = ft_atoi_base(parts[1], 16);
	else
		coord->color = -1;
	coord->next = NULL;
	free_strsplit_arr(parts);
	return (coord);
}

static void	parse_line(char **coords_line,
		t_coord_val **coords_stack, t_map *map)
{
	int	width;

	width = 0;
	while (*coords_line)
	{
		push(coords_stack, new_coord(*(coords_line++)));
		width++;
	}
	if (map->height == 0)
		map->width = width;
	else if (map->width != width)
		terminate(ERR_MAP);
}

int	read_map(const int fd, t_coord_val **coords_stack, t_map *map)
{
	char	*line;
	int		result;
	char	**coords_line;

	result = get_next_line(fd, &line);
	while (result == 1)
	{
		coords_line = ft_split(line, ' ');
		if (!coords_line)
			terminate(ERR_MAP_READING);
		parse_line(coords_line, coords_stack, map);
		free_strsplit_arr(coords_line);
		ft_strdel(&line);
		map->height++;
		result = get_next_line(fd, &line);
	}
	if (!(*coords_stack))
		terminate(ERR_MAP);
	return (result);
}
