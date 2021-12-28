/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:49:54 by leng-chu          #+#    #+#             */
/*   Updated: 2021/12/06 10:34:55 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SRC/fdf.h"

int	main(int argc, char **argv)
{
	int		count;
	int		fd;
	char	*line;

	count = 0;
	fd = 0;
	line = NULL;
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (0);
	while (get_next_line(fd, &line))
	{
		count++;
		free(line);
	}
	free(line);
	printf("count: %d\n", count);
	printf("width: %d\n", get_width(argv[1]));
	return (0);
}
