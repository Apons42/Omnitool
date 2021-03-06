/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 10:33:44 by apons             #+#    #+#             */
/*   Updated: 2019/10/31 16:04:39 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "wolf3d.h"

/*
** First part of raycasting functions. Calculations for walls are done here.
*/

static t_ray	side_step(t_ray ray, t_player p)
{
	if (ray.dir.x < 0)
	{
		ray.sidedist.x = (p.pos.x - ray.mapos.x) * ray.deltadist.x;
		ray.step.x = -1;
	}
	else
	{
		ray.sidedist.x = (ray.mapos.x + 1.0 - p.pos.x) * ray.deltadist.x;
		ray.step.x = 1;
	}
	if (ray.dir.y < 0)
	{
		ray.sidedist.y = (p.pos.y - ray.mapos.y) * ray.deltadist.y;
		ray.step.y = -1;
	}
	else
	{
		ray.sidedist.y = (ray.mapos.y + 1.0 - p.pos.y) * ray.deltadist.y;
		ray.step.y = 1;
	}
	return (ray);
}

void			ray_calc(t_enval *env, int i)
{
	env->ray.camera = 2 * i / (double)WIN_W - 1;
	env->ray.dir.x = env->player.dir.x + env->player.plane.x * env->ray.camera;
	env->ray.dir.y = env->player.dir.y + env->player.plane.y * env->ray.camera;
	env->ray.deltadist.x = sqrt(1 + (env->ray.dir.y * env->ray.dir.y)
		/ (env->ray.dir.x * env->ray.dir.x));
	env->ray.deltadist.y = sqrt(1 + (env->ray.dir.x * env->ray.dir.x)
		/ (env->ray.dir.y * env->ray.dir.y));
	env->ray.mapos.x = (int)env->player.pos.x;
	env->ray.mapos.y = (int)env->player.pos.y;
	env->ray = side_step(env->ray, env->player);
}

static void		perp_height(t_enval *env)
{
	if (env->ray.wallside == 0)
		env->ray.perpwalldist = ft_abs((env->ray.mapos.x - env->player.pos.x +
			(1 - env->ray.step.x) / 2) / env->ray.dir.x);
	else
		env->ray.perpwalldist = ft_abs((env->ray.mapos.y - env->player.pos.y +
			(1 - env->ray.step.y) / 2) / env->ray.dir.y);
	env->ray.height = (int)(WIN_H / env->ray.perpwalldist);
	env->ray.wallbot = (int)env->ray.height / 2 + WIN_H / 2;
	if (env->ray.wallbot > WIN_H)
		env->ray.wallbot = WIN_H;
	env->ray.walltop = (int)-env->ray.height / 2 + WIN_H / 2;
	if (env->ray.walltop < 0)
		env->ray.walltop = 0;
}

void			ray_hit(t_enval *env)
{
	env->ray.wallhit = 0;
	while (env->ray.wallhit == 0)
	{
		if (env->ray.sidedist.x < env->ray.sidedist.y)
		{
			env->ray.sidedist.x += env->ray.deltadist.x;
			env->ray.mapos.x += env->ray.step.x;
			env->ray.wallside = 0;
		}
		else
		{
			env->ray.sidedist.y += env->ray.deltadist.y;
			env->ray.mapos.y += env->ray.step.y;
			env->ray.wallside = 1;
		}
		if (env->map.walls[env->ray.mapos.x][env->ray.mapos.y] != 0)
			env->ray.wallhit = 1;
	}
	perp_height(env);
}

void			ray_draw(t_enval *env)
{
	int i;
	int texnum;

	env->mlx.pxl = (int *)mlx_get_data_addr(env->mlx.i_p, &env->mlx.bpp,
			&env->mlx.s_line, &env->mlx.endian);
	i = 0;
	while (i < WIN_W)
	{
		ray_calc(env, i);
		ray_hit(env);
		if (!(env->ray.wallside) && env->ray.dir.x < 0)
			texnum = 1;
		else if (!(env->ray.wallside) && env->ray.dir.x >= 0)
			texnum = 0;
		else if (env->ray.wallside && env->ray.dir.y < 0)
			texnum = 2;
		else if (env->ray.wallside && env->ray.dir.y >= 0)
			texnum = 3;
		wall_draw(env, i, texnum);
		fc_draw(env, i);
		i++;
	}
	mlx_put_image_to_window(env->mlx.m_p, env->mlx.w_p, env->mlx.i_p, 0, 0);
}
