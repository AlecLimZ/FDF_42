/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:43:03 by leng-chu          #+#    #+#             */
/*   Updated: 2021/12/22 17:46:19 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_menu(t_dot param)
{
	char	*menu;

	menu = "up, down, left, right: move picture";
	mlx_string_put(param.mlx_ptr, param.win_ptr, 10, 5, 0x03fc35, menu);
	menu = "5, spase: 3d/2d mode; +, -: zoom";
	mlx_string_put(param.mlx_ptr, param.win_ptr, 10, 20, 0x03fc35, menu);
	menu = "8, 2: z-scale; 4, 6: rotation";
	mlx_string_put(param.mlx_ptr, param.win_ptr, 10, 35, 0x03fc35, menu);
	menu = "f: full screen mode";
	mlx_string_put(param.mlx_ptr, param.win_ptr, 10, 50, 0x03fc35, menu);
}
