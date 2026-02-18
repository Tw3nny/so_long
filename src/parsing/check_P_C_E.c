/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_P_C_E.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matiguti <matiguti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:31:30 by matisgutier       #+#    #+#             */
/*   Updated: 2026/02/17 11:10:28 by matiguti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	check_content(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->grid[++i])
	{
		j = -1;
		while (map->grid[i][++j])
		{
			if (map->grid[i][j] == PLAYER)
				set_player_pos(map, i, j);
			else if (map->grid[i][j] == EXIT)
				map->exit_count++;
			else if (map->grid[i][j] == COIN)
				map->coins++;
			else if (map->grid[i][j] != WALL && map->grid[i][j] != FLOOR)
				return (0);
		}
	}
	if (map->player_count != 1 || map->exit_count != 1 || map->coins < 1)
		return (0);
	return (1);
}

void	set_player_pos(t_map *map, int i, int j)
{
	map->player_count++;
	map->player.y = i;
	map->player.x = j;
}
