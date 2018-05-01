/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:24:59 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/01 16:16:51 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int		deal_mouse(int k, int x, int y, t_env *e)
{
	e->x += 0;
	if (k == 5) // MOLETTE BAS
	{
		e->x += x / 10;
		e->y += y / 10;
		e->x *= 1.2;
		e->y *= 1.2;
		e->zoom *= 1.2;
		e->it_max *= 1.05;
	}

	if (k == 4) // MOLETTE HAUT
	{
		e->x -= x / 10;
		e->y -= y / 10;
		e->x /= 1.2;
		e->y /= 1.2;
		e->zoom /= 1.2;
		e->it_max *= 1.05;
	}

	printf("click %d\n", k);
	if (x >= 0 && y >= 0 && x <= WIN_WIDTH && y <= WIN_HEIGHT)
		printf("x %d / y %d\n", x, y);
	mandel_plot(e);
	return (0);
}

int		deal_key(int key, t_env *e)
{
	if (key == 123) // GAUCHE
	{
		e->x -= 100;
	}
	if (key == 124) // RIGHT
	{
		e->x += 100;
	}
	if (key == 126) // HAUT
	{
		e->y -= 100;
	}
	if (key == 125) // BAS
	{
		e->y += 100;
	}


	if (key == 78) // -
	{
		//e->x += e->x / 5;
		//e->y += e->y / 5;
		//e->x *= 1.2;
		//e->y *= 1.2;
		e->it_max -= 20;
	}
	if (key == 69) // +
	{
		//e->x -= e->x / 5;
		//e->y -= e->y / 5;
		//e->x /= 1.2;
		//e->y /= 1.2;
		e->it_max += 20;
	}
	if (key == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(1);
	}
	mandel_plot(e);
	return (0);
}
