/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 12:38:32 by apons             #+#    #+#             */
/*   Updated: 2019/10/24 11:30:43 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			main(int argc, char **argv)
{
	t_info *info;

	info = NULL;
	if (argc != 2)
		ft_available((void *)0);
	info = ft_one_fract(argv[1]);
	mlx_loop(info->m_p);
	return (0);
}
