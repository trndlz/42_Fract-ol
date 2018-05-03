/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:42:49 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/03 13:47:57 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_env *e;

	if (ac != 2)
		ft_usage();
	e = init_env();
	init_fract(e, av);
	create_image(e);
	mlx_hook(e->win, 2, 3, deal_key, e);
	mlx_mouse_hook(e->win, deal_mouse, e);
	mlx_loop(e->mlx);
	return (0);
}
