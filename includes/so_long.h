/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matisgutierreztw3nny <matisgutierreztw3    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 23:10:59 by matisgutier       #+#    #+#             */
/*   Updated: 2026/02/13 15:36:44 by matisgutier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ============================== */
/*             DEFINES            */
/* ============================== */

// LIBRARY

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"

// KEYS

#ifdef __APPLE__

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123

#else

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_LEFT 65361
#endif

// MAP 

# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define COIN 'C'
# define EXIT 'E'

# define WALL_F	"assets/.xpm"
# define FLOOR_F "assets/.xpm"
# define PLAYER_F "assets/.xpm"
# define COIN_F "assets/.xpm"
# define EXIT_F "assets/.xpm"

# define IMG_SIZE // 32/64

/* ============================== */
/*           STRUCTURES           */
/* ============================== */

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_img
{
	void	*ptr;
	int		width;
	int		height;
}	t_img;

typedef struct s_map
{
	char 	**grid;
	int		width;
	int		height;
	int		coins;
	int		collected;
	int		exit_count;
	int		player_count;
	t_pos	player;
	t_pos	exit;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	int		moves;
	t_map	map;
	t_img	wall;
	t_img	floor;
	t_img	player;
	t_img	collect;
	t_img	exit;	
}	t_games;

/* ============================== */
/*           FONCTIONS            */
/* ============================== */

// MAP PARSING

int		count_lines(char *file);
char	**read_map(char *file, int height);
int		is_rectangular(char **grid);
int		check_wall(char **grid);
int		check_content(t_map *map);
void	set_player_pos(t_map *map, int i, int j);
void	free_grid(char **grid, int height);
char	**copy_grid(char **grid, int height);
void	floodfill(char **grid, int y, int x);
int		check_path(t_map *map);
void	error(char *msg, t_map *map);


#endif