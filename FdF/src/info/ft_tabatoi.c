/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabatoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 11:44:43 by apons             #+#    #+#             */
/*   Updated: 2019/05/28 11:28:11 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_info	*ft_pointtaken(t_info *info, t_line *alst, int width, int y)
{
	int x;

	x = 0;
	if (!(info->points[y] = (t_lstpt *)malloc(sizeof(t_lstpt) * (width))))
	{
		info->height = y;
		ft_puterror(info, 0, "Malloc error.");
	}
	while (x < width)
	{
		info->points[y][x].x = x;
		info->points[y][x].y = y;
		info->points[y][x].z = ft_atoi(alst->tab[x]);
		info->points[y][x].color = ft_get_colors(alst->tab[x], info);
		x++;
	}
	return (info);
}

t_lstpt			**ft_tabatoi(t_info *info, int width, int height)
{
	int		y;
	t_line	*linker;

	info->width = width;
	info->height = height;
	linker = info->val_head;
	if (!(info->points = (t_lstpt **)malloc(sizeof(t_lstpt *) * height)))
		ft_puterror(info, 0, "Malloc error.");
	y = 0;
	while (1)
	{
		info = ft_pointtaken(info, linker, width, y);
		y++;
		if (linker->next == NULL)
			break ;
		linker = linker->next;
	}
	info->scale = fmax(fmin(WIN_WIDTH / info->width,
						WIN_HEIGHT / info->height) * 0.8, 0.5);
	return (info->points);
}
