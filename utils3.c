/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiorgi <pgiorgi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:44:25 by pgiorgi           #+#    #+#             */
/*   Updated: 2024/05/14 17:48:59 by pgiorgi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_julia(char *s1, char *s2)
{
	double	point1;
	double	point2;

	if (s1 == NULL || s2 == NULL)
		return (0);
	point1 = ft_atoi_float(s1);
	point2 = ft_atoi_float(s2);
	if (point1 >= 0 && point1 <= 2 && point2 >= 0 && point2 <= 2)
		return (1);
	else
		return (0);
}

void	ft_inits(t_fractal *fractal, t_img *img, char *argv)
{
	choose_fractal(argv, fractal);
	fractal_init(fractal);
	img_init(img);
}

int	wrong_parameters(void)
{
	write (1, "Inserisci dei parametri validi.\n", 33);
	exit (0);
}

int	no_fractal(void)
{
	write(1, "Indica il frattale:\nMandelbrot\nJulia\nTricorn\n", 46);
	exit (0);
}
