/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiorgi <pgiorgi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:33:45 by pgiorgi           #+#    #+#             */
/*   Updated: 2024/05/16 17:21:59 by pgiorgi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

int	render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y <= fractal->height)
	{
		x = 0;
		while (x <= fractal->width)
		{
			if (ft_strncmp(fractal->name, "mandelbrot", 10) == 0 || \
			ft_strncmp(fractal->name, "Mandelbrot", 10) == 0)
				handle_pixel_mandelbrot(x, y, fractal);
			else if (ft_strncmp(fractal->name, "julia", 5) == 0 || \
				ft_strncmp(fractal->name, "Julia", 5) == 0)
				handle_pixel_julia(x, y, fractal);
			else if (ft_strncmp(fractal->name, "tricorn", 7) == 0 || \
				ft_strncmp(fractal->name, "Tricorn", 7) == 0)
				handle_pixel_tricorn(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->mlx_window, \
		fractal->img.img_ptr, 0, 0);
	return (0);
}

void	choose_fractal(char *str, t_fractal *fractal)
{
	if (ft_strncmp(str, "mandelbrot", 11) == 0 || \
		ft_strncmp(str, "Mandelbrot", 11) == 0)
		fractal->name = "mandelbrot";
	else if (ft_strncmp(str, "julia", 6) == 0 || \
		ft_strncmp(str, "Julia", 6) == 0)
		fractal->name = "julia";
	else if (ft_strncmp(str, "tricorn", 8) == 0 || \
		ft_strncmp(str, "Tricorn", 8) == 0)
		fractal->name = "tricorn";
	else
	{
		write (1, "Prova a scrivere *mandelbrot* o *julia* o *tricorn*\n", 52);
		exit (0);
	}
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;
	t_img		img;

	if (argc < 2)
		no_fractal();
	if ((ft_strncmp(argv[1], "julia", 6) == 0 || \
		ft_strncmp(argv[1], "Julia", 6) == 0) && argc > 2)
	{
		if (check_julia(argv[2], argv[3]) == 1)
			fractal_init2_julia(&fractal, argv[2], argv[3]);
		else
			wrong_parameters();
	}
	else
		fractal_init2(&fractal);
	ft_inits(&fractal, &img, argv[1]);
	if (ft_strncmp(argv[1], "julia", 6) == 0 || \
		ft_strncmp(argv[1], "Julia", 6) == 0)
		mlx_hook(fractal.mlx_window, 6, 1L << 6, julia_motion, &fractal);
	render(&fractal);
	mlx_hook(fractal.mlx_window, 2, 1L << 0, keys, &fractal);
	mlx_hook(fractal.mlx_window, 17, 1L << 2, esc_x, &fractal);
	mlx_mouse_hook(fractal.mlx_window, mouse_handler, &fractal);
	mlx_loop(fractal.mlx_ptr);
	return (0);
}
