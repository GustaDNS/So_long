/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudaniel <gudaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:30:24 by gudaniel          #+#    #+#             */
/*   Updated: 2024/10/15 16:58:29 by gudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	killua(t_game *game, int a)
{
	int	i;

	i = -1;
	while (++i < game->height)
		free(game->map[i]);
	killua_dup(game);
	if (a == 1)
	{
		free(game->map);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		free(game);
		exit(1);
	}
	free(game->map);
	if (a == 0)
		destroy_image(game);
	free(game);
	exit(1);
}

int	close_window(t_game *game)
{
	killua(game, 0);
	exit(0);
}

void	dup_map(t_game *game, char *file)
{
	char	*row;
	int		i;
	int		fd;

	fd = open(file, O_RDONLY);
	i = -1;
	row = 0;
	game->map_dup = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!game)
		killua(game, 1);
	while (++i < game->height)
		game->map_dup[i] = get_next_line(fd);
	row = get_next_line(fd);
	free(row);
	game->map_dup[i] = NULL;
}

void	validate_floodfill(t_game *game, int i, int j)
{
	int	count;
	int	x;

	x = 0;
	count = 0;
	while (++i < game->height)
	{
		while (++j < game->width)
		{
			if (game->map_dup[i][j] == 'P')
				count++;
			if (game->map_dup[i][j] == 'C')
				count++;
			if (game->map_dup[i][j] == 'E')
				count++;
		}
		j = -1;
		if (count != 0)
		{
			ft_printf("Error! Invalid floodfill\n");
			killua(game, 1);
		}
	}
}

void	destroy_image(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->collectible_img.img);
	mlx_destroy_image(game->mlx_ptr, game->exit_img.img);
	mlx_destroy_image(game->mlx_ptr, game->player_img.img);
	mlx_destroy_image(game->mlx_ptr, game->wall_outside.img);
	mlx_destroy_image(game->mlx_ptr, game->floor.img);
	mlx_destroy_window(game->mlx_ptr, game->window_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
}
