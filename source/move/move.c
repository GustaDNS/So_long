/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudaniel <gudaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:34:09 by gudaniel          #+#    #+#             */
/*   Updated: 2024/10/15 14:14:19 by gudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	move_to_up(t_game *game)
{
	if (game->map[game->player.y - 1][game->player.x] == '1')
		return ;
	if (game->map[game->player.y - 1][game->player.x] == 'E'
		&& game->collected != game->collectible)
		return ;
	if (game->map[game->player.y - 1][game->player.x] == 'E'
		&& game->collected == game->collectible)
	{
		ft_printf("%d\n", ++game->count);
		killua(game, 0);
	}
	if (game->map[game->player.y - 1][game->player.x] == 'C')
	{
		game->map[game->player.y - 1][game->player.x] = '0';
		game->collected++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->floor.img,
		(game->player.x * 64), (game->player.y * 64));
	mlx_put_image_to_window(game->mlx_ptr,
		game->window_ptr, game->player_img.img,
		((game->player.x) * 64), ((game->player.y - 1) * 64));
	game->player.y = game->player.y - 1;
	ft_printf("%d\n", ++game->count);
}

void	move_to_left(t_game *game)
{
	if (game->map[game->player.y][game->player.x - 1] == '1')
		return ;
	if (game->map[game->player.y][game->player.x - 1] == 'E'
		&& game->collected != game->collectible)
		return ;
	if (game->map[game->player.y][game->player.x - 1] == 'E'
		&& game->collected == game->collectible)
	{
		ft_printf("%d\n", ++game->count);
		killua(game, 0);
	}
	if (game->map[game->player.y][game->player.x - 1] == 'C')
	{
		game->map[game->player.y][game->player.x - 1] = '0';
		game->collected++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->floor.img,
		(game->player.x * 64), (game->player.y * 64));
	mlx_put_image_to_window(game->mlx_ptr,
		game->window_ptr, game->player_img.img,
		((game->player.x - 1) * 64), ((game->player.y) * 64));
	game->player.x = game->player.x - 1;
	ft_printf("%d\n", ++game->count);
}

void	move_to_down(t_game *game)
{
	if (game->map[game->player.y + 1][game->player.x] == '1')
		return ;
	if (game->map[game->player.y + 1][game->player.x] == 'E'
		&& game->collected != game->collectible)
		return ;
	if (game->map[game->player.y + 1][game->player.x] == 'E'
		&& game->collected == game->collectible)
	{
		ft_printf("%d\n", ++game->count);
		killua(game, 0);
	}
	if (game->map[game->player.y + 1][game->player.x] == 'C')
	{
		game->map[game->player.y + 1][game->player.x] = '0';
		game->collected++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->floor.img,
		(game->player.x * 64), (game->player.y * 64));
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
		game->player_img.img,
		((game->player.x) * 64), ((game->player.y + 1) * 64));
	game->player.y = game->player.y + 1;
	ft_printf("%d\n", ++game->count);
}

void	move_to_right(t_game *game)
{
	if (game->map[game->player.y][game->player.x + 1] == '1')
		return ;
	if (game->map[game->player.y][game->player.x + 1] == 'E'
		&& game->collected != game->collectible)
		return ;
	if (game->map[game->player.y][game->player.x + 1] == 'E'
		&& game->collected == game->collectible)
	{
		ft_printf("%d\n", ++game->count);
		killua(game, 0);
	}
	if (game->map[game->player.y][game->player.x + 1] == 'C')
	{
		game->map[game->player.y][game->player.x + 1] = '0';
		game->collected++;
	}
	mlx_put_image_to_window(game->mlx_ptr,
		game->window_ptr, game->floor.img,
		(game->player.x * 64), (game->player.y * 64));
	mlx_put_image_to_window(game->mlx_ptr,
		game->window_ptr, game->player_img.img,
		((game->player.x + 1) * 64), ((game->player.y) * 64));
	game->player.x = game->player.x + 1;
	ft_printf("%d\n", ++game->count);
}

int	key(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		killua(game, 0);
	if (keycode == XK_w)
		move_to_up(game);
	if (keycode == XK_s)
		move_to_down(game);
	if (keycode == XK_d)
		move_to_right(game);
	if (keycode == XK_a)
		move_to_left(game);
	return (0);
}
