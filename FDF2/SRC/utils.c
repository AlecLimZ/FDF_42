/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:46:29 by leng-chu          #+#    #+#             */
/*   Updated: 2021/12/30 17:07:21 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_isspace(int c)
{
	return (c == '\t'
			|| c == '\n'
			|| c == '\v'
			|| c == '\f'
			|| c == '\r'
			|| c == ' ');
}

static int	ft_isdigit_base(char c, int base)
{
	const char	*digits = "0123456789ABCDEF";
	int			i;

	i = 0;
	while (i < base)
	{
		if (digits[i] == ft_toupper(c))
			return (i);
		i++;
	}
	return (-1);
}

static	t_bool	ft_has_prefix(const char *str, int base)
{
	size_t	i;

	i = 0;
	if (base == 2 || base == 8 || base == 16)
	{
		if (str[i++] != '0')
			return (false);
		if (base == 2 && (str[i] == 'b' || str[i] == 'B'))
			return (true);
		if (base == 16 && (str[i] == 'x' || str[i] == 'X'))
			return (true);
		if (base == 8)
			return (true);
	}
	return (false);
}

t_bool	ft_isnumber(char *str, int base)
{
	size_t	i;
	size_t	digits;

	i = 0;
	digits = 0;
	while (ft_isspace(str[i]))
		i++;
	if (base != 10 && !ft_has_prefix(&str[i], base))
		return (false);
	if (base == 2 || base == 16)
		i += 2;
	else if (base == 8)
		i++;
	else if (base == 10 && (str[i] == '-' || str[i] == '+'))
		i++;
	while (ft_isdigit_base(str[i], base) >= 0)
	{
		i++;
		digits++;
	}
	if (!str[i] && digits)
		return (true);
	else
		return (false);
}

int	ft_atoi_base(const char *str, int base)
{
	unsigned long	result;
	size_t			i;
	int				sign;

	result = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (base != 10 && !ft_has_prefix(&str[i], base))
		return (false);
	if (base == 2 || base == 16)
		i += 2;
	else if (base == 8)
		i++;
	else if (base == 10 && (str[i] == '-' || str[i] == '+'))
		sign = (str[i++] == '-') ? -1 : 1;
	while (ft_isdigit_base(str[i], base) >= 0)
		result = result * base + ft_isdigit_base(str[i++], base);
	return ((int)(result * sign));
}