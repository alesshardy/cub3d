# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apintus <apintus@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 12:43:39 by apintus           #+#    #+#              #
#    Updated: 2024/10/14 12:32:19 by apintus          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #
#                                   NAME                                       #

NAME = cub3D

#----------------------------------------------------------------------------- #
#                                   COMPILATION                                #

CC = cc
CFLAGS = -Wall -Werror -Wextra
CFLAGS += -MMD -g3 -O3 -ffast-math -I./include

# ---------------------------------------------------------------------------- #
#                                   LIBRARIES                                  #


LIBFTDIR = ./libft
MLXDIR = ./mlx
MLXFLAG = -L$(MLXDIR) -lmlx -L/usr/lib -lXext -lX11 -lm

# ---------------------------------------------------------------------------- #
#                                   COLORS                                     #

GREEN   := \033[38;5;76m
RED     := \033[38;5;160m
YELLOW  := \033[38;5;226m
RESET   := \033[00m


# ---------------------------------------------------------------------------- #
#                                   SOURCES                                    #

SRC = main.c\
		key_handler.c\
		init.c\
		parsing/check_info.c\
		parsing/check_map_utils.c\
		parsing/check_map.c\
		parsing/check_map2.c\
		parsing/checker_file.c\
		parsing/get_color.c\
		parsing/get_file.c\
		parsing/get_info.c\
		parsing/get_texture.c\
		parsing/init_game.c\
		parsing/init_map.c\
		game/colors_utils.c\
		game/dda_utils.c\
		game/dda.c\
		game/movement_utils.c\
		game/movement.c\
		game/raycasting.c\
		game/raycasting2.c\
		game/texture.c\
		game/vector_utils.c\
		cleaning/exit_utils.c\
		cleaning/exit.c\

SRCS_DIR := ./srcs
OBJS_DIR := ./objs

SRCS := $(addprefix $(SRCS_DIR)/, $(SRC))
OBJS := $(addprefix $(OBJS_DIR)/, $(SRC:.c=.o))
DEPS := $(OBJS:.o=.d)

HEADERS := ./includes


O_SUBDIR := $(sort $(dir $(OBJS)))

# ---------------------------------------------------------------------------- #
#                                   RULES                                      #

all : $(NAME)

$(NAME): $(OBJS)
	@make --silent -C ${LIBFTDIR}
	@echo "$(YELLOW)[Compilation]$(RESET) Compilation de la bibliothèque MLX..."
	@make --silent -C ${MLXDIR}  > /dev/null 2>&1
	@$(CC) -I$(HEADERS) -I$(MLXDIR) -o $@ $(OBJS) -L$(LIBFTDIR) -lft $(MLXFLAG) $(LDFLAG) $(CFLAGS)
	@echo "$(GREEN)[Succes]$(RESET) Compilation de $@ terminée."
	@printf "$(RED)"
	@echo "   ___ _                                       _                     "
	@echo "  / __(_)_ __ ___ _   _ ___   /\\/\\   __ ___  _(_)_ __ ___  _   _ ___ "
	@echo " / /  | | '__/ __| | | / __| /    \\ / _\` \\ \\/ / | '_ \` _ \\| | | / __|"
	@echo "/ /___| | | | (__| |_| \\__ \\/ /\\/\\ \\ (_| |>  <| | | | | | | |_| \\__ \\"
	@echo "\\____/|_|_|  \\___|\\__,_|___/\\/    \\/\\__,_/_/\\_\\_|_| |_| |_|\\__,_|___/"
	@echo "                                                                    "
	@printf "$(RESET)"


$(OBJS_DIR) $(O_SUBDIR):
	@mkdir -p $@

-include $(DEPS)


$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(O_SUBDIR)
	@$(eval TOTAL := $(words $(OBJS)))
	@$(eval COUNT := $(shell expr $(COUNT) + 1))
	@echo -n "$(YELLOW)[Compilation]$(RESET) Compilation de $<" $(COUNT)"/"$(TOTAL)"\r"
	@$(CC) $(CFLAGS) -I$(HEADERS) -I$MLXDIR -c $< -o $@ >> /dev/null 2>&1
	@echo -n "$(YELLOW)[Compilation]$(RESET) Compilation de $<" $(COUNT)"/"$(TOTAL)"\r"


clean:
	@echo -n "$(RED)Cleaning object files... 🧹$(RESET)"
	@make --silent clean -C ${LIBFTDIR} /dev/null 2>&1
	@make --silent clean -C ${MLXDIR} /dev/null 2>&1
	@rm -rf $(OBJS_DIR)
	@for i in {1..10}; do echo -n "."; sleep 0.1; done; echo ""

fclean: clean
	@echo -n "$(RED)Cleaning all files... 🗑️$(RESET)"
	@make --silent fclean -C ${LIBFTDIR} /dev/null 2>&1
	@make --silent clean -C ${MLXDIR} /dev/null 2>&1
	@rm -f $(NAME)
	@for i in {1..10}; do echo -n "."; sleep 0.1; done; echo ""

re: fclean all

.PHONY: all clean fclean re
