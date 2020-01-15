/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fc_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 11:06:34 by apons             #+#    #+#             */
/*   Updated: 2019/05/27 14:37:44 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_listfree(t_line *alst)
{
	t_line	*first;
	t_line	*tonull;

	if (alst)
	{
		first = alst;
		while (1)
		{
			tonull = alst;
			if (tonull->tab)
				ft_tabfree(tonull->tab);
			alst = alst->next;
			if (tonull)
				free(tonull);
			tonull = NULL;
			if (alst == NULL)
				break ;
		}
	}
	first = NULL;
	alst = NULL;
}

void	ft_lstptfree(t_lstpt **points, int height)
{
	int y;

	y = 0;
	if (points)
	{
		while (y < height)
		{
			if (points[y])
				free(points[y]);
			y++;
		}
		free(points);
	}
	points = NULL;
}
