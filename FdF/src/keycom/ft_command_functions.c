/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 10:44:13 by apons             #+#    #+#             */
/*   Updated: 2019/05/28 11:34:45 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_showhelp(t_info *info)
{
	void *m;
	void *w;

	m = info->mlx_ptr;
	w = info->win_ptr;
	if (info->allow_help > 0)
	{
		mlx_string_put(m, w, 10, 10, 0x68D7C0, "H : Hide help");
		mlx_string_put(m, w, 10, 35, 0x68D7C0, "I, O, P : Swap projections");
		mlx_string_put(m, w, 10, 60, 0x68D7C0, "9/6 : Zoom in/out");
		mlx_string_put(m, w, 10, 85, 0x68D7C0, "Arrow Keys : Move wireframe");
		mlx_string_put(m, w, 10, 110, 0x68D7C0, "Q, W : x Axis rotation");
		mlx_string_put(m, w, 10, 135, 0x68D7C0, "A, S : y Axis rotation");
		mlx_string_put(m, w, 10, 160, 0x68D7C0, "Z, X : z Axis rotation");
		mlx_string_put(m, w, 10, 185, 0x68D7C0, "+ : Increase magnitude");
		mlx_string_put(m, w, 10, 210, 0x68D7C0, "- : Decrease magnitude");
		mlx_string_put(m, w, 10, 235, 0x68D7C0, "R : center wireframe");
	}
	else
		mlx_string_put(m, w, 10, 10, 0x68D7C0, "H : Show help");
	mlx_string_put(m, w, 10, 1270, 0xDC1904,
	"Dots outside the window will not be linked. Expect the unexpected !");
}

void	ft_reset(t_info *info)
{
	info->x_off = WIN_WIDTH / 2;
	info->y_off = WIN_HEIGHT / 2;
}
