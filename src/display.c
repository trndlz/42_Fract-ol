/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 16:24:56 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/03 15:39:20 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	disp_color(t_env *e, int x, int y)
{
	char	*c;
	int		a;

	c = "C\0O\0L\0O\0R\0S";
	a = -1;
	while (++a < 6)
	{
		mlx_string_put(e->mlx, e->win, x, y, rgb_to_hexa(e, a), c);
		c = c + 2;
		x = x + 33;
	}
}

void	display_infos2(t_env *e)
{
	char *it;

	it = ft_itoa(e->it_max);
	mlx_string_put(e->mlx, e->win, WINW + 10, 5, 0xC8C8C8, "> CURRENT");
	if (e->fract == 0)
		mlx_string_put(e->mlx, e->win, WINW + 10, 25, 0xFFFFFF, "MANDELBROT");
	if (e->fract == 1)
		mlx_string_put(e->mlx, e->win, WINW + 10, 25, 0xFFFFFF, "JULIA");
	if (e->fract == 2)
		mlx_string_put(e->mlx, e->win, WINW + 10, 25, 0xFFFFFF, "N-JULIA");
	mlx_string_put(e->mlx, e->win, WINW + 10, 65, 0xC8C8C8,
			"> MAX ITER. (+ -)");
	mlx_string_put(e->mlx, e->win, WINW + 10, 85, 0xFFFFFF, it);
	mlx_string_put(e->mlx, e->win, WINW + 10, 125, 0xC8C8C8,
			"> COLOR (6 to 9)");
	disp_color(e, WINW + 10, 145);
	free(it);
}

void	display_infos(t_env *e)
{
	char *n;

	n = ft_itoa(e->mndl->n);
	mlx_string_put(e->mlx, e->win, WINW + 10, 185, 0xC8C8C8,
			"> ZOOM IN : Space");
	mlx_string_put(e->mlx, e->win, WINW + 10, 205, 0xC8C8C8,
			"> ZOOM OUT : Del");
	mlx_string_put(e->mlx, e->win, WINW + 10, 245, 0xFFFFFF, "1 Mandelbrot");
	mlx_string_put(e->mlx, e->win, WINW + 10, 265, 0xFFFFFF, "2 Julia ");
	mlx_string_put(e->mlx, e->win, WINW + 10, 285, 0xFFFFFF, "3 N-Julia");
	mlx_string_put(e->mlx, e->win, WINW + 10, 325, 0xC8C8C8, "> RESET : Enter");
	mlx_string_put(e->mlx, e->win, WINW + 10, 345, 0xC8C8C8, "> MOVE < ^ > v");
	mlx_string_put(e->mlx, e->win, WINW + 10, 365, 0xC8C8C8, "> EXIT : Esc");
	if (e->fract == 2)
	{
		mlx_string_put(e->mlx, e->win, WINW + 10, 405, 0xC8C8C8, "> N (-n +m)");
		mlx_string_put(e->mlx, e->win, WINW + 10, 425, 0xFFFFFF, n);
	}
	free(n);
	display_infos2(e);
}
