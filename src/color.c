/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:46:22 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/03 11:43:33 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned long		get_color(t_env *e, int i)
{
	int				red;
	int				green;
	int				blue;

	red = e->color->col[0];
	green = e->color->col[1];
	blue = e->color->col[2];
	if (i == e->it_max)
		return (0x000000);
	red = i * e->color->col[3] / e->it_max;
	green = i * e->color->col[4] / e->it_max;
	blue = i * e->color->col[5] / e->it_max;
	return (((red & 0xff) << 16) + ((green & 0xff) << 8) + (blue & 0xff));
}

unsigned long		inter(t_env *e, int i, int r)
{
	int a;
	int b;
	int c;
	int red;
	int green;
	int blue;

	a = (e->color2->col[r + 1][0] - e->color2->col[r][0]) / (e->it_max / 4);
	b = (e->color2->col[r + 1][1] - e->color2->col[r][1]) / (e->it_max / 4);
	c = (e->color2->col[r + 1][2] - e->color2->col[r][2]) / (e->it_max / 4);
	red = a * i + e->color2->col[r][0] - a * r * e->it_max / 4;
	green = a * i + e->color2->col[r][1] - a * r * e->it_max / 4;
	blue = a * i + e->color2->col[r][2] - a * r * e->it_max / 4;
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
	if (i == e->it_max)
		return (rgb_to_hexa(e, 5));
	if (i >= 0 && i < e->it_max / 4)
		return (inter(e, i, 0));
	if (i >= e->it_max / 4 && i < e->it_max / 2)
		return (inter(e, i, 1));
	if (i >= e->it_max / 2 && i < 3 * e->it_max / 4)
		return (inter(e, i, 2));
	if (i >= 3 * e->it_max / 4 && i < e->it_max)
		return (inter(e, i, 3));
	else
		return (rgb_to_hexa(e, 4));
}

void		test(t_env *e)
{
	int i;

	i = 0;
	while (i < e->it_max)
	{
		i_color(e, i);
		i++;
	}
}

