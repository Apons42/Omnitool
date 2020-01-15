/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_circle_cross.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:03:39 by apons             #+#    #+#             */
/*   Updated: 2019/05/27 14:43:40 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_oct_horizontal(int *img, t_lstpt *s, t_lstpt *f, t_info *info)
{
	while ((int)s->x < (int)f->x)
	{
		ft_fill_pix(img, s, info);
		s->x++;
	}
	while ((int)f->x < (int)s->x)
	{
		if (f->x > 0 && f->x < WIN_WIDTH && f->y > 0 && f->y < WIN_HEIGHT)
		{
			ft_redo_delta(info, -1);
			f->color = ft_get_gradient(f, info->finish, info->start, info->d);
			img = ft_img_set_color(img, f);
		}
		f->x++;
	}
}

void	ft_oct_vertical(int *img, t_lstpt *s, t_lstpt *f, t_info *info)
{
	while ((int)s->y < (int)f->y)
	{
		ft_fill_pix(img, s, info);
		s->y++;
	}
	while ((int)f->y < (int)s->y)
	{
		if (f->x > 0 && f->x < WIN_WIDTH && f->y > 0 && f->y < WIN_HEIGHT)
		{
			ft_redo_delta(info, -1);
			f->color = ft_get_gradient(f, info->finish, info->start, info->d);
			img = ft_img_set_color(img, f);
		}
		f->y++;
	}
}
