/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mobility.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:21:35 by apons             #+#    #+#             */
/*   Updated: 2019/11/22 17:21:35 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "wolf3d.h"

/*
** These functions change the player's position
** and rotation values according to key events.
*/

static t_doublexy	get_projections(t_player player, t_keys key)
{
	double		judge_vert;
	double		judge_horiz;
	t_doublexy	proj;

	judge_vert = (key.up + key.down) * key.run;
	judge_horiz = (key.sleft + key.sright) * key.run;
	proj.x = player.pos.x + (player.dir.x / 9) * judge_vert;
	proj.x += player.plane.x / 9 * judge_horiz;
	proj.y = player.pos.y + (player.dir.y / 9) * judge_vert;
	proj.y += player.plane.y / 9 * judge_horiz;
	return (proj);
}

void				movement(t_enval *env)
{
	int			app_x;
	t_player	trim;
	t_doublexy	proj;

	app_x = 0;
	trim.pos.x = env->player.pos.x;
	trim.pos.y = env->player.pos.y;
	proj = get_projections(env->player, env->keyinf);
	if (env->map.walls[(int)(proj.x + OFF)][(int)(trim.pos.y - OFF)] == 0
		&& env->map.walls[(int)(proj.x - OFF)][(int)(trim.pos.y + OFF)] == 0
		&& env->map.walls[(int)(proj.x + OFF)][(int)(trim.pos.y + OFF)] == 0
		&& env->map.walls[(int)(proj.x - OFF)][(int)(trim.pos.y - OFF)] == 0)
		env->player.pos.x = proj.x;
	if (env->map.walls[(int)(trim.pos.x + OFF)][(int)(proj.y - OFF)] == 0
		&& env->map.walls[(int)(trim.pos.x - OFF)][(int)(proj.y + OFF)] == 0
		&& env->map.walls[(int)(trim.pos.x + OFF)][(int)(proj.y + OFF)] == 0
		&& env->map.walls[(int)(trim.pos.x - OFF)][(int)(proj.y - OFF)] == 0)
		env->player.pos.y = proj.y;
}

void				rotation(t_player *p, t_keys keyinf)
{
	int		judge;
	double	angle;
	double	dir_x_cpy;
	double	pla_x_cpy;

	judge = keyinf.left + keyinf.right;
	dir_x_cpy = p->dir.x;
	pla_x_cpy = p->plane.x;
	angle = 5 * M_PI / 180 * judge;
	p->dir.x = (p->dir.x * cos(angle) - p->dir.y * sin(angle));
	p->dir.y = (dir_x_cpy * sin(angle) + p->dir.y * cos(angle));
	p->plane.x = (p->plane.x * cos(angle) - p->plane.y * sin(angle));
	p->plane.y = (pla_x_cpy * sin(angle) + p->plane.y * cos(angle));
}
