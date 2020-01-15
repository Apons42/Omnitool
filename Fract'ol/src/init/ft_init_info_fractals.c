/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_info_fractals.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:46:28 by apons             #+#    #+#             */
/*   Updated: 2019/07/01 13:02:10 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_info	*ft_init_mandelbrot(t_info *info)
{
	info->zoom = 0.783;
	info->d_x = -0.75;
	info->d_y = 0.00;
	info->ft_fract = ft_mandelbrot;
	return (info);
}

t_info	*ft_init_julia(t_info *info)
{
	info->zoom = 0.750;
	info->d_x = 0.00;
	info->d_y = 0.00;
	info->mouse_x = 0.35;
	info->mouse_y = 0.06;
	info->ft_fract = ft_julia;
	return (info);
}

t_info	*ft_init_burning_ship(t_info *info)
{
	info->zoom = 0.625;
	info->d_x = -0.425;
	info->d_y = -0.50;
	info->ft_fract = ft_burning_ship;
	return (info);
}

t_info	*ft_init_burning_julia(t_info *info)
{
	info->zoom = 0.750;
	info->d_x = 0.00;
	info->d_y = 0.00;
	info->mouse_x = 0.35;
	info->mouse_y = 0.06;
	info->ft_fract = ft_burning_julia;
	return (info);
}
