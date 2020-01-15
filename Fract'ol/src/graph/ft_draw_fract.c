/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_fract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:07:31 by apons             #+#    #+#             */
/*   Updated: 2019/06/24 09:16:41 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_draw_fract(t_info *info, int x, int y)
{
	int		*img;
	double	zr;
	double	zi;

	zr = info->t_pts[y][x].r;
	zi = info->t_pts[y][x].i;
	if ((zr * zr) + (zi * zi) >= 4)
	{
		img = ft_get_img(info);
		img[WIN_W * y + x] = ft_get_color(info, x, y);
	}
}
