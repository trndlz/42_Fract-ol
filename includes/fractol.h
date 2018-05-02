/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 17:34:31 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/02 18:10:26 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# define WINW 800
# define WINH 500

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
	int					zoom;
	struct s_mandel		*mndl;
	struct s_color		*color;
}						t_env;

typedef struct			s_mandel
{
	double				x_len;
	double				y_len;
	double				x_cen;
	double				y_cen;
}						t_mandel;



/*
** STRUCTURES INITIALIZATION
*/

t_mandel				*init_mandel(void);
t_color					*init_color(void);
t_env					*init_env(void);

void					create_image(t_env *e);
void					fract_plot(t_env *e);
unsigned int			mandelbrot(t_env *e, double x0, double y0);
void					draw_point(t_env *e, int x, int y, unsigned int color);
int						deal_key(int key, t_env *e);
unsigned long			get_color(t_env *e, int i);
int						deal_mouse(int k, int x, int y, t_env *e);

#endif
