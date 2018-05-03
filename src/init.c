/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:44:47 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/03 12:30:17 by tmervin          ###   ########.fr       */
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

t_color2		*init_color2(void)
{
	t_color2 *color2;

	if (!(color2 = (t_color2*)malloc(sizeof(t_color2))))
		return (NULL);
	color2->col[0][0] = 253;
	color2->col[0][1] = 184;
	color2->col[0][2] = 19;
	color2->col[1][0] = 243;
	color2->col[1][1] = 112;
	color2->col[1][2] = 32;
	color2->col[2][0] = 201;
	color2->col[2][1] = 35;
	color2->col[2][2] = 75;
	color2->col[3][0] = 99;
	color2->col[3][1] = 95;
	color2->col[3][2] = 171;
	color2->col[4][0] = 0;
	color2->col[4][1] = 137;
	color2->col[4][2] = 207;
	color2->col[5][0] = 10;
	color2->col[5][1] = 176;
	color2->col[5][2] = 74;
	return (color2);
}

t_color2		*init_color3(void)
{
	t_color2 *color2;

	if (!(color2 = (t_color2*)malloc(sizeof(t_color2))))
		return (NULL);
	color2->col[0][0] = 4;
	color2->col[0][1] = 78;
	color2->col[0][2] = 129;
	color2->col[1][0] = 241;
	color2->col[1][1] = 133;
	color2->col[1][2] = 156;
	color2->col[2][0] = 246;
	color2->col[2][1] = 193;
	color2->col[2][2] = 197;
	color2->col[3][0] = 249;
	color2->col[3][1] = 236;
	color2->col[3][2] = 238;
	color2->col[4][0] = 168;
	color2->col[4][1] = 204;
	color2->col[4][2] = 174;
	color2->col[5][0] = 141;
	color2->col[5][1] = 186;
	color2->col[5][2] = 149;
	return (color2);
}

t_color2		*init_color4(void)
{
	t_color2 *color2;

	if (!(color2 = (t_color2*)malloc(sizeof(t_color2))))
		return (NULL);
	color2->col[0][0] = 212;
	color2->col[0][1] = 212;
	color2->col[0][2] = 212;
	color2->col[1][0] = 180;
	color2->col[1][1] = 180;
	color2->col[1][2] = 180;
	color2->col[2][0] = 144;
	color2->col[2][1] = 144;
	color2->col[2][2] = 144;
	color2->col[3][0] = 99;
	color2->col[3][1] = 99;
	color2->col[3][2] = 99;
	color2->col[4][0] = 72;
	color2->col[4][1] = 72;
	color2->col[4][2] = 72;
	color2->col[5][0] = 230;
	color2->col[5][1] = 230;
	color2->col[5][2] = 230;
	return (color2);
}

t_env		*init_env(void)
{
	t_env *e;

	if (!(e = (t_env*)malloc(sizeof(t_env))))
		return (NULL);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WINW + 200, WINH, "FRACT'OL");
	e->color2 = init_color2();
	e->mndl = init_mandel();
	e->zoom = 1;
	e->it_max = 50;
	e->j_cx = -0.7269;
	e->j_cy = 0.1889;
	return (e);
}
