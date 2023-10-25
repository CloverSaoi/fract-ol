/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddutta <ddutta@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:33:32 by ddutta            #+#    #+#             */
/*   Updated: 2023/10/25 17:03:11 by ddutta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_scale(double unscaledNum, double minAllowed,
			double maxAllowed, double org_max)
{
	double	num;
	double	denom;

	num = (maxAllowed - minAllowed) * (unscaledNum);
	denom = (org_max);
	return (num / denom + minAllowed);
}

void	calculate_complex(t_complex *comp)
{
	double	real;

	real = comp->r * comp->r - comp->i * comp->i;
	comp->i = 2 * comp->r * comp->i;
	comp->r = real;
}
