/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <tmervin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:42:49 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/07 13:25:18 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_env *e;

	e = NULL;
	if (ac != 2 || init_fract(av) == -1)
		ft_usage();
	if (!(e = init_env(av)))
		ft_malloc_error_env();
	create_image(e);
	mlx_hook(e->win, 2, 3, deal_key, e);
	mlx_mouse_hook(e->win, deal_mouse, e);
	mlx_loop(e->mlx);
	free_structures(e);
	return (0);
}
