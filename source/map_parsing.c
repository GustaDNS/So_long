/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudaniel <gudaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:46:04 by gudaniel          #+#    #+#             */
/*   Updated: 2024/09/12 16:06:46 by gudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	parsing(t_map *map, char *file)
{
	validate_format(file);
	read_map(map, file);
	validate_elements(map, 0, 0);
	validate_walls(map);
	is_rectangular(map);
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

int	set_height(char *file, int fd)
{
	char	*line;
	int		i;
	
	line = NULL;
	if (!line)
		perror("Nothing to read");
	line = get_next_line(fd);
	i++;
	while (line)
	{
		line = get_next_line(fd);
		i++;
	}
	free(line);
	return (i - 1);
}

int set_map(const char *file, t_map *map)
{
    int fd;
    int row;
	int height;
	int i; 
	
	i = 0;
	row = 0;
	height = set_height();
    map->map = (char **)malloc(sizeof(char *) * (map->height + 1));
    if (!map->map)
        return (-1);
    fd = open(file, O_RDONLY);
    if (fd < 0)
        perror("Error opening map file");
    while (++i < map->height)
    {
		
    }
    close(fd);
    return (0);
}

