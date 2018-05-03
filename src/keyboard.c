/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:24:59 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/03 12:00:27 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int		deal_mouse(int k, int x, int y, t_env *e)
{
	if (x >= 0 && y >= 0 && x <= WINW && y <= WINH)
	{
		printf("x %d / y %d\n", x, y);
		if (k == 1) // CLICK
		{
			e->j_cx = (3.5 * x / WINW) - 2.5;
			e->j_cy = (2 * x / WINH) - 1;
		}
	}

	printf("click %d\n", k);

	create_image(e);
	return (0);
}

int		deal_key(int key, t_env *e)
{
	printf("key %d\n", key);
	if (key == 123) // GAUCHE
	{
		e->mndl->x_cen -= (e->mndl->x_len * 15) / WINW;
	}
	if (key == 124) // RIGHT
	{
		e->mndl->x_cen += (e->mndl->x_len * 15) / WINW;
	}
	if (key == 126) // HAUT
	{
		e->mndl->y_cen -= (e->mndl->y_len * 15) / WINH;
	}
	if (key == 125) // BAS
	{
		e->mndl->y_cen += (e->mndl->y_len * 15) / WINH;
	}
	if (key == 49) // ESPACE
	{
			e->mndl->x_len *= 0.90;
			e->mndl->y_len *= 0.90;
			e->zoom *= 1.1;
	}
	if (key == 51) // DELETE
	{
			e->mndl->x_len *= 1.1;
			e->mndl->y_len *= 1.1;
			e->zoom *= 0.9;
	}
	if (key == 89) // 7
	{
		free(e->color2);
		e->color2 = init_color2();
	}
	if (key == 91) // 8
	{
		free(e->color2);
		e->color2 = init_color3();
	}
	if (key == 92) // 9
	{
		free(e->color2);
		e->color2 = init_color4();
	}
	if (key == 78) // -
	{
		e->it_max -= 5;
	}
	if (key == 69) // +
	{
		e->it_max += 5;
	}
	if (key == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(1);
	}
	create_image(e);
	return (0);
}
