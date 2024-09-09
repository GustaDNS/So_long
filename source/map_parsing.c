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