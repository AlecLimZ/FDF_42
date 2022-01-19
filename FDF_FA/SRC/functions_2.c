/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:31:22 by leng-chu          #+#    #+#             */
/*   Updated: 2022/01/17 10:39:56 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 * This function returns the error message
 * and also terminate the program as well
 */
void	ft_errorexit(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}

// this function to check is an existing file the fdf type or not
int	ft_ismap(char *s)
{
	int	i;

	i = 0;
	i = ft_strlen(s);
	if (s[--i] == 'f')
		if (s[--i] == 'd')
			if (s[--i] == 'f')
				if (s[--i] == '.')
					return (1);
	return (0);
}

/*
 * this function formula is designed to 
 * support the color gradient
 */
double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	return (placement / distance);
}

// this function is give a coordination of the whole matrix
int	get_index(int x, int y, int width)
{
	return (y * width + x);
}

/*
 * this function is create new point struct 
 * for the matrix's coordination.
 *
 * And also assign a color based on the coordination given at same time.
 */
t_coord	new_coord(int x, int y, t_fdf *data)
{
	t_coord	coord;
	int		index;

	index = get_index(x, y, data->width);
	coord.x = x;
	coord.y = y;
	coord.z = data->matrix[index];
	if (data->color_mx[index] == -1)
		coord.color = get_color(coord.z, data);
	else
		coord.color = data->color_mx[index];
	return (coord);
}
