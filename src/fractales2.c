/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <tmervin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 11:55:29 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/07 11:55:51 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			barnsley_algo(t_env *e, int rd)
{
	if (rd == 0)
	{
		e->brnsl->x1 = 0;
		e->brnsl->y1 = 0.16 * e->brnsl->y0;
	}
	else if (rd >= 1 && rd <= 7)
	{
		e->brnsl->x1 = -0.15 * e->brnsl->x0 + 0.28 * e->brnsl->y0;
		e->brnsl->y1 = 0.26 * e->brnsl->x0 + 0.24 * e->brnsl->y0 + 0.44;
	}
	else if (rd >= 8 && rd <= 15)
	{
		e->brnsl->x1 = 0.2 * e->brnsl->x0 - 0.26 * e->brnsl->y0;
		e->brnsl->y1 = 0.23 * e->brnsl->x0 + 0.22 * e->brnsl->y0 + 1.6;
	}
	else
	{
		e->brnsl->x1 = 0.85 * e->brnsl->x0 + 0.04 * e->brnsl->y0;
		e->brnsl->y1 = -0.04 * e->brnsl->x0 + 0.85 * e->brnsl->y0 + 1.6;
	}
}

void			barnsley(t_env *e, unsigned long iter)
{
	int			rd;
	double		a;
	double		b;

	e->brnsl->x0 = 0;
	e->brnsl->y0 = 0;
	srand(time(NULL));
	while (iter > 0)
	{
		rd = rand() % 100;
		barnsley_algo(e, rd);
		a = e->brnsl->x_zoom * (e->brnsl->x1 - e->brnsl->x_off) + WINW / 2;
		b = e->brnsl->y_zoom * (e->brnsl->y1 - e->brnsl->y_off);
		if (a > 0 && b > 0 && a < WINW && b < WINH)
			draw_point(e, a, b, COLBARNSLEY);
		e->brnsl->x0 = e->brnsl->x1;
		e->brnsl->y0 = e->brnsl->y1;
		iter--;
	}
}
