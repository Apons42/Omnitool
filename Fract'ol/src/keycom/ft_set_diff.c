/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_diff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:30:10 by apons             #+#    #+#             */
/*   Updated: 2019/06/24 19:53:17 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_set_diff(int key, t_info *info)
{
	if (key == 78)
		info->d_t = (info->d_t - info->d_i >= 0
				? info->d_t - info->d_i : info->d_t + (360 - info->d_i));
	else if (key == 69)
		info->d_t = (info->d_t + info->d_i < 359
				? info->d_t + info->d_i : info->d_t - (360 - info->d_i));
	else if (key == 75)
		info->d_i = fmax(info->d_i - 1, 1);
	else if (key == 67)
		info->d_i = fmin(info->d_i + 1, 36);
	else if (key == 81)
	{
		info->d_t = 0;
		info->d_i = 12;
	}
}
