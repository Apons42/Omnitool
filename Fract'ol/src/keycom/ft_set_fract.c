/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_fract.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:28:21 by apons             #+#    #+#             */
/*   Updated: 2019/06/20 11:46:37 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_set_fract(int key, t_info *info)
{
	if (key == 18 && info->ft_fract)
		info = ft_init_mandelbrot(info);
	if (key == 19 && info->ft_fract)
		info = ft_init_julia(info);
	if (key == 20 && info->ft_fract)
		info = ft_init_burning_ship(info);
	if (key == 21 && info->ft_fract)
		info = ft_init_burning_julia(info);
}
