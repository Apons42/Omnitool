/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_circle_east.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:10:14 by apons             #+#    #+#             */
/*   Updated: 2019/05/27 14:44:20 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** dx >= dy
*/

void	ft_oct1(int *img, t_info *info)
{
	int	err;

	err = info->d->x;
	info->d->x = info->d->x * 2;
	info->d->y = info->d->y * 2;
	while ((int)info->current->x < (int)info->c_finish->x)
	{
		ft_fill_pix(img, info->current, info);
		if ((err -= info->d->y) < 0)
		{
			info->current->y++;
			err += info->d->x;
		}
		info->current->x++;
	}
}

/*
** dx <= dy
*/

void	ft_oct2(int *img, t_info *info)
{
	int err;

	err = info->d->y;
	info->d->y = info->d->y * 2;
	info->d->x = info->d->x * 2;
	while ((int)info->current->y < (int)info->c_finish->y)
	{
		ft_fill_pix(img, info->current, info);
		if ((err -= info->d->x) < 0)
		{
			info->current->x++;
			err += info->d->y;
		}
		info->current->y++;
	}
}

/*
** dy < 0
** dx <= -dy
*/

void	ft_oct7(int *img, t_info *info)
{
	int err;

	err = info->d->y;
	info->d->y = info->d->y * 2;
	info->d->x = info->d->x * 2;
	while ((int)info->current->y > (int)info->c_finish->y)
	{
		ft_fill_pix(img, info->current, info);
		if ((err += info->d->x) > 0)
		{
			info->current->x++;
			err += info->d->y;
		}
		info->current->y--;
	}
}

/*
** dy < 0
** dx >= -dy
*/

void	ft_oct8(int *img, t_info *info)
{
	int	err;

	err = info->d->x;
	info->d->x = info->d->x * 2;
	info->d->y = info->d->y * 2;
	while ((int)info->current->x < (int)info->c_finish->x)
	{
		ft_fill_pix(img, info->current, info);
		if ((err += info->d->y) < 0)
		{
			info->current->y--;
			err += info->d->x;
		}
		info->current->x++;
	}
}

void	ft_oct_sideright(int *img, t_info *info)
{
	if (info->d->y != 0)
	{
		if (info->d->y > 0)
		{
			if (info->d->x >= info->d->y)
				ft_oct1(img, info);
			else
				ft_oct2(img, info);
		}
		else
		{
			if (info->d->x >= -info->d->y)
				ft_oct8(img, info);
			else
				ft_oct7(img, info);
		}
	}
	else
		ft_oct_horizontal(img, info->current, info->c_finish, info);
}
