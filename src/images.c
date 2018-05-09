/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <tmervin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 15:53:49 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/09 19:58:10 by tmervin          ###   ########.fr       */
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

unsigned long	choose_fractal(t_env *e, double a, double b)
{
	if (e->fract == 0)
		return (mandelbrot(e, a, b));
	if (e->fract == 1)
		return (julia(e, a, b));
	if (e->fract == 2)
		return (n_julia(e, a, b));
	if (e->fract == 4)
		return (burning_ship(e, a, b));
	if (e->fract == 5)
		return (tricorn(e, a, b));
	else
		return (-1);
}

void			fract_plot(t_env *e)
{
	unsigned long		i;
	int					a;
	int					b;

	if (e->fract == 3)
	{
		barnsley(e, e->brnsl->it);
		return ;
	}
	i = 0;
	a = -1;
	while (++a < WINW)
	{
		b = -1;
		while (++b < WINH)
		{
			i = choose_fractal(e, (double)a, (double)b);
			draw_point(e, a, b, i_color(e, i));
		}
	}
}

void			create_image(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	e->image = mlx_new_image(e->mlx, WINW, WINH);
	e->imgstr = (int *)mlx_get_data_addr(e->image, &e->bpp, &e->s_l,
			&e->endian);
	fract_plot(e);
	display_infos(e);
	mlx_put_image_to_window(e->mlx, e->win, e->image, 0, 0);
	mlx_destroy_image(e->mlx, e->image);
}
