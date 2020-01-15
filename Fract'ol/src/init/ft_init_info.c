/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 12:49:50 by apons             #+#    #+#             */
/*   Updated: 2019/07/01 13:03:05 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_info	*ft_init_info_mal(t_info *info)
{
	if (!(info->conv = (t_conv *)malloc(sizeof(t_conv))))
		ft_puterror(info, 0, "Malloc error");
	if (!(info->tsv = (t_tsv *)malloc(sizeof(t_tsv))))
		ft_puterror(info, 0, "Malloc error");
	if (!(info->rgb = (t_tsv *)malloc(sizeof(t_tsv))))
		ft_puterror(info, 0, "Malloc error");
	if (!(info->pal = (int *)malloc(sizeof(int) * 3)))
		ft_puterror(info, 0, "Malloc error");
	info->t_pts_h = 0;
	if (!(info->t_pts = (t_point **)malloc(sizeof(t_point *) * WIN_H)))
		ft_puterror(info, 0, "Malloc error");
	while (info->t_pts_h < WIN_H)
	{
		if (!(info->t_pts[info->t_pts_h] =
			(t_point *)malloc(sizeof(t_point) * WIN_H)))
			ft_puterror(info, 0, "Malloc error");
		info->t_pts_h++;
	}
	return (info);
}

void	*ft_init_ft_fract(char *fract)
{
	void *ft;

	ft = NULL;
	if (ft_strcmp(fract, "Mandelbrot") == 0)
		ft = ft_init_mandelbrot;
	else if (ft_strcmp(fract, "Julia") == 0)
		ft = ft_init_julia;
	else if (ft_strcmp(fract, "Burning_Ship") == 0)
		ft = ft_init_burning_ship;
	else if (ft_strcmp(fract, "Burning_Julia") == 0)
		ft = ft_init_burning_julia;
	else
		ft_available((void *)0);
	return (ft);
}

t_info	*ft_init_fract(t_info *ft(t_info *info), t_info *info)
{
	info = ft(info);
	return (info);
}

t_info	*ft_init_info_mlx(t_info *info)
{
	int *img;

	img = NULL;
	info->m_p = mlx_init();
	info->w_p = mlx_new_window(info->m_p, WIN_W, WIN_H,
			"Fract'ol project ; by Apons");
	info->i_p = mlx_new_image(info->m_p, WIN_W, WIN_H);
	img = ft_get_img(info);
	ft_bzero(img, WIN_W * WIN_H * sizeof(int));
	return (info);
}

t_info	*ft_init_info(char *fract)
{
	t_info	*info;
	void	*ft;

	ft = ft_init_ft_fract(fract);
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		ft_puterror(info, -1, "Malloc error");
	info = ft_init_info_mal(info);
	info->start_iter = 50;
	info->max_iter = 50;
	info->d_t = 0;
	info->d_i = 12;
	info->allow_help = 1;
	info->allow_julia = 1;
	info->tsv->s = 1.0;
	info->tsv->v = 1.0;
	info->pal[0] = 0xFF0000;
	info->pal[1] = 0x00FF00;
	info->pal[2] = 0x0000FF;
	info = ft_init_fract(ft, info);
	info = ft_init_info_mlx(info);
	return (info);
}
