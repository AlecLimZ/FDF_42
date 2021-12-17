/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:53:36 by leng-chu          #+#    #+#             */
/*   Updated: 2021/12/07 11:44:18 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx_mms_20191025/mlx.h"
# include "../mlx_linux/mlx.h"
# include "get_next_line.h"
# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_line
{
	float	x;
	float	y;
	float	x1;
	float	y1;
}	t_line;

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		zoom;
	int		color;
	int		addx;
	int		addy;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	void	*addr;
}	t_fdf;

typedef struct s_zoom
{
	float	x_step;
	float	y_step;
	float	zx;
	float	zy;
	float	zx1;
	float	zy1;
	int		max;
	int		c;
	int		c1;
}	t_zoom;

//inside ft_color.c
//Warning: rgb_to_hex returns memory located char *
unsigned long	rgbtohex(int r, int g, int b);
int				rgb_to_int(double r, double g, double b);
void			my_mlx_pixel_put(t_fdf *data, int x, int y, int color);

//inside read_map.c
int				get_height(char *file_name);
void			read_file(char *file_name, t_fdf *data);
int				get_width(char *file_name);
void			fill_matrix(int *z_line, char *line);

//inside ft_getwidth.c
int				ft_wdcounter(char *s, char c);

//inside draw.c
void			ft_bresenham(t_line *line, t_fdf *data);
void			draw_floor(t_line *line, t_fdf *data);

#endif
