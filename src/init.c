/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:44:47 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/02 18:47:05 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mandel	*init_mandel(void)
{
	t_mandel *b;

	if (!(b= (t_mandel*)malloc(sizeof(t_mandel))))
		return (NULL);
	b->x_len = 3.5;
	b->y_len = 2;
	b->x_cen = -0.75;
	b->x_cen = 0;
	return (b);
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
	e->win = mlx_new_window(e->mlx, WINW + 200, WINH, "FRACT'OL");
	e->color = init_color();
	e->mndl = init_mandel();
	e->zoom = 1;
	e->it_max = 20;
	return (e);
}
