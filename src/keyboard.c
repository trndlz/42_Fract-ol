/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <tmervin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 22:08:14 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/11 12:58:15 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		deal_mouse(int k, int x, int y, t_env *e)
{
	if (x >= 0 && y >= 0 && x <= WINW && y <= WINH)
	{
		if (k == 1)
		{
			e->mndl->x_cen += e->mndl->x_len * (float)(x - WINW / 2) / WINW;
			e->mndl->y_cen += e->mndl->y_len * (float)(y - WINH / 2) / WINH;
		}
		if (k == 5)
		{
			e->mndl->x_len *= 0.90;
			e->mndl->y_len *= 0.90;
			e->brnsl->x_zoom *= 1.1;
			e->brnsl->y_zoom *= 1.1;
		}
		if (k == 4)
		{
			e->mndl->x_len *= 1.1;
			e->mndl->y_len *= 1.1;
			e->brnsl->x_zoom *= 0.9;
			e->brnsl->y_zoom *= 0.9;
		}
	}
	create_image(e);
	return (0);
}

/*
** Mouse Move : Change Julia and N-Julia parameters (only)
*/

int		mouse_move(int x, int y, t_env *e)
{
	int tmp;

	if ((e->fract == 1 || e->fract == 2)
			&& x >= 0 && y >= 0 && e->zoomed == 0 && x <= WINW && y <= WINH)
	{
		tmp = e->mndl->n;
		free(e->mndl);
		if (!(e->mndl = init_mandel(e)))
			ft_malloc_error(e);
		e->mndl->n = tmp;
		e->mndl->j_cx = (3.5 * x / WINW) - 2.5;
		e->mndl->j_cy = (2 * x / WINH) - 1;
	}
	create_image(e);
	return (0);
}

void	key_move(int key, t_env *e)
{
	if (key == 123)
	{
		e->brnsl->x_off -= 30 / e->brnsl->x_zoom;
		e->mndl->x_cen -= (e->mndl->x_len * 20) / WINW;
	}
	if (key == 124)
	{
		e->brnsl->x_off += 30 / e->brnsl->x_zoom;
		e->mndl->x_cen += (e->mndl->x_len * 20) / WINW;
	}
	if (key == 126)
	{
		e->brnsl->y_off -= 30 / e->brnsl->x_zoom;
		e->mndl->y_cen -= (e->mndl->y_len * 20) / WINH;
	}
	if (key == 125)
	{
		e->brnsl->y_off += 30 / e->brnsl->x_zoom;
		e->mndl->y_cen += (e->mndl->y_len * 20) / WINH;
	}
}

void	key_zoom(int key, t_env *e)
{
	if (key == 49)
	{
		e->zoomed = 1;
		e->mndl->x_len *= 0.90;
		e->mndl->y_len *= 0.90;
		e->brnsl->x_zoom *= 1.1;
		e->brnsl->y_zoom *= 1.1;
	}
	if (key == 51)
	{
		e->zoomed = 1;
		e->mndl->x_len *= 1.1;
		e->mndl->y_len *= 1.1;
		e->brnsl->x_zoom *= 0.9;
		e->brnsl->y_zoom *= 0.9;
	}
}

int		deal_key(int key, t_env *e)
{
	key_fractals(key, e);
	key_fractals2(key, e);
	key_fractals3(key, e);
	key_colors(key, e);
	key_iter(key, e);
	key_zoom(key, e);
	key_move(key, e);
	if (key == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(1);
	}
	create_image(e);
	return (0);
}
