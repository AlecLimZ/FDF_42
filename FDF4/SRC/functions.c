/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:44:20 by leng-chu          #+#    #+#             */
/*   Updated: 2022/01/16 15:55:20 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// this function is check all possible space types
int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

/* This function is checking if a letter is 
 * decimal or hex. Otherwise, return false
*/
static int	ft_isdigitletter(char c, int base)
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

/*
 * This function is check whether a number is type base 2,
 * base 8 or base 16. If none match then return false
 */
static int	ft_prefix(const char *str, int base)
{
	int	i;

	i = 0;
	if (base == 2 || base == 8 || base == 16)
	{
		if (str[i++] != '0')
			return (0);
		if (base == 2 && (str[i] == 'b' || str[i] == 'B'))
			return (1);
		if (base == 16 && (str[i] == 'x' || str[i] == 'X'))
			return (1);
		if (base == 8)
			return (1);
	}
	return (0);
}

/*
 * This function is simply checking whether 
 * it is number(all base types) or not
 */
int	ft_isnum(char *s, int base)
{
	int	i;
	int	digits;

	i = 0;
	digits = 0;
	while (ft_isspace(s[i]))
		i++;
	if (base != 10 && !ft_prefix(&s[i], base))
		return (0);
	if (base == 2 || base == 16)
		i += 2;
	else if (base == 8)
		i++;
	else if (base == 10 && (s[i] == '-' || s[i] == '+'))
		i++;
	while (ft_isdigitletter(s[i], base) >= 0)
	{
		i++;
		digits++;
	}
	if (!s[i] && digits)
		return (1);
	else
		return (0);
}

/*
 * it is similar to ft_atoi which can do decimal only
 * while it can do other base beside decimal (base 10)
 */
int	ft_atoi_base(const char *s, int base)
{
	unsigned long	result;
	int				i;
	int				sign;

	result = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(s[i]))
		i++;
	if (base != 10 && !ft_prefix(&s[i], base))
		return (0);
	if (base == 2 || base == 16)
		i += 2;
	else if (base == 8)
		i++;
	else if (base == 10 && (s[i] == '-' || s[i] == '+'))
	{
		if (s[i++] == '-')
			sign = -1;
		else
			sign = 1;
	}
	while (ft_isdigitletter(s[i], base) >= 0)
		result = result * base + ft_isdigitletter(s[i++], base);
	return ((int)(result * sign));
}
