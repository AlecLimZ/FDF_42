/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:53:36 by leng-chu          #+#    #+#             */
/*   Updated: 2022/01/17 10:33:55 by leng-chu         ###   ########.fr       */
/*   Updated: 2021/12/07 11:44:18 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../../mlx_mms_20191025/mlx.h"
# include "../../mlx_linux/mlx.h"
# include "../../minilibx_macos/mlx.h"
# include "get_next_line.h"
# include "macos_key.h"
# include "linux_key.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include <limits.h>

# define WIDTH		1200
# define HEIGHT		1000
# define MENU_H		150

# define TEXT_COLOR	0xEAEAEA
# define MAP_BG		0x222222
# define MENU_BG	0x073763

// coordination for x, y & z
typedef struct s_coord
{
	int		x;
	int		y;
	int		z;
	int		color;
}	t_coord;

// project view type
typedef enum s_projection
{
	ISO,
	PARALLEL
}	t_projection;

//zoom setting
typedef struct s_zoom
{
	int				zoom;
	double			alpha;
	double			beta;
	double			gamma;
	float			z;
	int				x;
	int				y;
	t_projection	projection;
}	t_zoom;

/*
 * bt = bits_per_pixel
 * by = line_length
 * en = endian
 */

typedef struct s_fdf
{
	int		width;
	int		height;
	int		*matrix;
	int		pos_m;
	int		*color_mx;
	int		pos_c;
	int		max;
	int		min;
	int		range;
	int		bt;
	int		by;
	int		en;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	t_coord	crd;
	t_zoom	zm;
}	t_fdf;

//inside ft_color.c
void			my_mlx_pixel_put(t_fdf *data, int x, int y, int color);
int				get_color(int z, t_fdf *data);
void			ft_write_pixel(t_fdf *data, int x, int y, int color);
int				ft_color(t_coord current, t_coord start,
					t_coord end, t_coord delta);

//inside read_map.c
void			read_file(char *file_name, t_fdf *data);
void			fill_matrix(t_fdf *data, char **w_line);

//inside ft_getwidth.c
int				ft_wdcounter(char *s, char c);

//inside draw.c
void			ft_bresenham(t_coord f, t_coord s, t_fdf *data);
void			ft_draw(t_fdf *data);

//inside project.c
t_coord			project(t_coord p, t_fdf *data);

//inside menu.c
void			ft_menu(t_fdf *data);

//inside keyboard_control.c
int				ft_keyboard(int key, t_fdf *data);

//inside control.c
void			ft_zoom(int key, t_fdf *data);
void			ft_move(int key, t_fdf *data);
void			ft_rotate(int key, t_fdf *data);
void			ft_flat(int key, t_fdf *data);
void			ft_change(int key, t_fdf *data);

//inside functions.c
int				ft_isspace(int c);
int				ft_isnum(char *s, int base);
int				ft_atoi_base(const char *s, int base);

//inside functions_2.c
int				ft_ismap(char *s);
void			ft_errorexit(char *s);
t_coord			new_coord(int x, int y, t_fdf *data);
double			percent(int start, int end, int current);

#endif
