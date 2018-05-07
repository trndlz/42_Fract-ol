/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <tmervin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 22:18:44 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/07 12:02:17 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_usage(void)
{
	ft_putstr_fd("./fractol <0 or Mandelbrot>\n", 2);
	ft_putstr_fd("./fractol <1 or Julia>\n", 2);
	ft_putstr_fd("./fractol <2 or N-Julia>\n", 2);
	ft_putstr_fd("./fractol <3 or Barnsley>\n", 2);
	ft_putstr_fd("./fractol <4 or Burning-Ship>\n", 2);
	ft_putstr_fd("./fractol <5 or Tricorn>\n", 2);
	exit(1);
}

void		ft_malloc_error(void)
{
	ft_putstr_fd("Problem while malloc\n", 2);
	exit(1);
}
