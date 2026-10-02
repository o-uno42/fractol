/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiorgi <pgiorgi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:30:04 by pgiorgi           #+#    #+#             */
/*   Updated: 2024/05/14 17:55:40 by pgiorgi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atoi_float(const char *nptr)
{
	int		i;
	double	s;
	double	res;

	i = 0;
	s = 1;
	while (nptr[i])
	{
		if (!(nptr[i] >= '0' && nptr[i] <= '9') && nptr[i] != '.')
			return (-1);
		i++;
	}
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s *= -1;
		i++;
	}
	res = ft_atoi_float2(nptr, i, s);
	return (res);
}

double	ft_atoi_float2(const char *nptr, int i, double s)
{
	double	num;
	double	num2;
	double	pos;

	num = 0;
	num2 = 0;
	pos = 1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num *= 10;
		num += (nptr[i] - 48);
		i++;
	}
	if (nptr[i] == '.')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num2 *= 10;
		num2 += (nptr[i] - 48);
		pos *= 10;
		i++;
	}
	return ((num + (num2 / pos)) * s);
}

double	scale(double unscaled_num, double parameter, \
	double old_min, double old_max)
{
	double	parameter2;

	parameter2 = -parameter;
	return ((parameter2 - parameter) * (unscaled_num) \
		/ (old_max - old_min) + parameter);
}

void	print_error(void)
{
	perror("Error");
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n <= 0)
		return (0);
	while (*s1 != '\0' && i < n - 1 && *s1 == *s2)
	{
		s1++;
		s2++;
		i++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
