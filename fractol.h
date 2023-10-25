/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddutta <ddutta@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:18:59 by ddutta            #+#    #+#             */
/*   Updated: 2023/10/25 17:18:55 by ddutta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// includes
# include "minilibx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <stddef.h>
// definitions of values
# define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\""
# define ERROR_MESSAGE2 "./fractol julia <real_value> <imaginary_value>\"\n"
# define WIDTH	800
# define HEIGHT	800

// colours
# define BLACK       0x000000  // RGB(0, 0, 0)
# define WHITE       0xFFFFFF  // RGB(255, 255, 255)
# define RED         0xFF0000  // RGB(255, 0, 0)
# define GREEN       0x00FF00  // RGB(0, 255, 0)
# define BLUE        0x0000FF  // RGB(0, 0, 255)
# define YELLOW  	0xFFFF00

// Psychedelic colors
# define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
# define LIME_SHOCK      0xCCFF00  // A blinding lime
# define NEON_ORANGE     0xFF6600  // A blazing neon orange
# define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
# define AQUA_DREAM      0x33CCCC  // A bright turquoise
# define HOT_PINK        0xFF66B2  // As the name suggests!
# define ELECTRIC_BLUE   0x0066FF  // A radiant blue
# define LAVA_RED        0xFF3300  // A bright, molten red

//keys
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define PLUS 35
# define LESS 37
# define Z_I 5
# define Z_O 4

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_fractol
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iteration_def;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	jr;
	double	ji;
}			t_fractol;

typedef struct s_complex
{
	double	r;
	double	i;
}t_complex;
// string utils
void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
double	ft_atod(char *s);
// init
void	fractol_init(t_fractol *fractol);
// render
void	fractol_render(t_fractol *fractol);
//misc. utils
double	ft_scale(double unscaledNum, double minAllowed,
			double maxAllowed, double org_max);
void	calculate_complex(t_complex *comp);
//hooks
int		keys_handler(int keycode, t_fractol *fractol);
int		mouse_handler(int mousecode, int x, int y, t_fractol *fractol);
int		close_handler(t_fractol *fractol);
#endif
