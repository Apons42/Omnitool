/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 13:22:07 by apons             #+#    #+#             */
/*   Updated: 2019/06/24 09:05:35 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_point	ft_julia(t_point z0, t_info *info)
{
	int		p_iter;
	t_point	z;
	t_point	cz;

	z.r = z0.r;
	z.i = z0.i;
	p_iter = 0;
	while ((z.r * z.r) + (z.i * z.i) <= 4 && p_iter != info->max_iter)
	{
		cz.r = z.r;
		cz.i = z.i;
		z.r = ((cz.r * cz.r) - (cz.i * cz.i) + info->mouse_x);
		z.i = (2 * cz.r * cz.i + info->mouse_y);
		p_iter++;
	}
	z0.r = z.r;
	z0.i = z.i;
	z0.iter = p_iter;
	return (z0);
}
