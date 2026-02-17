/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matisgutierreztw3nny <matisgutierreztw3    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:40:43 by matisgutier       #+#    #+#             */
/*   Updated: 2026/02/16 10:59:38 by matisgutier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/so_long.h"

void	free_grid(char **grid, int height)
{
	int	i;
	
	i = 0;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

char	**copy_grid(char **grid, int height)
{
	int		i;
	char	**copy;
	
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(grid[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	floodfill(char **grid, int y, int x)
{
	if (grid[y][x] == WALL || grid[y][x] == 'F')
		return ;
	grid[y][x] = 'F';
	floodfill(grid, y - 1, x);
	floodfill(grid, y + 1, x);
	floodfill(grid, y, x - 1);
	floodfill(grid, y, x + 1);
}

int	check_path(t_map *map)
{
	char	**copy;
	int		i;
	int		j;
	
	copy = copy_grid(map->grid, map->height);
	if (!copy)
		return (0);
	floodfill(copy, map->player.y, map->player.x);
	i = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (copy[i][j] == COIN || copy[i][j] == EXIT)
			{
				free_grid(copy, map->height);
				return (0);
			}
			j++;
		}
		i++;
	}
	free_grid(copy, map->height);
	return (1);
}
