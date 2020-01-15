/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:32:58 by apons             #+#    #+#             */
/*   Updated: 2019/06/24 09:21:53 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_put_conv(t_tsv *rgb, double r, double g, double b)
{
	rgb->t = r;
	rgb->s = g;
	rgb->v = b;
}

t_tsv		*ft_get_rgb(t_tsv *rgb, t_tsv *tsv, t_conv *conv)
{
	if (conv->ti == 0)
		ft_put_conv(rgb, tsv->v, conv->n, conv->l);
	else if (conv->ti == 1)
		ft_put_conv(rgb, conv->m, tsv->v, conv->l);
	else if (conv->ti == 2)
		ft_put_conv(rgb, conv->l, tsv->v, conv->n);
	else if (conv->ti == 3)
		ft_put_conv(rgb, conv->l, conv->m, tsv->v);
	else if (conv->ti == 4)
		ft_put_conv(rgb, conv->n, conv->l, tsv->v);
	else
		ft_put_conv(rgb, tsv->v, conv->l, conv->m);
	return (rgb);
}

t_tsv		*ft_tsv_to_rgb(t_info *info)
{
	info->conv->ti = (int)(info->tsv->t / 60);
	info->conv->f = (info->tsv->t / 60) - info->conv->ti;
	info->conv->l = info->tsv->v * (1 - info->tsv->s);
	info->conv->m = info->tsv->v * (1 - info->conv->f * info->tsv->s);
	info->conv->n = info->tsv->v * (1 - (1 - info->conv->f) * info->tsv->s);
	info->rgb = ft_get_rgb(info->rgb, info->tsv, info->conv);
	return (info->rgb);
}

int			ft_get_color(t_info *info, int x, int y)
{
	info->tsv->t = info->d_t + info->d_i * info->t_pts[y][x].iter;
	while (info->tsv->t < 0)
		info->tsv->t += 360;
	while (info->tsv->t > 359)
		info->tsv->t -= 360;
	info->rgb = ft_tsv_to_rgb(info);
	return (info->pal[0] * info->rgb->t + info->pal[1] * info->rgb->s
			+ info->pal[2] * info->rgb->v);
}
