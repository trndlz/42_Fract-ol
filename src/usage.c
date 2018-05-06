/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <tmervin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 22:18:44 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/06 22:28:52 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_usage(void)
{
	ft_putstr("fractol <Mandelbrot/Julia/N-Julia/Barnsley>\n");
	exit(1);
}

void		ft_malloc_error(void)
{
	ft_putstr("Problem while malloc\n");
	exit(1);
}
