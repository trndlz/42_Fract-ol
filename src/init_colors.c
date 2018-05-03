/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 15:54:06 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/03 15:54:08 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color2		*init_color(void)
{
	t_color2 *color2;

	if (!(color2 = (t_color2*)malloc(sizeof(t_color2))))
		return (NULL);
	color2->col[0][0] = 46;
	color2->col[0][1] = 17;
	color2->col[0][2] = 45;
	color2->col[1][0] = 84;
	color2->col[1][1] = 0;
	color2->col[1][2] = 50;
	color2->col[2][0] = 130;
	color2->col[2][1] = 3;
	color2->col[2][2] = 151;
	color2->col[3][0] = 201;
	color2->col[3][1] = 40;
	color2->col[3][2] = 62;
	color2->col[4][0] = 240;
	color2->col[4][1] = 67;
	color2->col[4][2] = 58;
	color2->col[5][0] = 240;
	color2->col[5][1] = 139;
	color2->col[5][2] = 134;
	return (color2);
}

t_color2		*init_color2(void)
{
	t_color2 *color2;

	if (!(color2 = (t_color2*)malloc(sizeof(t_color2))))
		return (NULL);
	color2->col[0][0] = 253;
	color2->col[0][1] = 184;
	color2->col[0][2] = 19;
	color2->col[1][0] = 243;
	color2->col[1][1] = 112;
	color2->col[1][2] = 32;
	color2->col[2][0] = 201;
	color2->col[2][1] = 35;
	color2->col[2][2] = 75;
	color2->col[3][0] = 99;
	color2->col[3][1] = 95;
	color2->col[3][2] = 171;
	color2->col[4][0] = 0;
	color2->col[4][1] = 137;
	color2->col[4][2] = 207;
	color2->col[5][0] = 10;
	color2->col[5][1] = 176;
	color2->col[5][2] = 74;
	return (color2);
}

t_color2		*init_color3(void)
{
	t_color2 *color2;

	if (!(color2 = (t_color2*)malloc(sizeof(t_color2))))
		return (NULL);
	color2->col[0][0] = 4;
	color2->col[0][1] = 78;
	color2->col[0][2] = 129;
	color2->col[1][0] = 241;
	color2->col[1][1] = 133;
	color2->col[1][2] = 156;
	color2->col[2][0] = 246;
	color2->col[2][1] = 193;
	color2->col[2][2] = 197;
	color2->col[3][0] = 249;
	color2->col[3][1] = 236;
	color2->col[3][2] = 238;
	color2->col[4][0] = 168;
	color2->col[4][1] = 204;
	color2->col[4][2] = 174;
	color2->col[5][0] = 141;
	color2->col[5][1] = 186;
	color2->col[5][2] = 149;
	return (color2);
}

t_color2		*init_color4(void)
{
	t_color2 *color2;

	if (!(color2 = (t_color2*)malloc(sizeof(t_color2))))
		return (NULL);
	color2->col[0][0] = 212;
	color2->col[0][1] = 212;
	color2->col[0][2] = 212;
	color2->col[1][0] = 180;
	color2->col[1][1] = 180;
	color2->col[1][2] = 180;
	color2->col[2][0] = 144;
	color2->col[2][1] = 144;
	color2->col[2][2] = 144;
	color2->col[3][0] = 99;
	color2->col[3][1] = 99;
	color2->col[3][2] = 99;
	color2->col[4][0] = 72;
	color2->col[4][1] = 72;
	color2->col[4][2] = 72;
	color2->col[5][0] = 230;
	color2->col[5][1] = 230;
	color2->col[5][2] = 230;
	return (color2);
}
