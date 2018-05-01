/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 17:34:31 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/01 16:14:31 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# define WIN_WIDTH 2048
# define WIN_HEIGHT 1024

typedef struct			s_color
{
	int					col[6];
}						t_color;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	void				*image;
	int					*imgstr;
	int					bpp;
	int					s_l;
	int					endian;
	int					it_max;
	int					x;
	int					y;
	int					zoom;
	struct s_mandel		*mandel;
	struct s_color		*color;
}						t_env;

typedef struct			s_mandel
{
	double				x1;
	double				x2;
	double				y1;
	double				y2;
	double				zx;
	double				zy;
	double				cr;
	double				ci;
	double				zr;
	double				zi;
	double				tmp;
}						t_mandel;



/*
** STRUCTURES INITIALIZATION
*/

t_mandel				*init_mandel(void);
t_color					*init_color(void);
t_env					*init_env(void);

int						deal_key(int key, t_env *e);
unsigned long			get_color(t_env *e, int i);
int						mandel_rang(t_env *e);
void					mandel_plot(t_env *e);
int						deal_mouse(int k, int x, int y, t_env *e);

#endif
