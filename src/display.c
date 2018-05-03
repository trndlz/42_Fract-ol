/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 16:24:56 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/03 12:23:29 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	disp_color(t_env *e, int x, int y)
{
	char *c;
	int a;

	c = "C\0O\0L\0O\0R\0S";
	a = -1;

	while (++a < 6)
	{
		mlx_string_put(e->mlx, e->win, x, y, rgb_to_hexa(e, a), c);
		c = c + 2;
		x = x + 30;
	}
}

void	display_infos(t_env *e)
{
	char *it;

	it = ft_itoa(e->it_max);
	mlx_string_put(e->mlx, e->win, 810, 5, 0xC8C8C8, "> MAX ITERATION");
	mlx_string_put(e->mlx, e->win, 810, 25, 0xC8C8C8, "KEYS: - / +");
	mlx_string_put(e->mlx, e->win, 810, 45, 0xFFFFFF, it);
	mlx_string_put(e->mlx, e->win, 810, 85, 0xC8C8C8, "> SWITCH COLOR");
	mlx_string_put(e->mlx, e->win, 810, 105, 0xFFFFFF, "KEYS: 7 / 8 / 9");
	disp_color(e, 810, 125);
	free(it);
}
