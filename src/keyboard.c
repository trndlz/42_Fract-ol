/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:24:59 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/03 15:51:23 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		deal_mouse(int k, int x, int y, t_env *e)
{
	if (x >= 0 && y >= 0 && x <= WINW && y <= WINH)
	{
		printf("x %d / y %d\n", x, y);
		if (k == 1)
		{
			e->mndl->j_cx = (3.5 * x / WINW) - 2.5;
			e->mndl->j_cy = (2 * x / WINH) - 1;
		}
	}
	printf("click %d\n", k);
	create_image(e);
	return (0);
}

void	key_move_zoom(int key, t_env *e)
{
	if (key == 123)
		e->mndl->x_cen -= (e->mndl->x_len * 20) / WINW;
	if (key == 124)
		e->mndl->x_cen += (e->mndl->x_len * 20) / WINW;
	if (key == 126)
		e->mndl->y_cen -= (e->mndl->y_len * 20) / WINH;
	if (key == 125)
		e->mndl->y_cen += (e->mndl->y_len * 20) / WINH;
	if (key == 49)
	{
		e->mndl->x_len *= 0.90;
		e->mndl->y_len *= 0.90;
		e->zoom *= 1.1;
	}
	if (key == 51)
	{
		e->mndl->x_len *= 1.1;
		e->mndl->y_len *= 1.1;
		e->zoom *= 0.9;
	}
}

void	key_colors(int key, t_env *e)
{
	if (key == 88)
	{
		free(e->color2);
		e->color2 = init_color();
	}
	if (key == 89)
	{
		free(e->color2);
		e->color2 = init_color2();
	}
	if (key == 91)
	{
		free(e->color2);
		e->color2 = init_color3();
	}
	if (key == 92)
	{
		free(e->color2);
		e->color2 = init_color4();
	}
}

void	key_fractals(int key, t_env *e)
{
	if (key == 78 && e->it_max > 4)
		e->it_max -= 4;
	if (key == 69)
		e->it_max += 4;
	if (key == 83)
		e->fract = 0;
	if (key == 84)
		e->fract = 1;
	if (key == 85)
		e->fract = 2;
	if (key == 45 && e->mndl->n > 2)
		e->mndl->n -= 1;
	if (key == 46)
		e->mndl->n += 1;
	if (key == 36)
		e->mndl = init_mandel();
}

int		deal_key(int key, t_env *e)
{
	printf("key %d\n", key);
	key_fractals(key, e);
	key_colors(key, e);
	key_move_zoom(key, e);
	if (key == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(1);
	}
	create_image(e);
	return (0);
}
