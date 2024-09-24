/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudaniel <gudaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:26:28 by gudaniel          #+#    #+#             */
/*   Updated: 2024/09/24 12:11:28 by gudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	parsing(t_map *map, char *file)
{
	validate_format(file);
	validate_elements(map, -1, -1);
	validate_walls(map);
	validate_chr(map, 0, 0);
}

void	floodfill(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return ;
	if (map->map[y][x] == '1' || map->map[y][x] == 'C')
		return ;
	if (map->map[y][x] == 'E')
	{
		map->map[y][x] = 'C';
		return ;
	}
	map->map[y][x] = 'C';
	floodfill(map, x + 1, y);
	floodfill(map, x - 1, y);
	floodfill(map, x, y + 1);
	floodfill(map, x, y - 1);
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

void	set_map(t_map *map, char *file)
{
	char	*row;
	int		i;
	int		fd;

	fd = open(file, O_RDONLY);
	i = -1;
	row = 0;
	map->map = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map)
		killua(map);
	while (++i < map->height)
		map->map[i] = get_next_line(fd);
	row = get_next_line(fd);
	free(row);
	map->map[i] = NULL;
}

void	set_width(t_map *map)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	map->width = ft_strclen(map->map[j], '\n');
	j++;
	while (j < map->height)
	{
		temp = ft_strclen(map->map[j], '\n');
		if (temp != map->width)
		{
			ft_printf("Error\n");
			killua(map);
		}
		j++;
	}
}
