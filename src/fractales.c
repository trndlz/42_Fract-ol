/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:36:54 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/02 18:20:34 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_point(t_env *e, int x, int y, unsigned int color)
{
	int i;

	i = (x + ((y * e->s_l) / 4));
	if (i >= 0 && i < (WINW * WINH))
		e->imgstr[i] = color;
}

unsigned int	julia(t_env *e, double x, double y)
{
	unsigned char	i;
	double			xtemp;

	i = 0;
	x = x * e->mndl->x_len / WINW + e->mndl->x_cen - e->mndl->x_len / 2;
	y = y * e->mndl->y_len / WINH + e->mndl->y_cen - e->mndl->y_len / 2;
	while (x * x + y * y < 4.0 && i < e->it_max)
	{
		xtemp = x * x - y * y - 0.4;
		y = 2 * x * y + 0.6;
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
	n = 4;
	x = x * e->mndl->x_len / WINW + e->mndl->x_cen - e->mndl->x_len / 2;
	y = y * e->mndl->y_len / WINH + e->mndl->y_cen - e->mndl->y_len / 2;
	while (x * x + y * y < 4.0 && i < e->it_max)
	{
		xtemp = pow((x * x + y * y), (n / 2)) * cos(n * atan2(y, x)) - 0.74543;
		y = pow((x * x + y * y), (n / 2)) * sin(n * atan2(y, x)) + 0.11301;
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
	while (x * x + y * y < 4.0 && i < e->it_max)
	{
		xtemp = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = xtemp;
		i++;
	}
	return (i);
}

void	fract_plot(t_env *e)
{
	unsigned int		i;
	int					a;
	int					b;

	a = -1;
	while (++a < WINW)
	{
		b = -1;
		while (++b < WINH)
		{
			i = julia(e, (double)a, (double)b);
			draw_point(e, a, b, get_color(e, i));
		}
	}
}

void	create_image(t_env *e)
{
	e->image = mlx_new_image(e->mlx, WINW, WINH);
	e->imgstr = (int *)mlx_get_data_addr(e->image, &e->bpp, &e->s_l, &e->endian);
	fract_plot(e);
	mlx_put_image_to_window(e->mlx, e->win, e->image, 0, 0);
	mlx_destroy_image(e->mlx, e->image);
}
