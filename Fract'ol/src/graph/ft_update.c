/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 10:42:40 by apons             #+#    #+#             */
/*   Updated: 2019/06/24 09:17:06 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_update_fract(t_info *info)
{
	int *img;

	img = ft_get_img(info);
	ft_bzero(img, WIN_W * WIN_H * sizeof(int));
	info = ft_get_points(info, info->ft_fract);
}

void	ft_update_graph(t_info *info)
{
	int *img;

	img = ft_get_img(info);
	mlx_put_image_to_window(info->m_p, info->w_p, info->i_p, 0, 0);
	ft_showhelp(info);
}
