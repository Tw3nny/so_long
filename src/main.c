/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matisgutierreztw3nny <matisgutierreztw3    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 10:57:57 by matisgutier       #+#    #+#             */
/*   Updated: 2026/02/13 16:47:22 by matisgutier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	ft_printf("Map is valid");
}

int	main(int ac, char **av)
{
	t_map	map;
	
	if (!check_arg(ac, av))
		error("Invalid args", NULL);
	map.height = count_lines(av[1]);
	if (map.height<= 0)
		error("Empty or invalid file", NULL);
	map.grid = read_map(av[1], map.height);
	if (!map.grid)
		error("Malloc failed", NULL);
	valid_map(&map);
	return (0);
}