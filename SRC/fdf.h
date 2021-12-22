/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:53:36 by leng-chu          #+#    #+#             */
/*   Updated: 2021/12/22 18:19:56 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef PRM
#  define PRM matrix[0][0]
# endif

# include "../mlx_mms_20191025/mlx.h"
# include "../mlx_linux/mlx.h"
# include "get_next_line.h"
# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# define MAX(A, B)(A > B ? A : B)

typedef struct s_dot
{
	float	x;
	float	y;
	float	z;
	int		is_last;
	int		color;
	int		scale;
	int		z_scale;
	int		shift_x;
	int		shift_y;
	int		is_isometric;
	double	angle;
	int		win_x;
	int		win_y;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_dot;

t_dot	**read_map(char *file_name);
void	isometric(t_dot *dot, double angle);
void	draw(t_dot **matrix);
int		deal_key(int key, t_dot **matrix);
void	set_param(t_dot *a, t_dot *b, t_dot *param);
void	print_menu(t_dot param);
void	ft_error(char *msg);
void	new_window(int key, t_dot **matrix);
int		ft_wdcounter(char const *str, char c);

#endif
