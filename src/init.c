/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <tmervin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 22:07:55 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/06 23:35:33 by tmervin          ###   ########.fr       */
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
	else
	{
		b->x_len = 3.5;
		b->y_len = 2;
		b->x_cen = 0;
	}
	b->y_cen = 0;
	b->j_cx = -0.7269;
	b->j_cy = 0.1889;
	b->n = 2;
	b->it = 24;
	return (b);
}

t_brnsl		*init_brnsl(void)
{
	t_brnsl *b;

	if (!(b = (t_brnsl*)malloc(sizeof(t_brnsl))))
		return (NULL);
	b->x_off = 0;
	b->y_off = 0;
	b->x_zoom = 30;
	b->y_zoom = 30;
	b->it = 100000;
	return (b);
}

int			init_fract(char **av)
{
	if (ft_strcmp(av[1], "Mandelbrot") == 0)
		return (0);
	else if (ft_strcmp(av[1], "Julia") == 0)
		return (1);
	else if (ft_strcmp(av[1], "N-Julia") == 0)
		return (2);
	else if (ft_strcmp(av[1], "Barnsley") == 0)
		return (3);
	else if (ft_strcmp(av[1], "Tricorn") == 0)
		return (4);
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
	if (!(e->color2 = init_color2()))
		return (NULL);
	e->fract = init_fract(av);
	if (!(e->mndl = init_mandel(e)))
		return (NULL);
	if (!(e->brnsl = init_brnsl()))
		return (NULL);
	return (e);
}
