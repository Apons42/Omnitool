/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:08:59 by apons             #+#    #+#             */
/*   Updated: 2019/05/27 14:41:43 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_ptfree(t_lstpt *point)
{
	if (point)
		free(point);
	point = NULL;
}

t_info	*ft_freeall(t_info *info, int free_var)
{
	if (info)
	{
		if (info->liner)
			free(info->liner);
		ft_tabfree(info->tab);
		ft_listfree(info->val_head);
		if (free_var == 2)
			ft_tabfree(info->line->tab);
		if (free_var >= 1)
			free(info->line);
		ft_lstptfree(info->points, info->height);
		ft_ptfree(info->start);
		ft_ptfree(info->finish);
		ft_ptfree(info->d);
		ft_ptfree(info->current);
		ft_ptfree(info->c_finish);
		if (info->mlx_ptr && info->img_ptr)
			mlx_destroy_image(info->mlx_ptr, info->img_ptr);
		if (info->mlx_ptr && info->win_ptr)
			mlx_destroy_window(info->mlx_ptr, info->win_ptr);
		if (info->mlx_ptr)
			mlx_del(info->mlx_ptr);
		free(info);
	}
	return (NULL);
}
