/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:27:53 by apons             #+#    #+#             */
/*   Updated: 2019/10/24 14:29:03 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		*ft_get_img(t_info *info)
{
	int	*img;
	int bpp;
	int sl;
	int endian;

	img = (int *)mlx_get_data_addr(info->i_p, &bpp, &sl, &endian);
	return (img);
}
