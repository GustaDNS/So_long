/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudaniel <gudaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:42:47 by gudaniel          #+#    #+#             */
/*   Updated: 2024/10/15 15:53:40 by gudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/libft/libft.h"
# include "../libraries/minilibx-linux/mlx.h"
# include <stdbool.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdbool.h>

//-------------------GAME--------------------//
typedef struct s_img
{
	void	*img;
	char	*add;
	int		bpp;
	int		lm;
	int		endian;
}	t_img;

typedef struct s_position
{
	int	x;
	int	y;

}	t_coord;

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
	t_coord	tile;
	char	**map;
	char	**map_dup;
	t_img	wall_outside;
	t_img	exit_img;
	t_img	player_img;
	t_img	collectible_img;
	t_img	floor;

}	t_game;

t_game	*init(void);
void	init_game(t_game *game);
int		set_height(int fd);
void	set_map(t_game *game, char *file);
void	make_struct(char *file, t_game *map);
void	set_width(t_game *game);
void	validate_chr(t_game *game, int i, int j);
void	killua(t_game *game, int i);
void	ft_render(t_game *game);
void	move_to_right(t_game *game);
void	move_to_down(t_game *game);
void	move_to_left(t_game *game);
void	move_to_up(t_game *game);
int		key(int keycode, t_game *game);

void	validate_format(char *file, t_game *game);
void	validate_walls(t_game *game, int i);
void	validate_elements(t_game *game, int i, int j, int player);
void	parsing(t_game *game, char *file);
void	ft_render(t_game *game);
void	render_grid(t_game *game);
void	init_player(t_game *game);
int		close_window(t_game *game);
void	dup_map(t_game *game, char *file);
void	floodfill(t_game **game, int x, int y);
void	validate_floodfill(t_game *game, int i, int j);
void	destroy_image(t_game *game);
void	killua_dup(t_game *game);
void	validate_image(void);

//-------------------IMAGE--------------------//

#endif