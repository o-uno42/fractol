/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiorgi <pgiorgi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:33:45 by pgiorgi           #+#    #+#             */
/*   Updated: 2024/05/16 16:33:32 by pgiorgi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_draw(t_fractal *fractal, t_draw draw)
{
	int	i;
	int	j;

	if (fractal->mlx_window == NULL)
		return (1);
	i = draw.y;
	while (i < draw.y + draw.height)
	{
		j = draw.x;
		while (j < draw.x + draw.width)
			mlx_pixel_put(fractal->mlx_ptr, fractal->mlx_window, \
				j++, i, draw.color);
		++i;
	}
	return (0);
}

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = 0;
	offset += (y * img->line_len) + (x *(img->bpp / 8));
	*(unsigned int *)(img->pix_ptr + offset) = color;
}

int	psyche_color(int i, int iterations, t_fractal *fractal)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)i + fractal->color / (double)iterations;
	r = (int)(4 * (1 - t) * t * t * t * 255);
	g = (int)(4 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(4 * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}
