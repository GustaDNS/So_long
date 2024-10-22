# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gudaniel <gudaniel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/01 10:23:59 by gudaniel          #+#    #+#              #
#    Updated: 2024/10/22 13:49:29 by gudaniel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SOURCE = ./source/map/map_parsing.c ./source/map/map_validation.c ./source/move/image.c ./source/move/move.c \
		 ./source/init.c	./source/so_long.c	./source/util.c\

LPATH = ./libraries/libft

MPATH = ./libraries/minilibx-linux

API = -L $(MPATH) -lmlx -L~/../../usr/local/lib -lXext -lX11 -lm -lbsd

LIBS = $(LPATH)/libft.a

all: $(NAME)

$(NAME): $(SOURCE) $(LIBS)
		cc -g -Wall -Werror -Wextra $(SOURCE) $(LIBS) $(API) -o so_long

$(LIBS): $(LPATH) $(MPATH)
	$(MAKE) -C $(LPATH)
	$(MAKE) -C $(MPATH)

clean:
	$(MAKE) clean -C $(LPATH)

fclean: clean
	$(MAKE) fclean -C $(LPATH)
	rm -Rf so_long

re: fclean all

download:
	@wget https://cdn.intra.42.fr/document/document/27195/minilibx-linux.tgz
	@tar -xzf minilibx-linux.tgz
	@rm minilibx-linux.tgz