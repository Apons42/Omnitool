/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_showtime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 11:00:40 by apons             #+#    #+#             */
/*   Updated: 2019/10/31 10:26:29 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_showtime(int key, t_info *info)
{
	int *img;

	img = ft_get_img(info);
	if (key == 53)
	{
		ft_freeall(info, 0);
		exit(0);
	}
	else if (key == 4)
		info->allow_help *= -1;
	else
	{
		ft_moveframe(key, info);
		ft_rotframe(key, info);
		ft_misc(key, info);
		ft_preset(key, info);
		ft_bzero(img, WIN_WIDTH * WIN_HEIGHT * sizeof(int));
		ft_drawgrid(info);
	}
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_ptr, 0, 0);
	ft_showhelp(info);
	return (0);
}
