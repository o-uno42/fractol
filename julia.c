/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiorgi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:33:45 by pgiorgi           #+#    #+#             */
/*   Updated: 2024/03/20 13:06:51 by pgiorgi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_pixel_julia(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = ((scale(x, -2, 0, fractal->width) * \
		fractal->zoom) + fractal->shift_x);
	z.y = ((scale(y, 2, 0, fractal->height) * \
		fractal->zoom) + fractal->shift_y);
	c.x = fractal->julia.julia_cx;
	c.y = fractal->julia.julia_cy;
	while (i < fractal->iterations)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			color = psyche_color(i, fractal->iterations, fractal);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &fractal->img, BLACK);
}

int	julia_motion(int x, int y, t_fractal *fractal)
{
	fractal->julia.julia_cx = ((scale(x, -2, 0, fractal->width) * \
		fractal->zoom) + fractal->shift_x);
	fractal->julia.julia_cy = ((scale(y, 2, 0, fractal->height) * \
		fractal->zoom) + fractal->shift_y);
	render(fractal);
	return (0);
}
