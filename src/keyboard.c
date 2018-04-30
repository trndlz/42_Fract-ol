/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:24:59 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/30 17:56:43 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int		deal_key(int key, t_env *e)
{
	printf("KEY %d\n", key);
	if (key == 69)
		e->mandel->zoom += 50;
	if (key == 123)
		e->x -= 100;
	if (key == 124)
		e->x += 100;
	if (key == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(1);
	}
	mandel_plot(e);
	return (0);
}
