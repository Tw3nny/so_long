/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matiguti <matiguti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:13:15 by matisgutier       #+#    #+#             */
/*   Updated: 2026/02/17 11:09:32 by matiguti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	render_sprite(t_games *game, int y, int x)
{
	int		px;
	int		py;
	void	*img;

	px = x * IMG_SIZE;
	py = y * IMG_SIZE;
	if (game->map.grid[y][x] == WALL)
		img = game ->wall.ptr;
	else if (game->map.grid[y][x] == COIN)
		img = game->collect.ptr;
	else if (game->map.grid[y][x] == EXIT)
		img = game->exit.ptr;
	else
		img = game->floor.ptr;
	mlx_put_image_to_window(game->mlx, game->window, img, px, py);
}

void	render_map(t_games *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.grid[y])
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			render_sprite(game, y, x);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->player.ptr,
		game->map.player.x * IMG_SIZE, game->map.player.y * IMG_SIZE);
}

void	load_sprites(t_games *game)
{
	int	s;

	s = IMG_SIZE;
	game->wall.ptr = mlx_xpm_file_to_image(game->mlx, WALL_F, &s, &s);
	game->floor.ptr = mlx_xpm_file_to_image(game->mlx, FLOOR_F, &s, &s);
	game->player.ptr = mlx_xpm_file_to_image(game->mlx, PLAYER_F, &s, &s);
	game->collect.ptr = mlx_xpm_file_to_image(game->mlx, COIN_F, &s, &s);
	game->exit.ptr = mlx_xpm_file_to_image(game->mlx, EXIT_F, &s, &s);
	if (!game->wall.ptr || !game->floor.ptr || !game->player.ptr
		|| !game->collect.ptr || !game->exit.ptr)
		error("Failed to load sprites", &game->map);
}
