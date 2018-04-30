/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 17:09:07 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/27 17:47:09 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plot_image(t_inf *d, t_points *p)
{
	p->dx = abs(p->bx1 - p->bx0);
	p->dy = -abs(p->by1 - p->by0);
	p->sx = p->bx0 < p->bx1 ? 1 : -1;
	p->sy = p->by0 < p->by1 ? 1 : -1;
	p->err = p->dx + p->dy;
	while (1)
	{
		p->color = get_color(d, p->z0 > p->z1 ? p->z1 : p->z0);
		if (p->bx0 >= 0 && p->by0 >= 0 && p->bx0 < WIN_WIDTH &&
				p->by0 < WIN_HEIGHT)
			d->imgstr[p->bx0 + p->by0 * WIN_WIDTH] = (int)p->color;
		if (p->bx0 == p->bx1 && p->by0 == p->by1)
			break ;
		p->e2 = 2 * p->err;
		if (p->e2 >= p->dy)
		{
			p->err += p->dy;
			p->bx0 += p->sx;
		}
		if (p->e2 <= p->dx)
		{
			p->err += p->dx;
			p->by0 += p->sy;
		}
	}
}

void	create_image(t_inf *d)
{
	d->image = mlx_new_image(d->mlx, WIN_WIDTH, WIN_HEIGHT);
	d->imgstr = (int *)mlx_get_data_addr(d->image, &d->bpp, &d->s_l, &d->endian);
	fill_image(d);
	mlx_put_image_to_window(d->mlx, d->win, d->image, 0, 0);
	mlx_destroy_image(d->mlx, d->image);
	mlx_loop(d->mlx);
}

