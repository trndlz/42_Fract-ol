/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <tmervin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 21:08:31 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/11 12:57:02 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_colors(int key, t_env *e)
{
	if (key == 88)
	{
		free(e->color);
		if (!(e->color = init_color()))
			ft_malloc_error(e);
	}
	if (key == 89)
	{
		free(e->color);
		if (!(e->color = init_color2()))
			ft_malloc_error(e);
	}
	if (key == 91)
	{
		free(e->color);
		if (!(e->color = init_color3()))
			ft_malloc_error(e);
	}
	if (key == 92)
	{
		free(e->color);
		if (!(e->color = init_color4()))
			ft_malloc_error(e);
	}
}

void	key_iter(int key, t_env *e)
{
	if (key == 78 && e->mndl->it > 4 && e->brnsl->it > 100000)
	{
		e->mndl->it -= 4;
		e->brnsl->it -= 100000;
	}
	if (key == 69 && e->mndl->it < 230)
	{
		e->mndl->it += 4;
	}
	if (key == 69 && e->brnsl->it < 20000000)
	{
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
		free(e->mndl);
		if (!(e->mndl = init_mandel(e)))
			ft_malloc_error(e);
	}
	if (key == 87)
	{
		e->fract = 5;
		free(e->mndl);
		if (!(e->mndl = init_mandel(e)))
			ft_malloc_error(e);
	}
	if (key == 84)
	{
		e->fract = 2;
		free(e->mndl);
		if (!(e->mndl = init_mandel(e)))
			ft_malloc_error(e);
	}
}

void	key_fractals2(int key, t_env *e)
{
	if (key == 36)
	{
		free(e->mndl);
		free(e->brnsl);
		if (!(e->brnsl = init_brnsl()))
			ft_malloc_error(e);
		if (!(e->mndl = init_mandel(e)))
			ft_malloc_error(e);
	}
}

void	key_fractals3(int key, t_env *e)
{
	if (key == 82)
	{
		e->fract = 0;
		free(e->mndl);
		if (!(e->mndl = init_mandel(e)))
			ft_malloc_error(e);
	}
	if (key == 83)
	{
		e->fract = 1;
		free(e->mndl);
		if (!(e->mndl = init_mandel(e)))
			ft_malloc_error(e);
	}
	if (key == 85)
	{
		e->fract = 3;
		free(e->brnsl);
		if (!(e->brnsl = init_brnsl()))
			ft_malloc_error(e);
	}
}
