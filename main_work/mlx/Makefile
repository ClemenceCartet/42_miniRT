# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/19 10:10:21 by ljohnson          #+#    #+#              #
#    Updated: 2022/08/19 10:17:10 by ljohnson         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re
.SILENT:

NAME		:=	libmlx.a

#//////////////////////////////////////////////////////////////////////////////
#		ALL FILES
#//////////////////////////////////////////////////////////////////////////////

# Files
INCS	:=	mlx_int.h	mlx_new_window.h	mlx_opengl.h	mlx_png.h	mlx.h

SRCS	:=	mlx_shaders.c				mlx_xpm.c		\
			mlx_int_str_to_wordtab.c	mlx_png.c		\
			mlx_new_window.m			mlx_init_loop.m	\
			mlx_new_image.m				mlx_mouse.m

OBJS	:=	$(SRCS:.c=.o)
OBJ		=	$(OBJS:.m=.o)

#//////////////////////////////////////////////////////////////////////////////
#		FLAGS & TEXT MODIFIERS
#//////////////////////////////////////////////////////////////////////////////

# Flags
CC			:=	cc
CFLAGS		+=	-O2 -DSTRINGPUTX11 -Wno-deprecated-declarations -DGL_SILENCE_DEPRECATION
CS			:=	-g -fsanitize=address
CI			:=	-I .
CG			:=	-g3
AR			:=	ar -rcs
RM			:=	rm -rf

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

all: $(NAME)

# Binary creation
$(NAME): $(OBJ) Makefile
	$(AR) $(NAME) $(OBJ)
	printf "✅	$(GREEN)$(BOLD)Library $(NAME) created$(RESET)\n"

# Mandatory rules

clean:
	$(RM) $(OBJ)
	printf "$(YELLOW)$(BOLD)All MLX object files removed$(RESET)\n"

fclean: clean
	$(RM) $(NAME)
	$(RM) mlx_app
	printf "$(RED)$(BOLD)Library $(NAME) removed $(RESET)\n"

re:
	$(MAKE) fclean
	$(MAKE) all

# Old Makefile

#
#

# NOM=libmlx.a
# SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
# SRC+= mlx_png.c mlx_mouse.m
# OBJ1=$(SRC:.c=.o)
# OBJ=$(OBJ1:.m=.o)
# CFLAGS+=-O2

# # add to match string put with X11 in size and position
# CFLAGS+= -DSTRINGPUTX11

# all: $(NOM)

# $(NOM):	$(OBJ)
# 	ar -r $(NOM) $(OBJ)
# 	ranlib $(NOM)

# clean:
# 	rm -f $(NOM) $(OBJ) *~
# 	rm -f mlx_app

# re: clean all