/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 10:08:15 by apons             #+#    #+#             */
/*   Updated: 2019/05/28 12:59:37 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_puterror(t_info *info, int free_var, char *str)
{
	info = ft_freeall(info, free_var);
	if (str)
		ft_putendl(str);
	exit(1);
}
