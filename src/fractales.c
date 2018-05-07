/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <tmervin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:36:54 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/07 11:55:54 by tmervin          ###   ########.fr       */
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
	while (x * x + y * y < 4.0 && i < e->mndl->it)
	{
		xtemp = x * x - y * y + e->mndl->j_cx;
		y = 2 * x * y + e->mndl->j_cy;
		x = xtemp;
		i++;
	}
	return (i);
}

unsigned int	burning_ship(t_env *e, double x, double y)
{
	unsigned char	i;
	double			xtemp;
	double			zx;
	double			zy;

	i = 0;
	x = x * e->mndl->x_len / WINW + e->mndl->x_cen - e->mndl->x_len / 2;
	y = y * e->mndl->y_len / WINH + e->mndl->y_cen - e->mndl->y_len / 2;
	zx = x;
	zy = y;
	while (zx * zx + zy * zy < 4.0 && i < e->mndl->it)
	{
		xtemp = zx * zx - zy * zy + x;
		zy = fabs(2 * zx * zy) + y;
		zx = fabs(xtemp);
		i++;
	}
	return (i);
}

unsigned int	tricorn(t_env *e, double x, double y)
{
	unsigned char	i;
	double			xtemp;
	double			zx;
	double			zy;

	i = 0;
	x = x * e->mndl->x_len / WINW + e->mndl->x_cen - e->mndl->x_len / 2;
	y = y * e->mndl->y_len / WINH + e->mndl->y_cen - e->mndl->y_len / 2;
	zx = x;
	zy = y;
	while (zx * zx + zy * zy < 4.0 && i < e->mndl->it)
	{
		xtemp = zx * zx - zy * zy + x;
		zy = -2 * zx * zy + y;
		zx = xtemp;
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
	while (x * x + y * y < 4.0 && i < e->mndl->it)
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
	while (x * x + y * y < (1 << 16) && i < e->mndl->it)
	{
		xtemp = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = xtemp;
		i++;
	}
	return (i);
}
