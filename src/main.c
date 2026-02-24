/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matiguti <matiguti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 10:57:57 by matisgutier       #+#    #+#             */
/*   Updated: 2026/02/17 11:13:35 by matiguti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static int	check_arg(int ac, char **av)
{
	int	len;

	if (ac != 2)
		return (0);
	len = ft_strlen(av[1]);
	if (len < 4)
		return (0);
	if (ft_strncmp(av[1] + len - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}

static void	valid_map(t_map *map)
{
	map->player_count = 0;
	map->exit_count = 0;
	map->coins = 0;
	map->collected = 0;
	if (!is_rectangular(map->grid))
		error("Map is not rectangular", map);
	if (!check_wall(map->grid))
		error("Map is not surrounded by walls", map);
	if (!check_content(map))
		error("Invalid map content", map);
	if (!check_path(map))
		error("No valid path", map);
	map->width = ft_strlen(map->grid[0]);
}

int	main(int ac, char **av)
{
	t_games	game;

	if (!check_arg(ac, av))
		error("Invalid args", NULL);
	game.map.height = count_lines(av[1]);
	if (game.map.height <= 0)
		error("Empty or invalid file", NULL);
	game.map.grid = read_map(av[1], game.map.height);
	if (!game.map.grid)
		error("Malloc failed", NULL);
	valid_map(&game.map);
	game.moves = 0;
	game.wall.ptr = NULL;
	game.floor.ptr = NULL;
	game.player.ptr = NULL;
	game.collect.ptr = NULL;
	game.exit.ptr = NULL;
	game.map.grid[game.map.player.y][game.map.player.x] = FLOOR;
	init_game(&game);
	load_sprites(&game);
	render_map(&game);
	mlx_hook(game.window, 2, 1L << 0, key_handler, &game);
	mlx_hook(game.window, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
