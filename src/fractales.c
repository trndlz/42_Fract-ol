/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:36:54 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/03 15:41:04 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	julia(t_env *e, double x, double y)
{
	unsigned char	i;
	double			xtemp;

	i = 0;
	x = x * e->mndl->x_len / WINW + e->mndl->x_cen - e->mndl->x_len / 2;
	y = y * e->mndl->y_len / WINH + e->mndl->y_cen - e->mndl->y_len / 2;
	while (x * x + y * y < 4.0 && i < e->it_max)
	{
		xtemp = x * x - y * y + e->mndl->j_cx;
		y = 2 * x * y + e->mndl->j_cy;
		x = xtemp;
		i++;
	}
	return (i);
}

unsigned int	n_julia(t_env *e, double x, double y)
{
	unsigned char	i;
	double			xtemp;
	double			n;

	i = 0;
	n = e->mndl->n;
	x = x * e->mndl->x_len / WINW + e->mndl->x_cen - e->mndl->x_len / 2;
	y = y * e->mndl->y_len / WINH + e->mndl->y_cen - e->mndl->y_len / 2;
	while (x * x + y * y < 4.0 && i < e->it_max)
	{
		xtemp = pow((x * x + y * y), (n / 2)) *
			cos(n * atan2(y, x)) + e->mndl->j_cx;
		y = pow((x * x + y * y), (n / 2)) *
			sin(n * atan2(y, x)) + e->mndl->j_cy;
		x = xtemp;
		i++;
	}
	return (i);
}

unsigned int	mandelbrot(t_env *e, double x0, double y0)
{
	unsigned char	i;
	double			x;
	double			y;
	double			xtemp;

	i = 0;
	x = 0.0;
	y = 0.0;
	x0 = x0 * e->mndl->x_len / WINW + e->mndl->x_cen - e->mndl->x_len / 2;
	y0 = y0 * e->mndl->y_len / WINH + e->mndl->y_cen - e->mndl->y_len / 2;
	while (x * x + y * y < (1 << 16) && i < e->it_max)
	{
		xtemp = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = xtemp;
		i++;
	}
	return (i);
}
