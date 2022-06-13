# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 07:55:50 by ljohnson          #+#    #+#              #
#    Updated: 2022/06/13 09:26:09 by ljohnson         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


.PHONY: all clean fclean re makelibft makemlx
# .SILENT:

NAME	:=	miniRT
LIBFT	:=	libft/libft.a
MLX		:=	mlx/libmlx.a

#//////////////////////////////////////////////////////////////////////////////
#		ALL FILES
#//////////////////////////////////////////////////////////////////////////////

# Files
LST_INCS		:=	mini_rt.h					rt_keys.h				\
					rt_data.h					rt_structs.h			\
					rt_defines.h

LST_CHECKERS	:=	check_file_content.c		check_float_syntax.c	\
					check_value_format.c

LST_FREEZERS	:=	free_master.c				free_object_list.c

LST_GETTERS		:=	get_file_content.c			get_split_from_raw.c

LST_INIT_ITEM	:=	init_item_ambient.c			init_item_camera.c		\
					init_item_cylinder.c		init_item_light.c		\
					init_item_plane.c			init_item_sphere.c

LST_INIT_VALUE	:=	init_value_fov.c			init_value_o_xyz.c		\
					init_value_p_xyz.c			init_value_ratio.c		\
					init_value_rgb.c			init_value_size.c

LST_INITIERS	:=	init_master.c				init_object_ptr.c

LST_PARSE_ITEM	:=	parse_item_ambient.c		parse_item_camera.c		\
					parse_item_cylinder.c		parse_item_light.c		\
					parse_item_plane.c			parse_item_sphere.c

LST_PARSERS		:=	parse_file_content.c		parse_line.c			\
					parse_master.c				parse_object.c

LST_SETTERS		:=	

LST_WRITERS		:=	write_char_error.c			write_int_error.c		\
					write_split_error.c

LST_TESTERS		:=	test_ambient_values.c		test_camera_values.c	\
					test_cylinder_values.c		test_light_values.c		\
					test_object_list_values.c	test_plane_values.c		\
					test_sphere_values.c		test_split_values.c		\
					test_unit.c					test_fov.c				\
					test_ratio.c				test_rgb.c				\
					test_size.c					test_p_xyz.c

# Directories
P_MLX			:=	mlx/
P_LIBFT			:=	libft/
P_INCS_LIBFT	:=	libft/incs/

P_INCS			:=	incs/
P_SRCS			:=	srcs/
P_CHECKERS		:=	checkers/
P_FREEZERS		:=	freezers/
P_GETTERS		:=	getters/
P_INIT_ITEM		:=	init_item/
P_INIT_VALUE	:=	init_value/
P_INITIERS		:=	initiers/
P_PARSE_ITEM	:=	parse_item/
P_PARSERS		:=	parsers/
P_SETTERS		:=	setters/
P_WRITERS		:=	writers/

P_TESTERS		:=	testers/
P_OBJS			:=	.objs/

# Shortcuts
INCS			:=	$(addprefix $(P_INCS),$(LST_INCS))
SRCS			:=	$(addprefix $(P_SRCS),main.c)								\
					$(addprefix $(P_SRCS)$(P_CHECKERS),$(LST_CHECKERS))			\
					$(addprefix $(P_SRCS)$(P_FREEZERS),$(LST_FREEZERS))			\
					$(addprefix $(P_SRCS)$(P_GETTERS),$(LST_GETTERS))			\
					$(addprefix $(P_SRCS)$(P_INIT_ITEM),$(LST_INIT_ITEM))		\
					$(addprefix $(P_SRCS)$(P_INIT_VALUE),$(LST_INIT_VALUE))		\
					$(addprefix $(P_SRCS)$(P_INITIERS),$(LST_INITIERS))			\
					$(addprefix $(P_SRCS)$(P_PARSE_ITEM),$(LST_PARSE_ITEM))		\
					$(addprefix $(P_SRCS)$(P_PARSERS),$(LST_PARSERS))			\
					$(addprefix $(P_SRCS)$(P_SETTERS),$(LST_SETTERS))			\
					$(addprefix $(P_SRCS)$(P_WRITERS),$(LST_WRITERS))			\
					$(addprefix $(P_SRCS)$(P_TESTERS),$(LST_TESTERS))
OBJS			:=	$(subst $(P_SRCS),$(P_OBJS),$(SRCS:.c=.o))

#//////////////////////////////////////////////////////////////////////////////
#		COMMAND SHORTCUTS
#//////////////////////////////////////////////////////////////////////////////

# Commands
CC				:=	gcc
CF				:=	-Wall -Werror -Wextra
CI				:=	-I $(P_INCS_LIBFT) -I $(P_INCS) -I $(P_MLX)
CS				:=	-g3 -fsanitize=address
CG				:=	-g3
RM				:=	rm -rf
FW				:=	-Lmlx -lmlx -framework OpenGL -framework AppKit

# Colors
BLACK=\033[30m
RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m
PURPLE=\033[35m
CYAN=\033[36m
WHITE=\033[37m

# Text
ERASE=\033[2K\r
RESET=\033[0m
BOLD=\033[1m
FAINT=\033[2m
ITALIC=\033[3m
UNDERLINE=\033[4m

#//////////////////////////////////////////////////////////////////////////////
#		RULES
#//////////////////////////////////////////////////////////////////////////////

# all:	makemlx makelibft $(NAME)
all:	makelibft $(NAME)

# Binary creation
# $(NAME): $(OBJS) $(INCS) $(LIBFT) $(MLX) Makefile
# 	$(CC) $(CF) $(CI) $(FW) $(LIBFT) $(MLX) $(OBJS) -o $@
# 	printf "\n✅	$(GREEN)$(BOLD)Binary $(NAME) created$(RESET)\n"

# $(P_OBJS)%.o: $(P_SRCS)%.c $(INCS) $(LIBFT) $(MLX) Makefile | $(P_OBJS)
# 	$(CC) $(CF) $(CI) $(FW) -c $< -o $@
# 	printf "$(FAINT)$(CC) $(CF) $(CI) $(FW) -c -o $(RESET) $(CYAN)$(BOLD)$@$(RESET) $(FAINT)$(BLUE)$<$(RESET)\n"

$(NAME): $(OBJS) $(INCS) $(LIBFT) Makefile
	$(CC) $(CF) $(CI) $(LIBFT) $(OBJS) -o $@

$(P_OBJS)%.o: $(P_SRCS)%.c $(INCS) $(LIBFT) Makefile | $(P_OBJS)
	$(CC) $(CF) $(CI) -c $< -o $@

$(P_OBJS):
	mkdir -p $(P_OBJS)										\
	$(P_OBJS)$(P_CHECKERS)		$(P_OBJS)$(P_FREEZERS)		\
	$(P_OBJS)$(P_GETTERS)		$(P_OBJS)$(P_INITIERS)		\
	$(P_OBJS)$(P_INIT_ITEM)		$(P_OBJS)$(P_INIT_VALUE)	\
	$(P_OBJS)$(P_PARSERS)		$(P_OBJS)$(P_SETTERS)		\
	$(P_OBJS)$(P_PARSE_ITEM)	$(P_OBJS)$(P_WRITERS)		\
	$(P_OBJS)$(P_TESTERS)
#	printf "✅	$(GREEN)$(BOLD)$(NAME) obj directories created$(RESET)\n"

# Libs creation
$(MLX): makemlx

$(LIBFT): makelibft

makemlx:
	$(MAKE) -C mlx/

makelibft:
	$(MAKE) -j 3 -C libft/

# Mandatory rules
clean:
	$(RM) $(OBJS)
	$(RM) $(P_OBJS)
#	printf "$(YELLOW)$(BOLD)All $(NAME) object files removed$(RESET)\n"
#	printf "$(YELLOW)$(BOLD)All $(NAME) object folders removed$(RESET)\n"

fclean:
	$(MAKE) clean
	$(RM) $(NAME)
	$(MAKE) fclean -C libft/
	$(MAKE) clean -C mlx/
#	printf "$(RED)$(BOLD)Binary $(NAME) removed $(RESET)\n"

re:
	$(MAKE) fclean
	$(MAKE) all