/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:42:49 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/01 15:45:12 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mandel_rang(t_env *e)
{
	int i;

	i = 0;
	while (i < e->it_max)
	{
		e->mandel->tmp = e->mandel->zr;
		e->mandel->zr = (e->mandel->zr * e->mandel->zr) - (e->mandel->zi * e->mandel->zi) + e->mandel->cr;
		e->mandel->zi = (2 * e->mandel->zi * e->mandel->tmp) + e->mandel->ci;
		if (e->mandel->zr * e->mandel->zr + e->mandel->zi * e->mandel->zi >= 4)
			return (i);
		i++;
	}
	return (i);
}

void	mandel_plot(t_env *e)
{
	int x;
	int y;

	e->image = mlx_new_image(e->mlx, WIN_WIDTH, WIN_HEIGHT);
	e->imgstr = (int *)mlx_get_data_addr(e->image, &e->bpp, &e->s_l, &e->endian);
	x = e->x;
	while (x < WIN_WIDTH + e->x)
	{
		y = e->y;
		while (y < WIN_HEIGHT + e->y)
		{
			e->mandel->cr = (double)x / e->zoom + e->mandel->x1;
			e->mandel->ci = (double)y / e->zoom + e->mandel->y1;
			e->mandel->zr = 0;
			e->mandel->zi = 0;
			e->imgstr[x - e->x + (y - e->y) * WIN_WIDTH] = get_color(e, mandel_rang(e));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->image, 0, 0);
	mlx_destroy_image(e->mlx, e->image);
}

int		main(void)
{
	t_env *e;
	e = init_env();
	mandel_plot(e);
	mlx_hook(e->win, 2, 3, deal_key, e);
	mlx_mouse_hook(e->win, deal_mouse, e);
	mlx_loop(e->mlx);
	return (0);
}
