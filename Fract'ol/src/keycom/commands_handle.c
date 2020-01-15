/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 13:39:59 by apons             #+#    #+#             */
/*   Updated: 2019/09/02 08:31:44 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_keyboard_handle(int key, t_info *info)
{
	if (key == 53)
		ft_exit(info);
	else
	{
		ft_move_fract(key, info);
		ft_set_fract(key, info);
		ft_set_iter(key, info);
		ft_set_diff(key, info);
		ft_set_palette(key, info);
		ft_update_fract(info);
	}
	ft_update_graph(info);
	return (0);
}

int	ft_mouseclick_handle(int button, int x, int y, t_info *info)
{
	//ft_toggle_allows(button, info);
	if (info->allow_julia > 0)
	{
		info->mouse_x = (double)x * 2 / WIN_W - 1;
		info->mouse_y = (double)y * 2 / WIN_H - 1;
	}
	ft_toggle_allows(button, info);
	if (button != 2)
	{
		ft_set_zoom(button, info);
		ft_update_fract(info);
	}
	ft_update_graph(info);
	return (0);
}

int	ft_mousemove_handle(int x, int y, t_info *info)
{
	void *ft;

	ft = info->ft_fract;
	if ((ft == ft_julia || ft == ft_burning_julia) && info->allow_julia > 0)
	{
		info->mouse_x = (double)x * 2 / WIN_W - 1;
		info->mouse_y = (double)y * 2 / WIN_H - 1;
		ft_update_fract(info);
		ft_update_graph(info);
	}
	return (0);
}
