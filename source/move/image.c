/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudaniel <gudaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:03:22 by gudaniel          #+#    #+#             */
/*   Updated: 2024/10/08 12:35:41 by gudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	image(t_game *game)
{
	int	width;
	int	height;

	game->image.wall_inside = mlx_xpm_to_image(game->mlx_ptr, "textures/bush.xpm", &width, &height);
	game->image.wall_outside = mlx_xpm_to_image(game->mlx_ptr, "textures/tree_y_max.xpm", &width, &height);
	game->image.player = mlx_xpm_to_image(game->mlx_ptr, "textures/minato.xpm", &width, &height);
	game->image.collectible = mlx_xpm_to_image(game->mlx_ptr, "textures/kunai.xpm", &width, &height);
	game->image.exit = mlx_xpm_to_image(game->mlx_ptr, "textures/exit.xpm", &width, &height);
	game->linker.path = mlx_xpm_file_to_image(game->mlx_ptr,"textures/path.xpm", &width, &height);
}

void	tile(t_game *game, int x, int y)
{
	void	*img;

	if (game->map.map[y][x] == '1')
		img = game->image.wall_outside;
	else if(game->map.map[y][x + 1] || game->map.map[y][x - 1])
		img = game->image.wall_inside;
	else if (game->map.map[y][x] == 'P')
		img = game->image.player;
	else if (game->map.map[y][x] == 'C')
		img = game->image.collectible;
	else if (game->map.map[y][x] == 'E')
		img = game->image.exit;
	if (img)
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, img, (x * 64), (y * 64));
}
void	ft_render(t_game *game)
{
	game->window_ptr = mlx_new_window(game->mlx_ptr, (game->width * game->tile.x),
			(game->height * game->tile.y), "so_long");
	render_grid(game);
	mlx_hook(game->window_ptr, KeyPress, KeyPressMask, key, game);
	mlx_hook(game->window_ptr, DestroyNotify, NoEventMask, key, game);
	mlx_loop(game->mlx_ptr);
}
void	render_grid(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	load_images(game);
	while (game->map.map[++y])
	{
		while (game->map.map[y][++x])
			draw_tile(game, x, y);
		x = -1;
	}
}