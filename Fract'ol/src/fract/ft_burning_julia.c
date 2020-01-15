/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burning_julia.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:07:46 by apons             #+#    #+#             */
/*   Updated: 2019/06/24 09:03:40 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_point	ft_burning_julia(t_point z0, t_info *info)
{
	int		p_iter;
	t_point	z;
	t_point	cz;

	z.r = z0.r;
	z.i = z0.i;
	p_iter = 0;
	while ((z.r * z.r) + (z.i * z.i) <= 4 && p_iter != info->max_iter)
	{
		cz.r = ft_abs(z.r);
		cz.i = ft_abs(z.i);
		z.r = ((cz.r * cz.r) - (cz.i * cz.i) + info->mouse_x);
		z.i = (2 * cz.r * cz.i + info->mouse_y);
		p_iter++;
	}
	z0.r = ft_abs(z.r);
	z0.i = ft_abs(z.i);
	z0.iter = p_iter;
	return (z0);
}
