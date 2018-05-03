/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 15:53:49 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/03 15:53:50 by tmervin          ###   ########.fr       */
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

void			fract_plot(t_env *e)
{
	unsigned long		i;
	int					a;
	int					b;

	a = -1;
	while (++a < WINW)
	{
		b = -1;
		while (++b < WINH)
		{
			if (e->fract == 0)
				i = mandelbrot(e, (double)a, (double)b);
			if (e->fract == 1)
				i = julia(e, (double)a, (double)b);
			if (e->fract == 2)
				i = n_julia(e, (double)a, (double)b);
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
