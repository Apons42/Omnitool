/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_fract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 13:16:45 by apons             #+#    #+#             */
/*   Updated: 2019/06/24 10:15:08 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_move_fract(int key, t_info *info)
{
	if (key == 123)
		info->d_x = fmax(info->d_x - 0.05 / info->zoom, -10);
	else if (key == 124)
		info->d_x = fmin(info->d_x + 0.05 / info->zoom, 10);
	else if (key == 125)
		info->d_y = fmin(info->d_y + 0.05 / info->zoom, 10);
	else if (key == 126)
		info->d_y = fmax(info->d_y - 0.05 / info->zoom, -10);
}
