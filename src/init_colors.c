/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <tmervin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 15:54:06 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/09 20:02:09 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color		*init_color(void)
{
	t_color *color;

	if (!(color = (t_color*)malloc(sizeof(t_color))))
		return (NULL);
	color->col[0][0] = 46;
	color->col[0][1] = 17;
	color->col[0][2] = 45;
	color->col[1][0] = 84;
	color->col[1][1] = 0;
	color->col[1][2] = 50;
	color->col[2][0] = 130;
	color->col[2][1] = 3;
	color->col[2][2] = 151;
	color->col[3][0] = 201;
	color->col[3][1] = 40;
	color->col[3][2] = 62;
	color->col[4][0] = 240;
	color->col[4][1] = 67;
	color->col[4][2] = 58;
	color->col[5][0] = 240;
	color->col[5][1] = 139;
	color->col[5][2] = 134;
	return (color);
}

t_color		*init_color2(void)
{
	t_color *color;

	if (!(color = (t_color*)malloc(sizeof(t_color))))
		return (NULL);
	color->col[0][0] = 253;
	color->col[0][1] = 184;
	color->col[0][2] = 19;
	color->col[1][0] = 243;
	color->col[1][1] = 112;
	color->col[1][2] = 32;
	color->col[2][0] = 201;
	color->col[2][1] = 35;
	color->col[2][2] = 75;
	color->col[3][0] = 99;
	color->col[3][1] = 95;
	color->col[3][2] = 171;
	color->col[4][0] = 0;
	color->col[4][1] = 137;
	color->col[4][2] = 207;
	color->col[5][0] = 10;
	color->col[5][1] = 176;
	color->col[5][2] = 74;
	return (color);
}

t_color		*init_color3(void)
{
	t_color *color;

	if (!(color = (t_color*)malloc(sizeof(t_color))))
		return (NULL);
	color->col[0][0] = 4;
	color->col[0][1] = 78;
	color->col[0][2] = 129;
	color->col[1][0] = 241;
	color->col[1][1] = 133;
	color->col[1][2] = 156;
	color->col[2][0] = 246;
	color->col[2][1] = 193;
	color->col[2][2] = 197;
	color->col[3][0] = 249;
	color->col[3][1] = 236;
	color->col[3][2] = 238;
	color->col[4][0] = 168;
	color->col[4][1] = 204;
	color->col[4][2] = 174;
	color->col[5][0] = 141;
	color->col[5][1] = 186;
	color->col[5][2] = 149;
	return (color);
}

t_color		*init_color4(void)
{
	t_color *color;

	if (!(color = (t_color*)malloc(sizeof(t_color))))
		return (NULL);
	color->col[0][0] = 212;
	color->col[0][1] = 212;
	color->col[0][2] = 212;
	color->col[1][0] = 180;
	color->col[1][1] = 180;
	color->col[1][2] = 180;
	color->col[2][0] = 144;
	color->col[2][1] = 144;
	color->col[2][2] = 144;
	color->col[3][0] = 99;
	color->col[3][1] = 99;
	color->col[3][2] = 99;
	color->col[4][0] = 72;
	color->col[4][1] = 72;
	color->col[4][2] = 72;
	color->col[5][0] = 230;
	color->col[5][1] = 230;
	color->col[5][2] = 230;
	return (color);
}
