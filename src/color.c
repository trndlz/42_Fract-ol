/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:46:22 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/30 17:18:49 by tmervin          ###   ########.fr       */
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
