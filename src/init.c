/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <tmervin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 22:07:55 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/10 15:18:46 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mandel	*init_mandel(t_env *e)
{
	t_mandel *b;

	if (!(b = (t_mandel*)malloc(sizeof(t_mandel))))
		return (NULL);
	if (e->fract == 0 || e->fract == 4 || e->fract == 5)
	{
		b->x_len = 4.2;
		b->y_len = 2.4;
		b->x_cen = (e->fract == 4 ? -0.55 : -0.75);
		b->y_cen = (e->fract == 4 ? -0.5 : 0);
	}
	else
	{
		b->x_len = 3.5;
		b->y_len = 2;
		b->x_cen = 0;
		b->y_cen = 0;
	}
	b->j_cx = -0.7269;
	b->j_cy = 0.1889;
	b->n = 2;
	b->it = 24;
	e->zoomed = 0;
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
	if (ft_strcmp(av[1], "Mandelbrot") == 0 || ft_strcmp(av[1], "0") == 0)
		return (0);
	else if (ft_strcmp(av[1], "Julia") == 0 || ft_strcmp(av[1], "1") == 0)
		return (1);
	else if (ft_strcmp(av[1], "N-Julia") == 0 || ft_strcmp(av[1], "2") == 0)
		return (2);
	else if (ft_strcmp(av[1], "Barnsley") == 0 || ft_strcmp(av[1], "3") == 0)
		return (3);
	else if (ft_strcmp(av[1], "Burning") == 0 || ft_strcmp(av[1], "4") == 0)
		return (4);
	else if (ft_strcmp(av[1], "Tricorn") == 0 || ft_strcmp(av[1], "5") == 0)
		return (5);
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
	e->fract_name[0] = "MANDELBROT";
	e->fract_name[1] = "JULIA";
	e->fract_name[2] = "N-JULIA";
	e->fract_name[3] = "BARNSLEY";
	e->fract_name[4] = "BURNING-SHIP";
	e->fract_name[5] = "TRICORN";
	if (!(e->color = init_color2()))
		ft_malloc_error(e);
	e->fract = init_fract(av);
	if (e->fract == -1)
	{
		free_structures(e);
		ft_usage();
	}
	if (!(e->mndl = init_mandel(e)))
		ft_malloc_error(e);
	if (!(e->brnsl = init_brnsl()))
		ft_malloc_error(e);
	return (e);
}
