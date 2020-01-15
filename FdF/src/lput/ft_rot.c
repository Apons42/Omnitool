/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:04:29 by apons             #+#    #+#             */
/*   Updated: 2019/05/27 14:47:49 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_lstpt	*ft_rot_x(t_lstpt *point, float theta)
{
	float x;
	float y;
	float z;

	x = point->x;
	y = point->y;
	z = point->z;
	point->x = x;
	point->y = (y * cos(theta) + z * sin(theta));
	point->z = (-y * cos(theta) + z * cos(theta));
	return (point);
}

t_lstpt	*ft_rot_y(t_lstpt *point, float theta)
{
	float x;
	float y;
	float z;

	x = point->x;
	y = point->y;
	z = point->z;
	point->x = (x * cos(theta) - z * sin(theta));
	point->y = y;
	point->z = (x * sin(theta) + z * cos(theta));
	return (point);
}

t_lstpt	*ft_rot_z(t_lstpt *point, float theta, float mag)
{
	float x;
	float y;
	float z;

	x = point->x;
	y = point->y;
	z = point->z * mag;
	point->x = (x * cos(theta) + y * sin(theta));
	point->y = (x * -sin(theta) + y * cos(theta));
	point->z = z;
	return (point);
}

t_lstpt	*ft_scale(t_lstpt *point, t_info *info)
{
	point->x = info->scale * point->x + info->x_off;
	point->y = info->scale * point->y + info->y_off;
	point->z = info->scale * point->z + 500;
	return (point);
}

t_lstpt	*ft_valuemanip(t_lstpt *point, t_info *info)
{
	point = ft_rot_z(point, info->angle_x, info->magnitude);
	point = ft_rot_y(point, info->angle_y);
	point = ft_rot_x(point, info->angle_z);
	point = ft_scale(point, info);
	return (point);
}
