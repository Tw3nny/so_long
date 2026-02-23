/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matiguti <matiguti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:49:10 by matisgutier       #+#    #+#             */
/*   Updated: 2026/02/17 11:12:21 by matiguti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	init_game(t_games *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error("MLX init failed", &game->map);
	game->window = mlx_new_window(game->mlx,
			game->map.width * IMG_SIZE, game->map.height * IMG_SIZE, "so_long");
	if (!game->window)
		error("Window creation failed", &game->map);
}

int	close_game(t_games *game)
{
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->map.grid)
		free_grid(game->map.grid, game->map.height);
	exit(0);
	return (0);
}
