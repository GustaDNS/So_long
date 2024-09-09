#include "../include/so_long.h"

void	validate_elements(t_map *map)
{
	int	i;
	int	j;
	int	player;
	int	exit;
	int	collectible;

	i = 0;
	player = 0;
	exit = 0;
	collectible = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'P')
				player++;
			if (map->map[i][j] == 'E')
				exit++;
			if (map->map[i][j] == 'C')
				collectible++;
			j++;
		}
		i++;
	}
	if (player != 1 || exit != 1 || collectible == 0)
		error("Invalid map");
}

void	validate_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (i == 0 || i == map->height - 1 || j == 0 || j == map->width - 1)
			{
				if (map->map[i][j] != '1')
					error("Invalid map");
			}
			j++;
		}
		i++;
	}
}

void	validate_format(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (file[0] == '/' || file[i - 4] != '.' || file[i - 3] != 'b' || file[i - 2] != 'e' || file[i - 1] != 'r')
		error("Invalid file format");
}

void	is_rectangular(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (ft_strlen(map->map[i]) != map->width)
			error("Invalid map");
		i++;
	}
}

void	read_map(t_map *map, char *file)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("Invalid file");
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (map->width == 0)
			map->width = ft_strlen(line);
		map->map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	map->map[i] = ft_strdup(line);
	free(line);
	map->height = i + 1;
	close(fd);
}
