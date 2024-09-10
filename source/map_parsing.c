#include "../include/so_long.h"

void	parsing(t_map *map, char *file)
{
	map->width = 0;
	map->height = 0;
	validate_format(file);
	read_map(map, file);
	validate_elements(map);
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
	flodfill(map, x + 1, y);
	flodfill(map, x - 1, y);
	flodfill(map, x, y + 1);
	flodfill(map, x, y - 1);
}