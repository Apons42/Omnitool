/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:41:26 by apons             #+#    #+#             */
/*   Updated: 2019/05/29 10:05:48 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_info	*ft_init_non_malloc(int width, int height, t_info *info)
{
	info->width = width;
	info->height = height;
	info->scale = 0;
	info->x_off = WIN_WIDTH / 2;
	info->y_off = WIN_HEIGHT / 2;
	info->allow_help = 1;
	info->angle_x = -0.785398;
	info->angle_y = 0;
	info->angle_z = -1.0472;
	info->magnitude = 0.2;
	return (info);
}

t_info	*ft_init_malloc(t_info *info)
{
	info->mlx_ptr = NULL;
	info->win_ptr = NULL;
	info->img_ptr = NULL;
	info->liner = NULL;
	info->line = NULL;
	info->val_head = NULL;
	info->tab = NULL;
	info->points = NULL;
	info->start = NULL;
	info->finish = NULL;
	info->d = NULL;
	info->current = NULL;
	info->c_finish = NULL;
	return (info);
}

t_info	*ft_init_mlx(t_info *info)
{
	int *img;

	info->mlx_ptr = mlx_init();
	info->win_ptr = mlx_new_window(info->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
									"FDF project ; Made by Apons.");
	info->img_ptr = mlx_new_image(info->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	img = ft_get_img(info);
	ft_bzero(img, WIN_WIDTH * WIN_HEIGHT);
	return (info);
}

t_info	*ft_init_info(int width, int height)
{
	t_info *info;

	if (!(info = (t_info *)malloc(sizeof(t_info))))
		ft_puterror(NULL, 0, "Malloc error");
	info = ft_init_non_malloc(width, height, info);
	info = ft_init_malloc(info);
	return (info);
}
