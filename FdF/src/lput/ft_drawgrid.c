/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawgrid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 11:51:17 by apons             #+#    #+#             */
/*   Updated: 2019/05/27 14:46:13 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_lstpt	*ft_getpoint(int x, int y, t_info *info)
{
	t_lstpt	*point;

	if (!(point = (t_lstpt *)malloc(sizeof(t_lstpt) * 1)))
		ft_puterror(info, 0, "Malloc error");
	point->x = info->points[y][x].x - info->width / 2;
	point->y = info->points[y][x].y - info->height / 2;
	point->z = info->points[y][x].z;
	point->color = info->points[y][x].color;
	return (point);
}

int		ft_isinside(t_lstpt *point)
{
	return (point->x >= -100 && point->x <= WIN_WIDTH + 100
			&& point->y >= -100 && point->y <= WIN_HEIGHT + 100);
}

void	ft_drawline(const int y, t_info *info)
{
	int		a;

	a = 1;
	info->start = ft_getpoint(0, y, info);
	info->start = ft_valuemanip(info->start, info);
	while (a < info->width)
	{
		info->finish = ft_getpoint(a, y, info);
		info->finish = ft_valuemanip(info->finish, info);
		if (ft_isinside(info->start) && ft_isinside(info->finish))
			ft_line_put(info);
		free(info->start);
		info->start = info->finish;
		info->finish = NULL;
		a++;
	}
	free(info->start);
	info->start = NULL;
}

void	ft_drawcoln(const int x, t_info *info)
{
	int		b;

	b = 1;
	info->start = ft_getpoint(x, 0, info);
	info->start = ft_valuemanip(info->start, info);
	while (b < info->height)
	{
		info->finish = ft_getpoint(x, b, info);
		info->finish = ft_valuemanip(info->finish, info);
		if (ft_isinside(info->start) && ft_isinside(info->finish))
			ft_line_put(info);
		free(info->start);
		info->start = info->finish;
		info->finish = NULL;
		b++;
	}
	free(info->start);
	info->start = NULL;
}

void	ft_drawgrid(t_info *info)
{
	int x;
	int y;

	y = 0;
	while (y < info->height)
	{
		ft_drawline(y, info);
		y++;
	}
	x = 0;
	while (x < info->width)
	{
		ft_drawcoln(x, info);
		x++;
	}
}
