/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiorgi <pgiorgi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:09:09 by pgiorgi           #+#    #+#             */
/*   Updated: 2024/05/16 17:16:55 by pgiorgi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keys(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
	{
		write (1, "Hai chiuso il programma.\n", 25);
		mlx_destroy_window(fractal->mlx_ptr, fractal->mlx_window);
		fractal->mlx_window = (NULL);
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		exit(0);
	}
	else if (keysym == 32)
	{
		if (fractal->psyche == 0)
			fractal->psyche += 1;
		fractal->color += 1;
	}
	else if (keysym == XK_Right)
		fractal->shift_x += 0.08 * fractal->zoom;
	else if (keysym == XK_Left)
		fractal->shift_x -= 0.08 * fractal->zoom;
	else if (keysym == XK_Up)
		fractal->shift_y += 0.08 * fractal->zoom;
	else if (keysym == XK_Down)
		fractal->shift_y -= 0.08 * fractal->zoom;
	render(fractal);
	return (0);
}

int	esc_x(t_fractal *fractal)
{
	write (1, "Hai chiuso il programma.\n", 25);
	mlx_destroy_window(fractal->mlx_ptr, fractal->mlx_window);
	fractal->mlx_window = (NULL);
	mlx_destroy_display(fractal->mlx_ptr);
	free(fractal->mlx_ptr);
	exit (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	fractal->shift_x += ((scale(x, -2, 0, fractal->width)) * fractal->zoom);
	fractal->shift_y += ((scale(y, 2, 0, fractal->height)) * fractal->zoom);
	if (button == 4)
		fractal->zoom *= 0.7;
	else if (button == 5)
		fractal->zoom *= 1.3;
	render(fractal);
	return (0);
}
