/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:04:32 by leng-chu          #+#    #+#             */
/*   Updated: 2022/01/17 10:35:10 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* this function is to free a line variable from GNL 
 * as GNL is using malloc
 */
static void	ft_freeline(char *line)
{
	free(line);
	line = NULL;
}

/* this function is to free variable which used ft_split 
 * as ft_split is using malloc
 */
static void	ft_freesplit(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

/* this function to fill the coordination and 
 * the hex(if hex is available on both matrix & color matrix)
 */
void	fill_matrix(t_fdf *data, char **w_line)
{
	char	**nums;
	int		j;

	j = 0;
	while (w_line[j])
	{
		nums = ft_split(w_line[j], ',');
		if (!nums || !ft_isnum(nums[0], 10))
			ft_errorexit("Error: Incorrect decimal\n");
		if (nums[1] && !ft_isnum(nums[1], 16))
			ft_errorexit("Error: Incorrect hex\n");
		data->matrix[data->pos_m++] = ft_atoi(nums[0]);
		if (ft_atoi(nums[0]) > data->max)
			data->max = ft_atoi(nums[0]);
		if (ft_atoi(nums[0]) < data->min)
			data->min = ft_atoi(nums[0]);
		if (nums[1])
			data->color_mx[data->pos_c++] = ft_atoi_base(nums[1], 16);
		else
			data->color_mx[data->pos_c++] = -1;
		ft_freesplit(nums);
		j++;
	}
}

// this function is to get a map's height size & width size
static void	get_hw(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0 || !ft_ismap(file_name))
		ft_errorexit("Error: Map does not exist\n");
	i = 0;
	line = NULL;
	while (get_next_line(fd, &line))
	{
		data->width = ft_wdcounter(line, ' ');
		ft_freeline(line);
		data->height++;
		i++;
	}
	ft_freeline(line);
	close(fd);
}

/* Read input from the fdf map file to fill 
 * both matrix and color_mx.
 *
 * Color_mx is mainly created to store a hex 
 * from a map for a coordination if that map's input
 * does contain a hex, otherwise will get default color by mine. 
 */
void	read_file(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	char	**w_line;
	int		total;

	get_hw(file_name, data);
	total = data->height * data->width + 1;
	fd = open(file_name, O_RDONLY, 0);
	data->matrix = (int *)malloc(sizeof(int) * total);
	data->color_mx = (int *)malloc(sizeof(int) * total);
	if (!data->matrix || !data->color_mx)
		ft_errorexit("Error: Malloc\n");
	while (get_next_line(fd, &line))
	{
		if (data->width != ft_wdcounter(line, ' '))
			ft_errorexit("Error: Width not same\n");
		w_line = ft_split(line, ' ');
		fill_matrix(data, w_line);
		ft_freesplit(w_line);
		ft_freeline(line);
	}
	ft_freeline(line);
	close(fd);
	data->range = data->max - data->min;
}
