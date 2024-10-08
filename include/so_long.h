/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudaniel <gudaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:42:47 by gudaniel          #+#    #+#             */
/*   Updated: 2024/10/08 12:24:25 by gudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/libft/libft.h"
# include "../libraries/minilibx-linux/mlx.h"
# include <stdbool.h>
# include <X11/keysym.h>
# include <X11/X.h>

//--------------------MAP----------------------//
typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
}	t_map;

void	validate_format(char *file);
void	validate_walls(t_map *map);
void	validate_elements(t_map *map, int i, int j);
void	parsing(t_map *map, char *file);
//-------------------GAME--------------------//
typedef struct s_game
{
	int		width;
	int		height;
	int		collectible;
	int		collected;
	int		count;
	t_coord	player;
	t_coord	exit;
	void	*mlx_ptr;
	void	*window_ptr;
	t_img	image;
	t_map	map;
	t_img	linker;
	t_coord	tile;

}	t_game;

typedef struct s_position
{
	int	x;
	int	y;

}	t_coord;

t_map	*init(void);
void	init_game(t_map *map);
void	floodfill(t_map *map, int x, int y);
int		set_height(int fd);
void	set_map(t_map *map, char *file);
void	make_struct(char *file, t_map *map);
void	set_width(t_map *map);
void	validate_chr(t_map *map, int i, int j);
void	killua(t_map *map);
void	ft_render(t_game *game);
void	move_to_right(t_game *game);
void	move_to_down(t_game *game);
void	move_to_left(t_game *game);
void	move_to_up(t_game *game);
int		key(int keycode, t_game *game);


//-------------------IMAGE--------------------//
typedef struct s_img
{
	int		*wall_outside;
	int		*wall_inside;
	int		*exit;
	int		*player;
	int		*collectible;
	char	*path
}	t_img;

#endif