/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_set_colors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:35:40 by apons             #+#    #+#             */
/*   Updated: 2019/05/28 11:34:43 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*ft_get_img(t_info *info)
{
	int	*img;
	int bpp;
	int sl;
	int endian;

	img = (int *)mlx_get_data_addr(info->img_ptr, &bpp, &sl, &endian);
	return (img);
}

int		*ft_img_set_color(int *img, t_lstpt *s)
{
	img[WIN_WIDTH * (int)s->y + (int)s->x] = s->color;
	return (img);
}

void	ft_redo_delta(t_info *info, int neg)
{
	info->d->x = (info->finish->x - info->start->x) * neg;
	info->d->y = (info->finish->y - info->start->y) * neg;
}

void	ft_fill_pix(int *img, t_lstpt *pt, t_info *info)
{
	if (pt->x > 0 && pt->x < WIN_WIDTH && pt->y > 0 && pt->y < WIN_HEIGHT)
	{
		pt->color = ft_get_gradient(pt, info->start, info->finish, info->d);
		img = ft_img_set_color(img, pt);
	}
}
