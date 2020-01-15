/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keycom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 10:56:23 by apons             #+#    #+#             */
/*   Updated: 2019/06/05 13:35:44 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_moveframe(int key, t_info *info)
{
	if (key == 123)
		info->x_off = fmax(info->x_off - 15, -2147483605);
	else if (key == 124)
		info->x_off = fmin(info->x_off + 15, 2147483605);
	else if (key == 125)
		info->y_off = fmin(info->y_off + 15, 2147483605);
	else if (key == 126)
		info->y_off = fmax(info->y_off - 15, -2147483605);
}

void	ft_rotframe(int key, t_info *info)
{
	if (key == 12)
		info->angle_x = fmin(info->angle_x + 0.1, 100);
	else if (key == 13)
		info->angle_x = fmax(info->angle_x - 0.1, -100);
	else if (key == 0)
		info->angle_y = fmin(info->angle_y + 0.1, 100);
	else if (key == 1)
		info->angle_y = fmax(info->angle_y - 0.1, -100);
	else if (key == 6)
		info->angle_z = fmax(info->angle_z - 0.1, -100);
	else if (key == 7)
		info->angle_z = fmin(info->angle_z + 0.1, 100);
}

void	ft_misc(int key, t_info *info)
{
	if (key == 69)
		info->magnitude = fmin(info->magnitude + 0.1, 10);
	else if (key == 78)
		info->magnitude = fmax(info->magnitude - 0.1, -10);
	else if (key == 92)
		info->scale = fmin(info->scale * 1.05, 500);
	else if (key == 88)
		info->scale = fmax(info->scale / 1.05, 0.5);
	else if (key == 15)
		ft_reset(info);
}

void	ft_preset(int key, t_info *info)
{
	if (key == 34)
	{
		info->angle_x = -0.785398;
		info->angle_y = 0;
		info->angle_z = -1.0472;
	}
	else if (key == 31)
	{
		info->angle_x = 0;
		info->angle_y = 0;
		info->angle_z = 0;
	}
	else if (key == 35)
	{
		info->angle_x = 0.6;
		info->angle_y = 0.2;
		info->angle_z = 0.85;
	}
}
