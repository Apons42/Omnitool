/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 12:58:39 by apons             #+#    #+#             */
/*   Updated: 2019/06/24 18:55:18 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_free_info(t_info *info, int nb)
{
	if (info && nb >= 0)
	{
		ft_free_tpts(info->t_pts, info->t_pts_h);
		if (info->conv)
			free(info->conv);
		if (info->tsv)
			free(info->tsv);
		if (info->rgb)
			free(info->rgb);
		if (info->pal)
			free(info->pal);
		if (info->i_p)
			mlx_destroy_image(info->m_p, info->i_p);
		if (info->w_p)
			mlx_destroy_window(info->m_p, info->w_p);
		free(info);
		info = NULL;
	}
}
