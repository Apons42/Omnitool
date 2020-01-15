/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_circle_west.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:20:38 by apons             #+#    #+#             */
/*   Updated: 2019/05/21 12:12:05 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** dx < 0
** -dx <= dy
*/

void	ft_oct3(int *img, t_info *info)
{
	int	err;

	err = info->d->y;
	info->d->y = info->d->y * 2;
	info->d->x = info->d->x * 2;
	while ((int)info->current->y < (int)info->c_finish->y)
	{
		ft_fill_pix(img, info->current, info);
		if ((err += info->d->x) <= 0)
		{
			info->current->x--;
			err += info->d->y;
		}
		info->current->y++;
	}
}

/*
** dx < 0
** -dx >= dy
*/

void	ft_oct4(int *img, t_info *info)
{
	int	err;

	err = info->d->x;
	info->d->x = info->d->x * 2;
	info->d->y = info->d->y * 2;
	while ((int)info->current->x > (int)info->c_finish->x)
	{
		ft_fill_pix(img, info->current, info);
		if ((err += info->d->y) >= 0)
		{
			info->current->y++;
			err += info->d->x;
		}
		info->current->x--;
	}
}

/*
** dx < 0 ; dy < 0
** dx <= dy
*/

void	ft_oct5(int *img, t_info *info)
{
	int	err;

	err = info->d->x;
	info->d->x = info->d->x * 2;
	info->d->y = info->d->y * 2;
	while ((int)info->current->x > (int)info->c_finish->x)
	{
		ft_fill_pix(img, info->current, info);
		if ((err -= info->d->y) >= 0)
		{
			info->current->y--;
			err += info->d->x;
		}
		info->current->x--;
	}
}

/*
** dx < 0 ; dy < 0
** dx >= dy
*/

void	ft_oct6(int *img, t_info *info)
{
	int err;

	err = info->d->y;
	info->d->y = info->d->y * 2;
	info->d->x = info->d->x * 2;
	while ((int)info->current->y > (int)info->c_finish->y)
	{
		ft_fill_pix(img, info->current, info);
		if ((err -= info->d->x) >= 0)
		{
			info->current->x--;
			err += info->d->y;
		}
		info->current->y--;
	}
}

void	ft_oct_sideleft(int *img, t_info *info)
{
	if (info->d->y != 0)
	{
		if (info->d->y > 0)
		{
			if (-info->d->x >= info->d->y)
				ft_oct4(img, info);
			else
				ft_oct3(img, info);
		}
		else
		{
			if (info->d->x <= info->d->y)
				ft_oct5(img, info);
			else
				ft_oct6(img, info);
		}
	}
	else
	{
		ft_oct_horizontal(img, info->current, info->c_finish, info);
	}
}
