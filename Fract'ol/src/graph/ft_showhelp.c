/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_showhelp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 10:51:05 by apons             #+#    #+#             */
/*   Updated: 2019/07/01 09:47:13 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_showjulia(t_info *info)
{
	if (info->allow_julia > 0)
		mlx_string_put(info->m_p, info->w_p, 5, 60, 0x9D0BD7,
			"Left Click : Freeze Julia");
	else
		mlx_string_put(info->m_p, info->w_p, 5, 60, 0x9D0BD7,
			"Left Click : Unfreeze Julia");
}

void		ft_showhelp(t_info *info)
{
	if (info->allow_help > 0)
	{
		mlx_string_put(info->m_p, info->w_p, 5, 0, 0x9D0BD7,
				"Right Click : Hide help");
		mlx_string_put(info->m_p, info->w_p, 5, 15, 0x9D0BD7,
				"1-4 : Select/Reset Fractal");
		mlx_string_put(info->m_p, info->w_p, 5, 30, 0x9D0BD7,
				"Arrow Keys : Move fractal");
		mlx_string_put(info->m_p, info->w_p, 5, 45, 0x9D0BD7,
				"I,O,P : Increase/Reset/Decrease Iterations");
		ft_showjulia(info);
		mlx_string_put(info->m_p, info->w_p, 5, 95, 0x9D0BD7, "Numpad :");
		mlx_string_put(info->m_p, info->w_p, 5, 110, 0x9D0BD7,
				"1-3 : Select color palette");
		mlx_string_put(info->m_p, info->w_p, 5, 125, 0x9D0BD7,
				"+,- : Rotate colors");
		mlx_string_put(info->m_p, info->w_p, 5, 140, 0x9D0BD7,
				"*,/ : Change Color scale");
		mlx_string_put(info->m_p, info->w_p, 5, 155, 0x9D0BD7,
				"= : Reset rotation & scale");
	}
	else
		mlx_string_put(info->m_p, info->w_p, 5, 0, 0x9D0BD7,
			"Right Click : Show help");
}
