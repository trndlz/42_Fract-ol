/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <tmervin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 17:34:31 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/06 21:33:37 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <time.h>
# include <stdlib.h>
# include "mlx.h"
# include "libft.h"
# define WINW 800
# define WINH 500
# define COLBARNSLEY 0x39FF12

typedef struct			s_color2
{
	int					col[6][3];
}						t_color2;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	void				*image;
	int					*imgstr;
	int					bpp;
	int					s_l;
	int					endian;
	int					zoom;
	int					fract;
	int					a;
	int					b;
	int					c;
	struct s_mandel		*mndl;
	struct s_brnsl		*brnsl;
	struct s_color2		*color2;
}						t_env;

typedef struct			s_mandel
{
	double				x_len;
	double				y_len;
	double				x_cen;
	double				y_cen;
	double				j_cx;
	double				j_cy;
	int					it;
	int					n;
}						t_mandel;

typedef struct			s_brnsl
{
	double				x_off;
	double				y_off;
	double				x_zoom;
	double				y_zoom;
	double				x0;
	double				y0;
	double				x1;
	double				y1;
	double				a;
	double				b;
	unsigned long		it;
}						t_brnsl;

/*
** STRUCTURES INITIALIZATION
*/

t_mandel				*init_mandel(t_env *e);
t_brnsl					*init_brnsl(void);
t_env					*init_env(char **av);
int						init_fract(char **av);
void					ft_usage(void);

/*
** COLORS INITIALIZATION
*/

t_color2				*init_color(void);
t_color2				*init_color2(void);
t_color2				*init_color3(void);
t_color2				*init_color4(void);

/*
** COLORS
*/

unsigned long			inter(t_env *e, int i, int r);
unsigned long			rgb_to_hexa(t_env *e, int index);
unsigned long			i_color(t_env *e, int i);

/*
** DISPLAY INFOS
*/

void					disp_color(t_env *e, int x, int y);
void					display_infos(t_env *e);
void					display_infos2(t_env *e);

/*
** FRACTALES
*/

unsigned int			mandelbrot(t_env *e, double x0, double y0);
unsigned int			julia(t_env *e, double x0, double y0);
unsigned int			n_julia(t_env *e, double x0, double y0);
void					barnsley(t_env *e, unsigned long iter);
void					barnsley_algo(t_env *e, int rd);

/*
** IMAGES / DRAWING
*/

void					create_image(t_env *e);
void					fract_plot(t_env *e);
void					draw_point(t_env *e, int x, int y, unsigned int color);

/*
** KEYBOARD / MOUSE
*/

int						deal_key(int key, t_env *e);
void					key_fractals(int key, t_env *e);
void					key_colors(int key, t_env *e);
void					key_iter(int key, t_env *e);
void					key_move(int key, t_env *e);
void					key_zoom(int key, t_env *e);
int						deal_key(int key, t_env *e);
int						deal_key(int key, t_env *e);
int						deal_mouse(int k, int x, int y, t_env *e);

#endif
