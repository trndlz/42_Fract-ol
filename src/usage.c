/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <tmervin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 22:18:44 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/06 23:22:45 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_usage(void)
{
	ft_putstr("fractol <Mandelbrot/Julia/N-Julia/Barnsley/Tricorn>\n");
	exit(1);
}

void		ft_malloc_error(void)
{
	ft_putstr("Problem while malloc\n");
	exit(1);
}
