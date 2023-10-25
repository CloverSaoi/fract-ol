/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddutta <ddutta@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:53:10 by ddutta            #+#    #+#             */
/*   Updated: 2023/10/25 17:32:38 by ddutta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_connection, fractol->img.img_ptr);
	mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
	exit(EXIT_SUCCESS);
	return (0);
}

int	keys_handler(int keycode, t_fractol *fractol)
{
	if (keycode == ESC)
		close_handler(fractol);
	else if (keycode == UP)
		fractol->shift_y += 0.5 * fractol->zoom;
	else if (keycode == DOWN)
		fractol->shift_y -= 0.5 * fractol->zoom;
	else if (keycode == LEFT)
		fractol->shift_x -= 0.5 * fractol->zoom;
	else if (keycode == RIGHT)
		fractol->shift_x += 0.5 * fractol->zoom;
	else if (keycode == PLUS)
		fractol->iteration_def += 10;
	else if (keycode == LESS)
		fractol->iteration_def -= 10;
	fractol_render(fractol);
	return (0);
}

int	mouse_handler(int mousecode, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (mousecode == Z_I)
		fractol->zoom *= 1.05;
	else if (mousecode == Z_O)
		fractol->zoom *= 0.95;
	fractol_render(fractol);
	return (0);
}
