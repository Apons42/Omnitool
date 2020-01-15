# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apons <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/14 10:44:54 by apons             #+#    #+#              #
#    Updated: 2019/10/18 11:06:42 by apons            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -Iincludes
MFLAGS = -lmlx -framework OpenGL -framework AppKit

NAME = fractol

LIBF = libft
LIB = libft.a

MINI = minilibx_macos
MLX = libmlx.a

_C = main.c\
	 src/fract/ft_get_points.c\
	 src/fract/ft_burning_julia.c\
	 src/fract/ft_burning_ship.c\
	 src/fract/ft_julia.c\
	 src/fract/ft_mandelbrot.c\
	 src/free/ft_available.c\
	 src/free/ft_free_info.c\
	 src/free/ft_free_tpts.c\
	 src/free/ft_puterror.c\
	 src/graph/ft_draw_fract.c\
	 src/graph/ft_get_color.c\
	 src/graph/ft_get_img.c\
	 src/graph/ft_showhelp.c\
	 src/graph/ft_update.c\
	 src/init/ft_init_info.c\
	 src/init/ft_init_info_fractals.c\
	 src/init/ft_one_fract.c\
	 src/keycom/commands_handle.c\
	 src/keycom/ft_exit.c\
	 src/keycom/ft_move_fract.c\
	 src/keycom/ft_set_diff.c\
	 src/keycom/ft_set_fract.c\
	 src/keycom/ft_set_iter.c\
	 src/keycom/ft_set_palette.c\
	 src/keycom/ft_set_zoom.c\
	 src/keycom/ft_toggle_allows.c

_O = ${_C:%.c=%.o}


all : $(NAME)

$(NAME): $(_O)
	make -j4 -C  $(MINI)
	make -j4 -C $(LIBF)
	@gcc $(CFLAGS) $(MFLAGS) -o $(NAME) $(_O) $(LIBF)/$(LIB) \
	$(MINI)/$(MLX)

clean:
	@make -C $(MINI) clean
	@make -s -C $(LIBF) clean
	@/bin/rm -f $(_O)

fclean: clean
	@/bin/rm -f $(MINI)/$(MLX)
	@make -s -C $(LIBF) fclean
	@/bin/rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
