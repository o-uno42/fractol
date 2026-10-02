/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiorgi <pgiorgi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:49:18 by pgiorgi           #+#    #+#             */
/*   Updated: 2024/05/16 16:55:14 by pgiorgi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define BLACK   0x000000

# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <limits.h>
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>

typedef struct s_img
{
	void	*img_ptr;
	char	*pix_ptr;
	int		bpp;
	int		endian;
	int		line_len;
	int		width;
	int		heigth;
	int		color_offset;
}	t_img;

typedef struct s_julia
{
	double	julia_cx;
	double	julia_cy;
	double	julia_rotation;
	double	julia_x;
	double	julia_y;
}	t_julia;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_ptr;
	void	*mlx_window;
	t_img	img;
	t_julia	julia;
	int		width;
	int		height;
	double	escape_value;
	double	iterations;
	double	zoom;
	double	cursor_zoom_x;
	double	cursor_zoom_y;
	double	shiftzoom;
	double	shift_x;
	double	shift_y;
	double	proportion;
	double	color;
	int		psyche;
}	t_fractal;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_draw
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_draw;

//WINDOW MANAGEMENT
int				keys(int keysym, t_fractal *fractal);
void			print_error(void);
int				esc_x(t_fractal *fractal);
int				wrong_parameters(void);
int				no_fractal(void);
void			ft_inits(t_fractal *fractal, t_img *img, char *argv);
void			img_init(t_img *img);
void			fractal_init2(t_fractal *fractal);
void			fractal_init2_julia(t_fractal *fractal, char *s1, char *s2);
int				mouse_handler(int button, int x, int y, t_fractal *fractal);
int				mouse_handler2(int button, int x, int y, t_fractal *fractal);
int				cursor_zoom(int button, int x, int y, t_fractal *fractal);

//COLORS
int				psyche_color(int i, int iterations, t_fractal *fractal);
int				ft_trgb(int t, int r, int g, int b);
int				create_trgb(unsigned char t, unsigned char r, \
	unsigned char g, unsigned char b);
unsigned char	get_t(int trgb);
unsigned char	get_r(int trgb);
unsigned char	get_g(int trgb);
unsigned char	get_b(int trgb);

//FRACTAL
void			fractal_init(t_fractal *fractal);
int				check_julia(char *s1, char *s2);
void			choose_fractal(char *str, t_fractal *fractal);
int				color_draw(t_fractal *fractal, t_draw draw);
double			scale(double unscaled_num, double parameter, \
	double old_min, double old_max);
t_complex		sum_complex(t_complex z1, t_complex z2);
t_complex		square_complex(t_complex z);
void			my_pixel_put(int x, int y, t_img *img, int color);
void			handle_pixel_julia(int x, int y, t_fractal *fractal);
void			handle_pixel_mandelbrot(int x, int y, t_fractal *fractal);
int				render(t_fractal *fractal);
int				julia_motion(int x, int y, t_fractal *fractal);
void			handle_pixel_tricorn(int x, int y, t_fractal *fractal);
double			ft_atoi_float(const char *nptr);
double			ft_atoi_float2(const char *nptr, int i, double s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
#endif
