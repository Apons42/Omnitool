# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apons <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/14 10:44:54 by apons             #+#    #+#              #
#    Updated: 2019/05/29 11:33:07 by apons            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -Iincludes
MFLAGS = -lmlx -framework OpenGL -framework AppKit

NAME = fdf

LIBF = libft
LIB = libft.a

MINI = minilibx_macos
MLX = libmlx.a

_C = main.c\
	 src/free/ft_fc_free.c\
	 src/free/ft_freeall.c\
	 src/free/ft_puterror.c\
	 src/lput/ft_circle_cross.c\
	 src/lput/ft_circle_east.c\
	 src/lput/ft_circle_west.c\
	 src/lput/ft_drawgrid.c\
	 src/lput/ft_line_put.c\
	 src/lput/ft_img_set_colors.c\
	 src/lput/ft_rot.c\
	 src/info/ft_colors_gradient.c\
	 src/info/ft_init_info.c\
	 src/info/ft_parse.c\
	 src/info/ft_tabatoi.c\
	 src/info/ft_tabmanip.c\
	 src/keycom/ft_command_functions.c\
	 src/keycom/ft_keycom.c\
	 src/keycom/ft_showtime.c

_O = ${_C:%.c=%.o}


all : $(NAME)

$(NAME): $(_O)
	make -C $(MINI) &&\
	make -C $(LIBF) &&\
	gcc $(CFLAGS) $(MFLAGS) -o $(NAME) $(_O) $(LIBF)/$(LIB) \
	$(MINI)/$(MLX)

clean:
	make -C $(MINI) clean &&\
	make -C $(LIBF) clean &&\
	/bin/rm -f $(_O)

fclean: clean
	/bin/rm -f $(MINI)/$(MLX) &&\
	make -C $(LIBF) fclean &&\
	/bin/rm -f $(NAME)

re : fclean all

.PHONY: clean fclean
