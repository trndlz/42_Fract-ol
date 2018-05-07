/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <tmervin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 21:08:31 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/07 13:28:44 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_colors(int key, t_env *e)
{
	if (key == 88)
	{
		free(e->color);
		e->color = init_color();
	}
	if (key == 89)
	{
		free(e->color);
		e->color = init_color2();
	}
	if (key == 91)
	{
		free(e->color);
		e->color = init_color3();
	}
	if (key == 92)
	{
		free(e->color);
		e->color = init_color4();
	}
}

void	key_iter(int key, t_env *e)
{
	if (key == 78 && e->mndl->it > 4 && e->brnsl->it > 100000)
	{
		e->mndl->it -= 4;
		e->brnsl->it -= 100000;
	}
	if (key == 69)
	{
		e->mndl->it += 4;
		e->brnsl->it += 100000;
	}
	if (key == 45 && e->mndl->n > 2)
		e->mndl->n -= 1;
	if (key == 46)
		e->mndl->n += 1;
}

void	key_fractals(int key, t_env *e)
{
	if (key == 86)
	{
		e->fract = 4;
		e->mndl = init_mandel(e);
	}
	if (key == 87)
	{
		e->fract = 5;
		e->mndl = init_mandel(e);
	}
	if (key == 84)
	{
		e->fract = 2;
		e->mndl = init_mandel(e);
	}
	if (key == 36)
	{
		e->brnsl = init_brnsl();
		e->mndl = init_mandel(e);
	}
}

void	key_fractals2(int key, t_env *e)
{
	if (key == 82)
	{
		e->fract = 0;
		e->mndl = init_mandel(e);
	}
	if (key == 83)
	{
		e->fract = 1;
		e->mndl = init_mandel(e);
	}
	if (key == 85)
	{
		e->fract = 3;
		e->brnsl = init_brnsl();
	}
}
