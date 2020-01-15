/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 11:44:49 by apons             #+#    #+#             */
/*   Updated: 2019/07/01 13:01:47 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <complex.h>
# include "libft.h"
# include "mlx.h"

# define WIN_W 750
# define WIN_H 750
# define LIM_ITER 120

/*
**Structures
*/

typedef struct	s_info
{
	int				start_iter;
	int				max_iter;
	int				d_t;
	int				d_i;
	int				allow_help;
	int				allow_julia;
	double			zoom;
	double			d_x;
	double			d_y;
	double			mouse_x;
	double			mouse_y;
	void			*ft_fract;
	void			*m_p;
	void			*w_p;
	void			*i_p;
	int				t_pts_h;
	struct s_point	**t_pts;
	struct s_conv	*conv;
	struct s_tsv	*tsv;
	struct s_tsv	*rgb;
	int				*pal;
}				t_info;

typedef struct	s_point
{
	double	r;
	double	i;
	int		iter;
}				t_point;

typedef struct	s_conv
{
	int		ti;
	double	f;
	double	l;
	double	m;
	double	n;
}				t_conv;

typedef struct	s_tsv
{
	double t;
	double s;
	double v;
}				t_tsv;

/*
**Fract - Fractal functions and points calculations
*/

t_point			ft_burning_julia(t_point c, t_info *info);
t_point			ft_burning_ship(t_point c, t_info *info);
t_point			ft_julia(t_point z0, t_info *info);
t_point			ft_mandelbrot(t_point c, t_info *info);
t_info			*ft_get_points(t_info *info,
					t_point f(t_point z, t_info *info));

/*
**Graph - Anything attuning to drawing fractals or showing help
*/

int				*ft_get_img(t_info *info);
int				ft_get_color(t_info *info, int x, int y);
t_tsv			*ft_get_rgb(t_tsv *rgb, t_tsv *tsv, t_conv *conv);
t_tsv			*ft_tsv_to_rgb(t_info *info);
void			ft_draw_fract(t_info *info, int x, int y);
void			ft_showhelp(t_info *info);
void			ft_update_fract(t_info *info);
void			ft_update_graph(t_info *info);

/*
**Keycom - Anything related to commands, be it with keyboard or mouse
*/

int				ft_keyboard_handle(int key, t_info *info);
int				ft_mouseclick_handle(int button, int x, int y, t_info *info);
int				ft_mousemove_handle(int x, int y, t_info *info);
void			ft_move_fract(int key, t_info *info);
void			ft_set_diff(int key, t_info *info);
void			ft_set_fract(int key, t_info *info);
void			ft_set_iter(int key, t_info *info);
void			ft_set_palette(int key, t_info *info);
void			ft_set_zoom(int key, t_info *info);
void			ft_toggle_allows(int key, t_info *info);
void			ft_exit(t_info *info);

/*
**Init - This is where Fract'ol begins
*/

t_info			*ft_init_info_mal(t_info *info);
t_info			*ft_init_info(char *fract);
t_info			*ft_init_fract(t_info *ft(t_info *info), t_info *info);
void			*ft_init_ft_fract(char *fract);
t_info			*ft_init_burning_ship(t_info *info);
t_info			*ft_init_burning_julia(t_info *info);
t_info			*ft_init_julia(t_info *info);
t_info			*ft_init_mandelbrot(t_info *info);
t_info			*ft_init_palette(t_info *info);
t_info			*ft_init_info_mlx(t_info *info);
t_info			*ft_one_fract(char *fract);

/*
**Free - This is where Fract'ol ends
*/

void			ft_available(t_info *info);
void			ft_puterror(t_info *info, int nb, char *error);
void			ft_free_info(t_info *info, int nb);
void			ft_free_tpts(t_point **t_pts, int height);

#endif
