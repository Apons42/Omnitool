/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:18:39 by apons             #+#    #+#             */
/*   Updated: 2019/05/27 10:53:09 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Last two calls are necessary because the last pixel of the line isn't
** drawn by the layers of 'if'.
*/

static void	ft_pointcpy(t_info *info)
{
	if (!(info->d = (t_lstpt *)malloc(sizeof(t_lstpt))))
		ft_puterror(info, 0, "Malloc error");
	if (!(info->current = (t_lstpt *)malloc(sizeof(t_lstpt))))
		ft_puterror(info, 0, "Malloc error");
	if (!(info->c_finish = (t_lstpt *)malloc(sizeof(t_lstpt))))
		ft_puterror(info, 0, "Malloc error");
	info->current->x = info->start->x;
	info->current->y = info->start->y;
	info->current->z = info->start->z;
	info->c_finish->x = info->finish->x;
	info->c_finish->y = info->finish->y;
	info->c_finish->z = info->finish->z;
	info->d->x = info->finish->x - info->start->x;
	info->d->y = info->finish->y - info->start->y;
	info->d->z = info->finish->z - info->start->z;
}

static void	ft_free_pointcpy(t_info *info)
{
	ft_ptfree(info->current);
	info->current = NULL;
	ft_ptfree(info->c_finish);
	info->c_finish = NULL;
	ft_ptfree(info->d);
	info->d = NULL;
}

void		ft_line_put(t_info *info)
{
	int *img;

	img = ft_get_img(info);
	ft_pointcpy(info);
	ft_fill_pix(img, info->current, info);
	if (info->d->x != 0)
	{
		if (info->d->x > 0)
			ft_oct_sideright(img, info);
		else
			ft_oct_sideleft(img, info);
	}
	else
	{
		if (info->d->y != 0)
		{
			if (info->d->y > 0)
				ft_oct_vertical(img, info->current, info->c_finish, info);
			else
				ft_oct_vertical(img, info->current, info->c_finish, info);
		}
	}
	ft_fill_pix(img, info->finish, info);
	ft_free_pointcpy(info);
}
