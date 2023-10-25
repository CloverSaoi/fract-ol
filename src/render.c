/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddutta <ddutta@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 00:44:55 by ddutta            #+#    #+#             */
/*   Updated: 2023/10/25 17:30:35 by ddutta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_mvj(t_complex *z, t_complex *c, t_fractol *fractol)
{
	if (!(ft_strncmp(fractol->name, "julia", 5)))
	{
		c->r = fractol->jr;
		c->i = fractol->ji;
	}
	else
	{
		c->r = z->r;
		c->i = z->i;
	}
}

static void	my_pixel_put(int x, int y, t_img *img, int colour)
{
	int	offset;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = colour;
}

static void	handle_pixel(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			colour;

	i = 0;
	z.r = ft_scale(x, -2, +2, WIDTH) * fractol->zoom + fractol->shift_x;
	z.i = ft_scale(y, +2, -2, HEIGHT) * fractol->zoom + fractol->shift_y;
	ft_mvj(&z, &c, fractol);
	while (i < fractol->iteration_def)
	{
		calculate_complex(&z);
		z.r += c.r;
		z.i += c.i;
		if ((z.r * z.r) + (z.i * z.i) > fractol->escape_value)
		{
			colour = ft_scale(i, BLACK, MAGENTA_BURST, fractol->iteration_def);
			my_pixel_put(x, y, &fractol->img, colour);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractol->img, WHITE);
}

void	fractol_render(t_fractol *fractol)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractol);
		}
	}
	mlx_put_image_to_window(fractol->mlx_connection,
		fractol->mlx_window, fractol->img.img_ptr, 0, 0);
}
