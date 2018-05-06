/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <tmervin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:36:54 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/06 23:33:38 by tmervin          ###   ########.fr       */
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

unsigned int	tricorn(t_env *e, double x, double y)
{
	unsigned char	i;
	double			xtemp;

	i = 0;
	x = x * e->mndl->x_len / WINW + e->mndl->x_cen - e->mndl->x_len / 2;
	y = y * e->mndl->y_len / WINH + e->mndl->y_cen - e->mndl->y_len / 2;
	while (x * x + y * y < 4.0 && i < e->mndl->it)
	{
		xtemp = x * x - y * y + x;
		y = -2 * x * y + y;
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

void			barnsley_algo(t_env *e, int rd)
{
	if (rd == 0)
	{
		e->brnsl->x1 = 0;
		e->brnsl->y1 = 0.16 * e->brnsl->y0;
	}
	else if (rd >= 1 && rd <= 7)
	{
		e->brnsl->x1 = -0.15 * e->brnsl->x0 + 0.28 * e->brnsl->y0;
		e->brnsl->y1 = 0.26 * e->brnsl->x0 + 0.24 * e->brnsl->y0 + 0.44;
	}
	else if (rd >= 8 && rd <= 15)
	{
		e->brnsl->x1 = 0.2 * e->brnsl->x0 - 0.26 * e->brnsl->y0;
		e->brnsl->y1 = 0.23 * e->brnsl->x0 + 0.22 * e->brnsl->y0 + 1.6;
	}
	else
	{
		e->brnsl->x1 = 0.85 * e->brnsl->x0 + 0.04 * e->brnsl->y0;
		e->brnsl->y1 = -0.04 * e->brnsl->x0 + 0.85 * e->brnsl->y0 + 1.6;
	}
}

void			barnsley(t_env *e, unsigned long iter)
{
	int			rd;
	double		a;
	double		b;

	e->brnsl->x0 = 0;
	e->brnsl->y0 = 0;
	srand(time(NULL));
	while (iter > 0)
	{
		rd = rand() % 100;
		barnsley_algo(e, rd);
		a = e->brnsl->x_zoom * (e->brnsl->x1 - e->brnsl->x_off) + WINW / 2;
		b = e->brnsl->y_zoom * (e->brnsl->y1 - e->brnsl->y_off);
		if (a > 0 && b > 0 && a < WINW && b < WINH)
			draw_point(e, a, b, COLBARNSLEY);
		e->brnsl->x0 = e->brnsl->x1;
		e->brnsl->y0 = e->brnsl->y1;
		iter--;
	}
}
