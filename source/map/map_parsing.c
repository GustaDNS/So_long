/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudaniel <gudaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:26:28 by gudaniel          #+#    #+#             */
/*   Updated: 2024/10/15 17:10:44 by gudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	parsing(t_game *game, char *file)
{
	validate_format(file, game);
	validate_elements(game, -1, -1, 0);
	validate_walls(game, 0);
	validate_chr(game, 0, 0);
	init_player(game);
	floodfill(&game, game->player.x, game->player.y);
	validate_floodfill(game, -1, -1);
}

int	set_height(int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	i++;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (i - 1);
}

void	floodfill(t_game **game, int x, int y)
{
	if ((*game)->map_dup[y][x] != '1')
		(*game)->map_dup[y][x] = 'f';
	if ((*game)->map_dup[y - 1][x] == 'E')
		(*game)->map_dup[y - 1][x] = 'f';
	if ((*game)->map_dup[y][x + 1] == 'E')
		(*game)->map_dup[y][x + 1] = 'f';
	if ((*game)->map_dup[y + 1][x] == 'E')
		(*game)->map_dup[y + 1][x] = 'f';
	if ((*game)->map_dup[y][x - 1] == 'E')
		(*game)->map_dup[y][x - 1] = 'f';
	if ((*game)->map_dup[y - 1][x] != '1' && (*game)->map_dup[y - 1][x] != 'f'
		&& (*game)->map_dup[y - 1][x] != 'E')
		floodfill(game, x, y - 1);
	if ((*game)->map_dup[y][x + 1] != '1' && (*game)->map_dup[y][x + 1] != 'f')
		floodfill(game, x + 1, y);
	if ((*game)->map_dup[y + 1][x] != '1' && (*game)->map_dup[y + 1][x] != 'f')
		floodfill(game, x, y + 1);
	if ((*game)->map_dup[y][x - 1] != '1' && (*game)->map_dup[y][x - 1] != 'f')
		floodfill(game, x - 1, y);
}

void	set_map(t_game *game, char *file)
{
	char	*row;
	int		i;
	int		fd;

	fd = open(file, O_RDONLY);
	i = -1;
	row = 0;
	game->map = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!game)
		killua(game, 1);
	while (++i < game->height)
		game->map[i] = get_next_line(fd);
	row = get_next_line(fd);
	free(row);
	game->map[i] = NULL;
}

void	set_width(t_game *game)
{
	int	j;
	int	temp;

	j = 0;
	if (game->height < 3)
	{
		ft_printf("Error! No map to read or to short\n");
		killua(game, 1);
	}
	game->width = ft_strclen(game->map[0], '\n');
	while (++j < game->height)
	{
		temp = ft_strclen(game->map[j], '\n');
		if (temp != game->width)
		{
			ft_printf("Error! not rectangular\n");
			killua(game, 1);
		}
	}
}
