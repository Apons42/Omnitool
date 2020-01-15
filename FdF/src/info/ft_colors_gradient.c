/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors_gradient.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:34:47 by apons             #+#    #+#             */
/*   Updated: 2019/05/29 11:45:27 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*ft_is_color(char *str, t_info *info)
{
	char	*hex_colors;
	int		i;

	i = 0;
	if (str && ft_strlen(str) == 9 && str[1] == '0'
			&& (str[2] == 'x' || str[2] == 'X'))
	{
		if (!(hex_colors = ft_strsub(str, 3, 6)))
		{
			ft_puterror(info, 0, "Malloc error");
		}
		while (ft_strchr("0123456789ABCDEFabcdef", hex_colors[i]))
		{
			if (hex_colors[i] >= 97 && hex_colors[i] <= 102)
				hex_colors[i] -= 32;
			i++;
			if (!(hex_colors[i]))
				return (hex_colors);
		}
		free(hex_colors);
	}
	return (NULL);
}

int			ft_get_colors(char *str, t_info *info)
{
	char	*str_color;
	char	*raw_color;
	int		int_color;

	str_color = ft_strchr(str, ',');
	if (str_color && (raw_color = ft_is_color(str_color, info)))
	{
		int_color = ft_atoi_base(raw_color, 16);
		free(raw_color);
		return (int_color);
	}
	if (!(raw_color = ft_is_color(info->color_default, info)))
		return (0xFFFFFF);
	int_color = ft_atoi_base(raw_color, 16);
	free(raw_color);
	return (int_color);
}

double		ft_get_percent(float start, float end, float current)
{
	double position;
	double distance;

	position = current - start;
	distance = end - start;
	if (distance == 0)
		return (0);
	return (position / distance);
}

int			ft_get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int			ft_get_gradient(t_lstpt *current, t_lstpt *start,
							t_lstpt *end, t_lstpt *delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (start->color == end->color)
		return (start->color);
	if (delta->x > delta->y)
		percentage = ft_get_percent(start->x, end->x, current->x);
	else
		percentage = ft_get_percent(start->y, end->y, current->y);
	red = ft_get_light((start->color >> 16) & 0xFF, (end->color >> 16) & 0xFF,
						percentage);
	green = ft_get_light((start->color >> 8) & 0xFF, (end->color >> 8) & 0xFF,
						percentage);
	blue = ft_get_light(start->color & 0xFF, end->color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
