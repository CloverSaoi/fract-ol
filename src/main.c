/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddutta <ddutta@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:28:57 by ddutta            #+#    #+#             */
/*   Updated: 2023/10/25 17:35:03 by ddutta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (((2 == argc) && !(ft_strncmp(argv[1], "mandelbrot", 10)))
		|| ((4 == argc) &&!(ft_strncmp(argv[1], "julia", 5))))
	{
		fractol.name = argv[1];
		if (!ft_strncmp(fractol.name, "julia", 5))
		{
			fractol.jr = ft_atod(argv[2]);
			fractol.ji = ft_atod(argv[3]);
		}
		fractol_init(&fractol);
		fractol_render(&fractol);
		mlx_loop(fractol.mlx_connection);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE ERROR_MESSAGE2, STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
	return (0);
}
