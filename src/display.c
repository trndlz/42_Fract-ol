/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 16:24:56 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/02 18:43:08 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display_infos(t_env *e)
{
	char *zoom;

	zoom = ft_itoa(e->zoom);
	mlx_string_put(e->mlx, e->win, 830, 5, 0xC8C8C8, "> ZOOM");
	mlx_string_put(e->mlx, e->win, 830, 25, 0xFFFFFF, zoom);
	free(zoom);

}

