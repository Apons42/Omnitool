/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_available.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 10:55:03 by apons             #+#    #+#             */
/*   Updated: 2019/06/18 15:27:09 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_available(t_info *info)
{
	ft_putendl("Usage : ./fractol [fractal name]\n\n           Available :");
	ft_putendl("-Mandelbrot\n-Julia\n-Burning_Ship\n-Burning_Julia\n");
	ft_puterror(info, 0, "Maybe you've made a typo ?");
}
