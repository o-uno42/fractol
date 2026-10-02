/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiorgi <pgiorgi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:33:45 by pgiorgi           #+#    #+#             */
/*   Updated: 2024/05/16 16:40:33 by pgiorgi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_pixel_mandelbrot(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = -1;
	z.x = 0;
	z.y = 0;
	c.x = (scale(x, -2, 0, (fractal->width)) * \
		fractal->zoom) + fractal->shift_x;
	c.y = (scale(y, 2, 0, (fractal->height)) * \
		fractal->zoom) + fractal->shift_y;
	while (++i < fractal->iterations)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			color = psyche_color(i, fractal->iterations, fractal);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
	}
	my_pixel_put(x, y, &fractal->img, BLACK);
}

t_complex	square_complex2(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = -2 * z.x * z.y;
	return (result);
}

void	handle_pixel_tricorn(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = -1;
	z.x = 0;
	z.y = 0;
	c.x = (scale(x, -2, 0, (fractal->width)) * \
		fractal->zoom) + fractal->shift_x;
	c.y = (scale(y, 2, 0, (fractal->height)) * \
		fractal->zoom) + fractal->shift_y;
	while (++i < fractal->iterations)
	{
		z = sum_complex(square_complex2(z), c);
		if ((z.x * z.x) * (z.y * z.y) > 4)
		{
			color = psyche_color(i, fractal->iterations, fractal);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
	}
	my_pixel_put(x, y, &fractal->img, BLACK);
}
