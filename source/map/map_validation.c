/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudaniel <gudaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:27:24 by gudaniel          #+#    #+#             */
/*   Updated: 2024/10/15 16:26:27 by gudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	validate_elements(t_game *game, int i, int j, int player)
{
	int	exit;
	int	collectible;

	player = 0;
	exit = 0;
	collectible = 0;
	while (++i < game->height)
	{
		while (++j < game->width)
		{
			if (game->map[i][j] == 'P')
				player++;
			if (game->map[i][j] == 'E')
				exit++;
			if (game->map[i][j] == 'C')
				collectible++;
		}
		j = -1;
	}
	if (player != 1 || exit != 1 || collectible == 0)
	{
		killua(game, 1);
		ft_printf("Error! Invalid elements\n");
	}
	game->collectible = collectible;
}

void	validate_walls(t_game *game, int i)
{
	int	j;
	int	bi;

	i = 0;
	j = -1;
	bi = 0;
	while (game->map[0][++j] != '\n')
		if (game->map[0][j] != '1')
			bi = 1;
	j = -1;
	while (game->map[++i])
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
			bi = 1;
	}
	while (game->map[i - 1][++j])
	{
		if (game->map[game->height - 1][j] != '1')
			bi = 1;
	}
	if (bi == 1)
	{
		ft_printf("Error! Invalid walls\n");
		killua(game, 1);
	}
}

void	validate_format(char*file, t_game *game)
{
	if (strcmp(file + ft_strlen(file) - 4, ".ber") != 0)
	{
		ft_printf("Error! Invalid format!\n");
		killua(game, 1);
	}
}

void	make_struct(char *file, t_game *game)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error! Can't read\n");
		killua(game, 1);
	}
	game->height = set_height(fd);
	set_map(game, file);
	dup_map(game, file);
	set_width(game);
}

void	validate_chr(t_game *game, int i, int j)
{
	while (i < game->height)
	{
		while (j < game->width)
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0'
				&& game->map[i][j] != 'P' && game->map[i][j]
				!= 'E' && game->map[i][j] != 'C')
			{
				ft_printf("Error! Invalid elements on map\n");
				killua(game, 1);
			}
			j++;
		}
		j = 0;
		i++;
	}
}
