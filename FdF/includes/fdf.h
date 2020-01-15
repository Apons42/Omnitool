/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:30:27 by apons             #+#    #+#             */
/*   Updated: 2019/05/29 11:29:01 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <math.h>
# include "libft.h"
# include "../minilibx_macos/mlx.h"

/*
** Window management
*/

# define WIN_WIDTH 2100
# define WIN_HEIGHT 1300

typedef struct	s_info
{
	int					width;
	int					height;
	float				scale;
	int					x_off;
	int					y_off;
	int					allow_help;
	float				angle_x;
	float				angle_y;
	float				angle_z;
	float				magnitude;
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	char				*color_default;
	char				*liner;
	struct s_line		*line;
	struct s_line		*val_head;
	char				**tab;
	struct s_lstpt		**points;
	struct s_lstpt		*start;
	struct s_lstpt		*finish;
	struct s_lstpt		*d;
	struct s_lstpt		*current;
	struct s_lstpt		*c_finish;
}				t_info;

typedef struct	s_lstpt
{
	float	x;
	float	y;
	float	z;
	int		color;

}				t_lstpt;

typedef struct	s_line
{
	char			**tab;
	struct s_line	*next;
}				t_line;

/*
**Parsing (src/info)
*/

void			ft_appendline(t_line *head, t_line *newlink);
int				ft_get_colors(char *str, t_info *info);
int				ft_get_gradient(t_lstpt *current, t_lstpt *start,
								t_lstpt *end, t_lstpt *delta);
int				ft_get_light(int start, int end, double percentage);
double			ft_get_percent(float start, float end, float current);
t_info			*ft_get_values(int fd, t_info *info);
t_info			*ft_init_info(int width, int height);
t_info			*ft_init_malloc(t_info *info);
t_info			*ft_init_mlx(t_info *info);
t_info			*ft_init_non_malloc(int width, int height, t_info *info);
t_line			*ft_newline(t_info *info);
t_lstpt			**ft_tabatoi(t_info *info, int width, int height);
char			**ft_tabcpy(char **dst, char **tab);
int				ft_tablen(char **tab);

/*
**Graphical part (src/lput)
*/

void			ft_fill_pix(int *img, t_lstpt *pt, t_info *info);
int				*ft_get_img(t_info *info);
t_lstpt			*ft_getpoint(int x, int y, t_info *info);
void			ft_drawgrid(t_info *info);
void			ft_drawcoln(const int x, t_info *info);
void			ft_drawline(const int y, t_info *info);
int				*ft_img_set_color(int *img, t_lstpt *pt);
int				ft_isinside(t_lstpt *point);
void			ft_line_put(t_info *info);
void			ft_oct_horizontal(int *img, t_lstpt *s,
								t_lstpt *f, t_info *info);
void			ft_oct_sideleft(int *img, t_info *info);
void			ft_oct_sideright(int *img, t_info *info);
void			ft_oct_vertical(int *img, t_lstpt *s, t_lstpt *f, t_info *info);
void			ft_oct1(int *img, t_info *info);
void			ft_oct2(int *img, t_info *info);
void			ft_oct3(int *img, t_info *info);
void			ft_oct4(int *img, t_info *info);
void			ft_oct5(int *img, t_info *info);
void			ft_oct6(int *img, t_info *info);
void			ft_oct7(int *img, t_info *info);
void			ft_oct8(int *img, t_info *info);
void			ft_redo_delta(t_info *info, int neg);
t_lstpt			*ft_rot_x(t_lstpt *point, float theta);
t_lstpt			*ft_rot_y(t_lstpt *point, float theta);
t_lstpt			*ft_rot_z(t_lstpt *point, float theta, float mag);
t_lstpt			*ft_valuemanip(t_lstpt *point, t_info *info);
t_lstpt			*ft_scale(t_lstpt *point, t_info *info);

/*
**Commands
*/

void			ft_misc(int key, t_info *info);
void			ft_moveframe(int key, t_info *info);
void			ft_preset(int key, t_info *info);
void			ft_rotframe(int key, t_info *info);
void			ft_reset(t_info *info);
void			ft_showhelp(t_info *info);
int				ft_showtime(int key, t_info *info);

/*
**Other
*/

t_info			*ft_freeall(t_info *info, int free_var);
void			ft_listfree(t_line *alst);
void			ft_lstptfree(t_lstpt **points, int height);
void			ft_puterror(t_info *info, int free_var, char *str);
void			ft_ptfree(t_lstpt *point);

#endif
