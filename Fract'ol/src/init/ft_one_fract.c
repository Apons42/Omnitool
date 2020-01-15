/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_fract.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 09:39:53 by apons             #+#    #+#             */
/*   Updated: 2019/10/25 09:21:10 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_info	*ft_one_fract(char *fract)
{
	t_info *info;

	info = ft_init_info(fract);
	info = ft_get_points(info, info->ft_fract);
	mlx_put_image_to_window(info->m_p, info->w_p, info->i_p, 0, 0);
	ft_showhelp(info);
	mlx_hook(info->w_p, 2, (1L << 0), ft_keyboard_handle, info);
	mlx_hook(info->w_p, 4, (1L << 2), ft_mouseclick_handle, info);
	mlx_hook(info->w_p, 6, (1L << 6), ft_mousemove_handle, info);
	return (info);
}
