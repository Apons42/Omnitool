/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_palette.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:46:46 by apons             #+#    #+#             */
/*   Updated: 2019/06/20 11:46:11 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_set_palette(int key, t_info *info)
{
	if (key == 83)
	{
		info->pal[0] = 0xFF0000;
		info->pal[1] = 0x00FF00;
		info->pal[2] = 0x0000FF;
	}
	else if (key == 84)
	{
		info->pal[0] = 0x000000;
		info->pal[1] = 0x000000;
		info->pal[2] = 0xFF00FF;
	}
	else if (key == 85)
	{
		info->pal[0] = 0xFFFFFF;
		info->pal[1] = 0x00FF00;
		info->pal[2] = 0xDD0000;
	}
}
