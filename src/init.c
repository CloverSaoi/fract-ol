/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddutta <ddutta@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:44:39 by ddutta            #+#    #+#             */
/*   Updated: 2023/10/25 16:20:45 by ddutta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	data_init(t_fractol *fractol)
{
	fractol->escape_value = 4;
	fractol->iteration_def = 42;
	fractol->shift_x = 0.0;
	fractol->shift_y = 0.0;
	fractol->zoom = 1;
}

static void	events_init(t_fractol *fractol)
{
	mlx_hook(fractol->mlx_window, 2, 0, keys_handler, fractol);
	mlx_hook(fractol->mlx_window, 4, 0, mouse_handler, fractol);
	mlx_hook(fractol->mlx_window, 17, 0, close_handler, fractol);
}

static void	malloc_error(void)
{
	perror("Problem with malloc!");
	exit(EXIT_FAILURE);
}

void	fractol_init(t_fractol *fractol)
{
	fractol->mlx_connection = mlx_init();
	if (NULL == fractol->mlx_connection)
		malloc_error();
	fractol->mlx_window = mlx_new_window(fractol->mlx_connection,
			WIDTH, HEIGHT, fractol->name);
	if (fractol->mlx_window == NULL)
	{
		malloc_error();
	}
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_connection,
			WIDTH, HEIGHT);
	if (fractol->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
		malloc_error();
	}
	fractol->img.pixels_ptr = mlx_get_data_addr(fractol->img.img_ptr,
			&fractol->img.bpp, &fractol->img.line_len, &fractol->img.endian);
	events_init(fractol);
	data_init(fractol);
}
