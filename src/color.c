/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <tmervin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 20:48:38 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/06 20:54:18 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned long		inter(t_env *e, int i, int r)
{
	int red;
	int green;
	int blue;

	e->a = (e->color2->col[r + 1][0] - e->color2->col[r][0]) /
		(e->mndl->it / 4);
	e->b = (e->color2->col[r + 1][1] - e->color2->col[r][1]) /
		(e->mndl->it / 4);
	e->c = (e->color2->col[r + 1][2] - e->color2->col[r][2]) /
		(e->mndl->it / 4);
	red = e->a * i + e->color2->col[r][0] - e->a * r * e->mndl->it / 4;
	green = e->b * i + e->color2->col[r][1] - e->b * r * e->mndl->it / 4;
	blue = e->c * i + e->color2->col[r][2] - e->c * r * e->mndl->it / 4;
	return (((red & 0xff) << 16) + ((green & 0xff) << 8) + (blue & 0xff));
}

unsigned long		rgb_to_hexa(t_env *e, int index)
{
	int r;
	int g;
	int b;

	r = e->color2->col[index][0];
	g = e->color2->col[index][1];
	b = e->color2->col[index][2];
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

unsigned long		i_color(t_env *e, int i)
{
	if (i == e->mndl->it)
		return (rgb_to_hexa(e, 5));
	if (i >= 0 && i < e->mndl->it / 4)
		return (inter(e, i, 0));
	if (i >= e->mndl->it / 4 && i < e->mndl->it / 2)
		return (inter(e, i, 1));
	if (i >= e->mndl->it / 2 && i < 3 * e->mndl->it / 4)
		return (inter(e, i, 2));
	if (i >= 3 * e->mndl->it / 4 && i < e->mndl->it)
		return (inter(e, i, 3));
	else
		return (rgb_to_hexa(e, 4));
}
