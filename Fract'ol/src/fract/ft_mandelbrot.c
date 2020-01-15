/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 14:35:47 by apons             #+#    #+#             */
/*   Updated: 2019/07/01 09:36:22 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_point	ft_mandelbrot(t_point c, t_info *info)
{
	int		p_iter;
	t_point	z;
	t_point	cz;

	z.r = 0;
	z.i = 0;
	p_iter = 0;
	while ((z.r * z.r) + (z.i * z.i) <= 4 && p_iter != info->max_iter)
	{
		cz.r = z.r;
		cz.i = z.i;
		z.r = ((cz.r * cz.r) - (cz.i * cz.i) + c.r);
		z.i = (2 * cz.r * cz.i + c.i);
		p_iter++;
	}
	c.r = z.r;
	c.i = z.i;
	c.iter = p_iter;
	return (c);
}
