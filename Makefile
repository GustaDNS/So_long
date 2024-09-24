# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gudaniel <gudaniel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/01 10:23:59 by gudaniel          #+#    #+#              #
#    Updated: 2024/09/24 12:08:28 by gudaniel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                     NAMES                                    #
#==============================================================================#

CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror -g
NAME		= so_long

INC			= -I./includes -I./libraries/libft
RM			= rm -rf

GENERAL		= so_long init util
MAP			= map_parsing map_validation

#==============================================================================#
#                                    PATHS                                     #
#==============================================================================#
VPATH 		= ./source \
			  ./source/map \
			  
MAPS_PATH	= ./source/map			
LIBS_PATH	= ./libraries
LIBFT_PATH	= $(LIBS_PATH)/libft
LIBFT 		= $(LIBFT_PATH)/libft.a

SRC			= $(addsuffix .c, $(GENERAL))\
			  $(addsuffix .c, $(MAP))\

OBJ_DIR		= obj
OBJS		= $(SRC:%.c=$(OBJ_DIR)/%.o)

DEPS		= $(addsuffix .h, $(GENERAL)) $(addsuffix .h, $(MAP))

#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

all: deps $(NAME)

deps: 
	@$(MAKE) -C $(LIBFT_PATH)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@$(MAKE) clean -C $(LIBFT_PATH)
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_PATH) 
	@$(RM) $(NAME) $(OBJ_DIR)

re: fclean all