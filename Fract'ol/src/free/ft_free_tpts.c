/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tpts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:05:44 by apons             #+#    #+#             */
/*   Updated: 2019/06/24 09:11:53 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_free_tpts(t_point **t_pts, int height)
{
	int y;

	if (t_pts)
	{
		y = 0;
		while (y < height)
		{
			if (t_pts[y])
				free(t_pts[y]);
			t_pts[y] = NULL;
			y++;
		}
		free(t_pts);
	}
	t_pts = NULL;
}
