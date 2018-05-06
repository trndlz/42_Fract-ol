/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <tmervin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:24:59 by tmervin           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/05/06 21:15:16 by tmervin          ###   ########.fr       */
=======
/*   Updated: 2018/05/03 17:35:51 by tmervin          ###   ########.fr       */
>>>>>>> fb0516f9e3d6763e01fb9ec68cc92412d203293d
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
			e->mndl = init_mandel(e);
			e->mndl->j_cx = (3.5 * x / WINW) - 2.5;
			e->mndl->j_cy = (2 * x / WINH) - 1;
		}
		if (k == 5)
		{
			e->mndl->x_len *= 0.90;
			e->mndl->y_len *= 0.90;
		}
		if (k == 4)
		{
			e->mndl->x_len *= 1.1;
			e->mndl->y_len *= 1.1;
		}
	}
	printf("click %d\n", k);
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
		e->mndl->x_len *= 0.90;
		e->mndl->y_len *= 0.90;
		e->brnsl->x_zoom *= 1.1;
		e->brnsl->y_zoom *= 1.1;
	}
	if (key == 51)
	{
		e->mndl->x_len *= 1.1;
		e->mndl->y_len *= 1.1;
		e->brnsl->x_zoom *= 0.9;
		e->brnsl->y_zoom *= 0.9;
	}
}

<<<<<<< HEAD
=======
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
	{
		e->fract = 0;
		e->mndl = init_mandel(e);
	}
	if (key == 84)
	{
		e->fract = 1;
		e->mndl = init_mandel(e);
	}
	if (key == 85)
	{
		e->fract = 2;
		e->mndl = init_mandel(e);
	}
	if (key == 45 && e->mndl->n > 2)
		e->mndl->n -= 1;
	if (key == 46)
		e->mndl->n += 1;
	if (key == 36)
		e->mndl = init_mandel(e);
}

>>>>>>> fb0516f9e3d6763e01fb9ec68cc92412d203293d
int		deal_key(int key, t_env *e)
{
	printf("key %d\n", key);
	key_fractals(key, e);
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
