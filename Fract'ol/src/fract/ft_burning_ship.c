/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burning_ship.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 14:35:47 by apons             #+#    #+#             */
/*   Updated: 2019/06/24 09:04:39 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_point	ft_burning_ship(t_point c, t_info *info)
{
	int		p_iter;
	t_point	z;
	t_point	cz;

	z.r = 0;
	z.i = 0;
	p_iter = 0;
	while ((z.r * z.r) + (z.i * z.i) <= 4 && p_iter != info->max_iter)
	{
		cz.r = ft_abs(z.r);
		cz.i = ft_abs(z.i);
		z.r = ((cz.r * cz.r) - (cz.i * cz.i) + c.r);
		z.i = (2 * cz.r * cz.i + c.i);
		p_iter++;
	}
	c.r = ft_abs(z.r);
	c.i = ft_abs(z.i);
	c.iter = p_iter;
	return (c);
}
