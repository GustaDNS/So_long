/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudaniel <gudaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:03:22 by gudaniel          #+#    #+#             */
/*   Updated: 2024/10/15 15:21:04 by gudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	image(t_game *game)
{
	int	width;
	int	height;

	game->wall_outside.img = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/tree_y_max.xpm", &width, &height);
	game->player_img.img = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/minato.xpm", &width, &height);
	game->collectible_img.img = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/kunai.xpm", &width, &height);
	game->exit_img.img = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/exit.xpm", &width, &height);
	game->floor.img = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/green.xpm", &width, &height);
}

void	tile(t_game *game, int x, int y)
{
	t_img	img;

	if (game->map[y][x] == '1')
		img.img = game->wall_outside.img;
	else if (game->map[y][x] == '0')
		img.img = game->floor.img;
	else if (game->map[y][x] == 'P')
		img.img = game->player_img.img;
	else if (game->map[y][x] == 'C')
		img.img = game->collectible_img.img;
	else if (game->map[y][x] == 'E')
		img.img = game->exit_img.img;
	else
		img.img = game->floor.img;
	if (img.img)
		mlx_put_image_to_window(game->mlx_ptr,
			game->window_ptr, img.img, (x * 64), (y * 64));
}

void	ft_render(t_game *game)
{
	game->window_ptr = mlx_new_window(game->mlx_ptr, (game->width * 64),
			(game->height * 64), "so_long");
	render_grid(game);
	mlx_hook(game->window_ptr, KeyPress, KeyPressMask, key, game);
	mlx_hook(game->window_ptr, DestroyNotify, NoEventMask, key, game);
	mlx_hook(game->window_ptr, 17, 0, close_window, game);
	mlx_loop(game->mlx_ptr);
}

void	render_grid(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	image(game);
	while (game->map[++y])
	{
		while (game->map[y][++x])
			tile(game, x, y);
		x = -1;
	}
}

void	init_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] && game->map[i][j] != 'P')
			j++;
		if (game->map[i][j] == 'P')
			break ;
		i++;
	}
	game->player.y = i;
	game->player.x = j;
}
