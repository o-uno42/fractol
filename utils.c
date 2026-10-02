/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiorgi <pgiorgi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:33:45 by pgiorgi           #+#    #+#             */
/*   Updated: 2024/05/16 16:56:42 by pgiorgi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_init(t_img *img)
{
	img->img_ptr = mlx_init();
	if (!img->img_ptr)
		print_error();
	img->color_offset = 0;
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (!fractal->mlx_ptr)
		print_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_ptr, \
		fractal->width, fractal->height, "Fractol");
	if (!fractal->mlx_window)
	{
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		print_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_ptr, \
		fractal->width, fractal->height);
	if (!fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_ptr, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		print_error();
	}
	fractal->img.pix_ptr = mlx_get_data_addr(fractal->img.img_ptr, \
		&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
}

void	fractal_init_julia(t_fractal *fractal, char *s1, char *s2)
{
	double	point1;
	double	point2;

	point1 = ft_atoi_float(s1);
	point2 = ft_atoi_float(s2);
	if (point1 >= 0 && point1 <= 2 && point2 >= 0 && point2 <= 2)
	{
		fractal->julia.julia_cx = point1;
		fractal->julia.julia_cy = point2;
	}
	else
	{
		fractal->julia.julia_cx = 1;
		fractal->julia.julia_cy = 1;
	}
	fractal->julia.julia_x = 0;
	fractal->julia.julia_y = 0;
	fractal->julia.julia_rotation = 30;
}

void	fractal_init2_julia(t_fractal *fractal, char *s1, char *s2)
{
	fractal->width = 1080;
	fractal->height = 1080;
	fractal->iterations = 40;
	fractal->zoom = 1;
	fractal->shift_x = 0;
	fractal->shift_y = 0;
	fractal->shift_x = 0;
	fractal->shift_y = 0;
	fractal->proportion = 1;
	fractal->color = 1;
	fractal->psyche = 0;
	fractal_init_julia(fractal, s1, s2);
}

void	fractal_init2(t_fractal *fractal)
{
	fractal->width = 1080;
	fractal->height = 1080;
	fractal->iterations = 40;
	fractal->zoom = 1;
	fractal->shiftzoom = 1;
	fractal->shift_x = 0;
	fractal->shift_y = 0;
	fractal->shift_x = 0;
	fractal->shift_y = 0;
	fractal->julia.julia_cx = 1;
	fractal->julia.julia_cy = 1;
	fractal->julia.julia_x = 0;
	fractal->julia.julia_y = 0;
	fractal->julia.julia_rotation = 30;
	fractal->proportion = 1;
	fractal->color = 1;
	fractal->psyche = 0;
}
