/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getwidth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:46:12 by leng-chu          #+#    #+#             */
/*   Updated: 2021/12/03 14:03:31 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_wdcounter(char *s, char c)
{
	char	**new;
	int		i;

	new = ft_split(s, c);
	i = 0;
	while (new[i])
		free(new[i++]);
	free(new);
	return (i);
}
