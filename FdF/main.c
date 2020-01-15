/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 10:31:52 by apons             #+#    #+#             */
/*   Updated: 2019/05/31 10:35:25 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_info	*info;

	if (argc != 2 && argc != 3)
	{
		ft_putendl("Usage : ./fdf [map] [default color]");
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("File does not exist");
		exit(1);
	}
	info = ft_init_info(-1, 0);
	info->color_default = (argc == 3 ? argv[2] : ",0xFFFFFF");
	info = ft_get_values(fd, info);
	info = ft_init_mlx(info);
	ft_drawgrid(info);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_ptr, 0, 0);
	ft_showhelp(info);
	mlx_hook(info->win_ptr, 2, 1L << 0, &ft_showtime, info);
	mlx_loop(info->mlx_ptr);
	return (0);
}
