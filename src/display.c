/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <tmervin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 16:24:56 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/07 11:43:09 by tmervin          ###   ########.fr       */
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
		if (e->fract != 3)
			mlx_string_put(e->mlx, e->win, x, y, rgb_to_hexa(e, a), c);
		else
			mlx_string_put(e->mlx, e->win, x, y, COLBARNSLEY, c);
		c = c + 2;
		x = x + 33;
	}
}

void	display_status(t_env *e)
{
	char *it;

	if (e->fract == 3)
		it = ft_itoa(e->brnsl->it);
	else
		it = ft_itoa(e->mndl->it);
	mlx_string_put(e->mlx, e->win, WINW + 10, 5, 0xC8C8C8, "> CURRENT");
	mlx_string_put(e->mlx, e->win, WINW + 10, 25, 0xFFFFFF,
		e->fract_name[e->fract]);
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
	mlx_string_put(e->mlx, e->win, WINW + 10, 245, 0xFFFFFF, "0 Mandelbrot");
	mlx_string_put(e->mlx, e->win, WINW + 10, 265, 0xFFFFFF, "1 Julia ");
	mlx_string_put(e->mlx, e->win, WINW + 10, 285, 0xFFFFFF, "2 N-Julia");
	mlx_string_put(e->mlx, e->win, WINW + 10, 305, 0xFFFFFF, "3 Barnsley Fern");
	mlx_string_put(e->mlx, e->win, WINW + 10, 325, 0xFFFFFF, "4 Burning Ship");
	mlx_string_put(e->mlx, e->win, WINW + 10, 345, 0xFFFFFF, "5 Tricorn");
	mlx_string_put(e->mlx, e->win, WINW + 10, 385, 0xC8C8C8, "> RESET : Enter");
	mlx_string_put(e->mlx, e->win, WINW + 10, 405, 0xC8C8C8, "> MOVE < ^ > v");
	mlx_string_put(e->mlx, e->win, WINW + 10, 425, 0xC8C8C8, "> EXIT : Esc");
	if (e->fract == 2)
	{
		mlx_string_put(e->mlx, e->win, WINW + 10, 465, 0xC8C8C8,
			"> N (-n +m):");
		mlx_string_put(e->mlx, e->win, WINW + 135, 465, 0xFFFFFF, n);
	}
	free(n);
	display_status(e);
}
