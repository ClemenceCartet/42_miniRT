# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 07:55:50 by ljohnson          #+#    #+#              #
#    Updated: 2022/06/07 13:06:29 by ljohnson         ###   ########lyon.fr    #
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

LST_CHECKERS	:=	

LST_FREEZERS	:=	

LST_GETTERS		:=	

LST_INITIERS	:=	

LST_PARSERS		:=	

LST_SETTERS		:=	

LST_WRITERS		:=	

LST_TESTERS		:=	

# Directories
P_MLX			:=	mlx/
P_LIBFT			:=	libft/
P_INCS_LIBFT	:=	libft/incs/

P_INCS			:=	incs/
P_SRCS			:=	srcs/
P_CHECKERS		:=	checkers/
P_FREEZERS		:=	freezers/
P_GETTERS		:=	getters/
P_INITIERS		:=	initiers/
P_PARSERS		:=	parsers/
P_SETTERS		:=	setters/
P_WRITERS		:=	writers/

P_TESTERS		:=	testers/
P_OBJS			:=	.objs/

# Shortcuts
INCS			:=	$(addprefix $(P_INCS),$(LST_INCS))
SRCS			:=	$(addprefix $(P_SRCS),main.c)						\
					$(addprefix $(P_SRCS)$(P_CHECKERS),$(LST_CHECKERS))	\
					$(addprefix $(P_SRCS)$(P_FREEZERS),$(LST_FREEZERS))	\
					$(addprefix $(P_SRCS)$(P_GETTERS),$(LST_GETTERS))	\
					$(addprefix $(P_SRCS)$(P_INITIERS),$(LST_INITIERS))	\
					$(addprefix $(P_SRCS)$(P_PARSERS),$(LST_PARSERS))	\
					$(addprefix $(P_SRCS)$(P_SETTERS),$(LST_SETTERS))	\
					$(addprefix $(P_SRCS)$(P_WRITERS),$(LST_WRITERS))	\
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
	mkdir -p $(P_OBJS)								\
	$(P_OBJS)$(P_CHECKERS)	$(P_OBJS)$(P_FREEZERS)	\
	$(P_OBJS)$(P_GETTERS)	$(P_OBJS)$(P_INITIERS)	\
	$(P_OBJS)$(P_PARSERS)	$(P_OBJS)$(P_SETTERS)	\
	$(P_OBJS)$(P_WRITERS)	$(P_OBJS)$(P_TESTERS)
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