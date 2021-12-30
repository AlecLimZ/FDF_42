/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:06:49 by leng-chu          #+#    #+#             */
/*   Updated: 2021/12/30 17:07:50 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	push(t_coord_val **coords_stack, t_coord_val *new)
{
	if (coords_stack)
	{
		if (new)
			new->next = *coords_stack;
		*coords_stack = new;
	}
}

t_coord_val *pop(t_coord_val **coords_stack)
{
	t_coord_val *top;

	top = NULL;
	if (coords_stack && *coords_stack)
	{
		top = *coords_stack;
		*coords_stack = (*coords_stack)->next;
	}
	return (top);
}
