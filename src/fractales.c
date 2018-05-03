/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:36:54 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/03 11:49:18 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			draw_point(t_env *e, int x, int y, unsigned int color)
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
		xtemp = x * x - y * y + e->j_cx;
		y = 2 * x * y + e->j_cy;
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
		xtemp = pow((x * x + y * y), (n / 2)) * cos(n * atan2(y, x)) + e->j_cx;
		y = pow((x * x + y * y), (n / 2)) * sin(n * atan2(y, x)) + e->j_cy;
		x = xtemp;
		i++;
	}
	return (i);
}

double			c_interp(double v0, double v1, double t)
{
	return ((1 - t) * v0 + t * v1);
}

//unsigned long	mandelbrot(t_env *e, double x0, double y0)
unsigned int	mandelbrot(t_env *e, double x0, double y0)
{
	unsigned char	i;
	double			x;
	double			y;
	double			xtemp;
	//double			log_zn;
	//double			nu;
	//unsigned long	c1;
	//unsigned long	c2;
	//unsigned long	color;

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
	/*if (i < e->it_max)
	{
		log_zn = log(x * x + y * y) / 2;
		nu = log(log_zn / log(2)) / log(2);
		i = i + 1 - nu;
	}
	c1 = i_color(e, i);
	c2 = i_color(e, i + 1);
	color = c_interp(c1, c2, i % 1); */
	return (i);
	//return (color);
}

void			fract_plot(t_env *e)
{
	//unsigned int		i;
	unsigned long		i;
	int					a;
	int					b;

	a = -1;
	while (++a < WINW)
	{
		b = -1;
		while (++b < WINH)
		{
			i = mandelbrot(e, (double)a, (double)b);
			draw_point(e, a, b, i_color(e, i));
			//draw_point(e, a, b, i);
		}
	}
}

void			create_image(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	e->image = mlx_new_image(e->mlx, WINW, WINH);
	e->imgstr = (int *)mlx_get_data_addr(e->image, &e->bpp, &e->s_l, &e->endian);
	fract_plot(e);
	display_infos(e);
	mlx_put_image_to_window(e->mlx, e->win, e->image, 0, 0);
	mlx_destroy_image(e->mlx, e->image);
}
