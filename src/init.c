/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:44:47 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/01 15:37:29 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mandel	*init_mandel(void)
{
	t_mandel *brot;

	if (!(brot= (t_mandel*)malloc(sizeof(t_mandel))))
		return (NULL);
	brot->x1 = -2.1;
	brot->x2 = 0.6;
	brot->y1 = -1.2;
	brot->y2 = 1.2;
	brot->cr = 0;
	brot->ci = 0;
	brot->zr = 0;
	brot->zi = 0;
	brot->tmp = 0;
	return (brot);
}

t_color		*init_color(void)
{
	t_color *color;

	if (!(color = (t_color*)malloc(sizeof(t_color))))
		return (NULL);
	color->col[0] = 0;
	color->col[1] = 0;
	color->col[2] = 0;
	color->col[3] = 61;
	color->col[4] = 220;
	color->col[5] = 93;
	return (color);
}

t_env		*init_env(void)
{
	t_env *e;

	if (!(e = (t_env*)malloc(sizeof(t_env))))
		return (NULL);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_WIDTH, WIN_HEIGHT, "FRACT'OL");
	e->color = init_color();
	e->mandel = init_mandel();
	e->x = 0;
	e->y = 0;
	e->zoom = 150;
	e->it_max = 20;
	return (e);
}
