/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_points.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:22:48 by apons             #+#    #+#             */
/*   Updated: 2019/06/24 09:16:02 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_info	*ft_get_points(t_info *info, t_point f(t_point z, t_info *info))
{
	int x;
	int y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			info->t_pts[y][x].r =
				(x - WIN_W / 2) / (0.5 * info->zoom * WIN_W) + info->d_x;
			info->t_pts[y][x].i =
				(y - WIN_H / 2) / (0.5 * info->zoom * WIN_H) + info->d_y;
			info->t_pts[y][x].iter = 0;
			info->t_pts[y][x] = f(info->t_pts[y][x], info);
			ft_draw_fract(info, x, y);
			x++;
		}
		y++;
	}
	return (info);
}
