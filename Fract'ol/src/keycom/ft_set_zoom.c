/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_zoom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:49:25 by apons             #+#    #+#             */
/*   Updated: 2019/06/18 16:06:36 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "stdio.h"

void			ft_set_zoom(int button, t_info *info)
{
	if (button == 4)
		info->zoom = fmin(info->zoom * 1.15, 165368232858250.000000);
	else if (button == 5)
		info->zoom = fmax(info->zoom / 1.15, 0.250);
}
