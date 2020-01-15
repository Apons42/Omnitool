/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 15:19:51 by apons             #+#    #+#             */
/*   Updated: 2019/06/13 11:52:17 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_set_iter(int key, t_info *info)
{
	if (key == 34)
		info->max_iter = fmin(info->max_iter + 1, LIM_ITER);
	else if (key == 31)
		info->max_iter = info->start_iter;
	else if (key == 35)
		info->max_iter = fmax(info->max_iter - 1, 0);
}
