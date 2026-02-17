/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matisgutierreztw3nny <matisgutierreztw3    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:40:39 by matisgutier       #+#    #+#             */
/*   Updated: 2026/02/16 15:00:52 by matisgutier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	move_player(t_games *game, int dx, int dy)
{
	int	new_x;
	int	new_y;
	
	new_x = game->map.player.x + dx;
	new_y = game->map.player.y + dy;
	if (game->map.grid[new_y][new_x] == WALL)
		return ;
	if (game->map.grid[new_y][new_x] == COIN)
	{
		game->map.collected++;
		game->map.grid[new_y][new_x] = FLOOR;
	}
	if (game->map.grid[new_y][new_x] == EXIT
	&& game->map.collected == game->map.coins)
	{
		ft_printf("You win in %d moves!\n", game->moves + 1);
		close_game(game);
	}
	game->map.player.x = new_x;
	game->map.player.y = new_y;
	game->moves++;
	ft_printf("Moves : %d\n", game->moves);
	render_map(game);
}