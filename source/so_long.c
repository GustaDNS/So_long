/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudaniel <gudaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:21:35 by gudaniel          #+#    #+#             */
/*   Updated: 2024/11/05 14:30:39 by gudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	killua_dup(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->height)
		free(game->map_dup[i]);
	free(game->map_dup);
}

void	validate_image(void)
{
	int	fd;

	fd = open("./textures/kunai.xpm", O_RDONLY);
	if (fd < 0)
		exit(ft_printf("Error! Image doesn't exist\n"));
	fd = open("./textures/exit.xpm", O_RDONLY);
	if (fd < 0)
		exit(ft_printf("Error! Image doesn't exist\n"));
	fd = open("./textures/green.xpm", O_RDONLY);
	if (fd < 0)
		exit(ft_printf("Error! Image doesn't exist\n"));
	fd = open("./textures/minato.xpm", O_RDONLY);
	if (fd < 0)
		exit(ft_printf("Error! Image doesn't exist\n"));
	fd = open("./textures/tree_y_max.xpm", O_RDONLY);
	if (fd < 0)
		exit(ft_printf("Error! Can't read\n"));
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		validate_image();
		game = init();
		game->mlx_ptr = mlx_init();
		if (!game)
			killua(game, 1);
		make_struct(argv[1], game);
		parsing(game, argv[1]);
		ft_render(game);
		killua(game, 0);
	}
	return (0);
}
