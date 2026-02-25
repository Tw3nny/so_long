/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matisgutierreztw3nny <matisgutierreztw3    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:49:10 by matisgutier       #+#    #+#             */
/*   Updated: 2026/02/25 13:03:54 by matisgutier      ###   ########.fr       */
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
	{
		mlx_destroy_display(game->mlx);
		error("Window creation failed", &game->map);
	}
}

int	close_game(t_games *game)
{
	if (game->wall.ptr)
		mlx_destroy_image(game->mlx, game->wall.ptr);
	if (game->floor.ptr)
		mlx_destroy_image(game->mlx, game->floor.ptr);
	if (game->player.ptr)
		mlx_destroy_image(game->mlx, game->player.ptr);
	if (game->collect.ptr)
		mlx_destroy_image(game->mlx, game->collect.ptr);
	if (game->exit.ptr)
		mlx_destroy_image(game->mlx, game->exit.ptr);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);	
	}
	if (game->map.grid)
		free_grid(game->map.grid, game->map.height);
	exit(0);
	return (0);
}
