/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 10:03:10 by apons             #+#    #+#             */
/*   Updated: 2019/05/14 11:39:23 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**ft_valmap(int **val, int width, int height, int (*f)(int))
{
	int **dst;
	int x;
	int y;

	if (!val || !(dst = ft_valcpy(dst, val, width, height)))
		return (0);
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			val[y][x] = f(val[y][x]);
			x++;
		}
		y++;
	}
	return (dst);
}
