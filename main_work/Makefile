# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 07:55:50 by ljohnson          #+#    #+#              #
#    Updated: 2022/08/06 16:44:39 by ljohnson         ###   ########lyon.fr    #
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
LST_INCS		:=	mini_rt.h		rt_keys.h			\
					rt_data.h		rt_defines.h		\
					rt_objects.h
LST_SRCS		:=	rt_free_data.c		rt_free_objects.c	\
					rt_init_master.c	rt_write_errors.c	\
					rt_struct_utils.c	rt_init_objects.c	\
					rt_init_data.c		rt_check_utils.c	\
					rt_init_coords.c	rt_init_rgb.c		\
					test_battery.c

# Directories
P_MLX			:=	mlx/
P_LIBFT			:=	libft/
P_INCS_LIBFT	:=	libft/incs/

P_INCS			:=	incs/
P_SRCS			:=	srcs/

P_OBJS			:=	.objs/

# Shortcuts
INCS			:=	$(addprefix $(P_INCS),$(LST_INCS))
SRCS			:=	$(addprefix $(P_SRCS),$(LST_SRCS))	\
					$(addprefix $(P_SRCS),main.c)
OBJS			:=	$(subst $(P_SRCS),$(P_OBJS),$(SRCS:.c=.o))

#//////////////////////////////////////////////////////////////////////////////
#		COMMAND SHORTCUTS
#//////////////////////////////////////////////////////////////////////////////

# Commands
CC				:=	gcc
CF				:=	-Wall -Werror -Wextra
CI				:=	-I $(P_INCS_LIBFT) -I $(P_INCS) -I $(P_MLX)
CS				:=	-g -fsanitize=address
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

all: makelibft $(NAME)

# Binary creation
# $(NAME): $(OBJS) $(INCS) $(LIBFT) $(MLX) Makefile
# 	$(CC) $(CF) $(CI) $(FW) $(LIBFT) $(MLX) $(OBJS) -o $@
# 	printf "\n✅	$(GREEN)$(BOLD)Binary $(NAME) created$(RESET)\n"

# $(P_OBJS)%.o: $(P_SRCS)%.c $(INCS) $(LIBFT) $(MLX) Makefile | $(P_OBJS)
# 	$(CC) $(CF) $(CI) $(FW) -c $< -o $@
# 	printf "$(FAINT)$(CC) $(CF) $(CI) $(FW) -c -o $(RESET) $(CYAN)$(BOLD)$@$(RESET) $(FAINT)$(BLUE)$<$(RESET)\n"

$(NAME): $(OBJS) $(INCS) $(LIBFT) Makefile
	$(CC) $(CF) $(CI) $(OBJS) -o $@ $(LIBFT)

$(P_OBJS)%.o: $(P_SRCS)%.c $(INCS) $(LIBFT) Makefile | $(P_OBJS)
	$(CC) $(CF) $(CI) -c $< -o $@
	
$(P_OBJS):
	mkdir -p $(P_OBJS)
	printf "✅	$(GREEN)$(BOLD)$(NAME) obj directories created$(RESET)\n"

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
	printf "$(YELLOW)$(BOLD)All $(NAME) object files removed$(RESET)\n"
	printf "$(YELLOW)$(BOLD)All $(NAME) object folders removed$(RESET)\n"

fclean:
	$(MAKE) clean
	$(RM) $(NAME)
	$(MAKE) fclean -C libft/
	printf "$(RED)$(BOLD)Binary $(NAME) removed $(RESET)\n"
#	$(MAKE) clean -C mlx/

re:
	$(MAKE) fclean
	$(MAKE) all