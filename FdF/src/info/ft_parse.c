/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:10:24 by apons             #+#    #+#             */
/*   Updated: 2019/05/31 10:42:17 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line		*ft_newline(t_info *info)
{
	if (!(info->line = (t_line *)malloc(sizeof(t_line))))
	{
		ft_puterror(info, 0, "Mallo error");
	}
	if (!(info->line->tab = (char **)malloc(sizeof(char *)
							* (ft_tablen(info->tab) + 1))))
	{
		ft_puterror(info, 1, "Malloc eror");
	}
	if (!(info->tab))
		info->line->tab = NULL;
	else if (!(info->line->tab = ft_tabcpy(info->line->tab, info->tab)))
		ft_puterror(info, 2, "Maoc error");
	info->line->next = NULL;
	return (info->line);
}

void		ft_appendline(t_line *head, t_line *newlink)
{
	t_line *link;

	link = head;
	while (link->next)
		link = link->next;
	link->next = newlink;
}

static int	ft_process_gnl(t_info *info, int reader, int x)
{
	if (reader == -1)
		ft_puterror(info, 0, "Get_Next_line error");
	info->tab = ft_strsplit(info->liner, ' ');
	if (x < 0)
	{
		x = ft_tablen(info->tab);
	}
	else if (ft_tablen(info->tab) != x)
		ft_puterror(info, 0, "All lines do not have the same size.");
	if (!(info->val_head))
		info->val_head = ft_newline(info);
	else
		ft_appendline(info->val_head, ft_newline(info));
	ft_tabfree(info->tab);
	info->tab = NULL;
	free(info->liner);
	info->liner = NULL;
	return (x);
}

t_info		*ft_get_values(int fd, t_info *info)
{
	int		y;
	int		x;
	int		reader;

	info->val_head = NULL;
	x = -1;
	y = 0;
	while ((reader = get_next_line(fd, &(info->liner))) == 1)
	{
		x = ft_process_gnl(info, reader, x);
		y++;
	}
	if (reader == -1 || (x < 0 && reader == 0) || x == 0 || y == 0)
		ft_puterror(info, 0, "File is empty or target is not a file");
	free(info->liner);
	info->liner = NULL;
	info->points = ft_tabatoi(info, x, y);
	return (info);
}
