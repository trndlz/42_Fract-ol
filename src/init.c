/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 15:53:59 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/03 17:24:20 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mandel	*init_mandel(t_env *e)
{
	t_mandel *b;

	if (!(b = (t_mandel*)malloc(sizeof(t_mandel))))
		return (NULL);
	if (e->fract == 0)
	{
		b->x_len = 4.2;
		b->y_len = 2.4;
		b->x_cen = -0.75;
	}
	if (e->fract == 1 || e->fract == 2)
	{
		b->x_len = 3.5;
		b->y_len = 2;
		b->x_cen = 0;
	}
	b->y_cen = 0;
	b->j_cx = -0.7269;
	b->j_cy = 0.1889;
	b->n = 2;
	return (b);
}

void		ft_usage(void)
{
	ft_putstr("fractol <Mandelbrot/Julia/N-Julia>\n");
	exit(1);
}

int			init_fract(char **av)
{
	if (ft_strcmp(av[1], "Mandelbrot") == 0)
		return (0);
	else if (ft_strcmp(av[1], "Julia") == 0)
		return (1);
	else if (ft_strcmp(av[1], "N-Julia") == 0)
		return (2);
	else
		return (-1);
}

t_env		*init_env(char **av)
{
	t_env *e;

	if (!(e = (t_env*)malloc(sizeof(t_env))))
		return (NULL);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WINW + 200, WINH, "FRACT'OL");
	e->color2 = init_color2();
	e->fract = init_fract(av);
	e->mndl = init_mandel(e);
	e->zoom = 1;
	e->it_max = 24;
	return (e);
}
