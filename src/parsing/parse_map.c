/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matisgutierreztw3nny <matisgutierreztw3    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:14:00 by matisgutier       #+#    #+#             */
/*   Updated: 2026/02/13 10:57:51 by matisgutier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *file)
{
	int		fd;
	int		count;
	char	*line;
	
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

char	**read_map(char *file, int height)
{
	int		fd;
	int		i;
	char	**grid;
	
	grid = malloc(sizeof(char *) * (height + 1));
	if (!grid)
		return (NULL);
	fd = open(file, O_RDONLY);
	i = 0;
	while (i < height)
	{
		grid[i] = get_next_line(fd);
		if (grid[i] && grid[i][ft_strlen(grid[i]) - 1] == '\n')
			grid[i][ft_strlen(grid[i]) - 1] = '\0';
		i++;
	}
	grid[i] = NULL;
	close(fd);
	return (grid);
}

int	is_rectangular(char **grid)
{
	int	i;
	size_t	length;
	
	length = ft_strlen(grid[0]);
	i = 1;
	while (grid[i] != NULL)
	{
		if (ft_strlen(grid[i]) != length)
			return (0);
		i++;
	}
	return (1);
}

int	check_wall(char **grid)
{
	int i;
	int	i_max;
	
	i = -1;
	i_max = ft_strlen(grid[0]) - 1;
	while (grid[0][++i])
		if (grid[0][i] != WALL)
			return (0);
	i = -1;
	while (grid[++i])
		if (grid[i][0] != WALL || grid[i][i_max] != WALL)
			return (0);
	--i;
	i_max = -1;
	while (grid[i][++i_max])
		if (grid[i][i_max] != WALL)
			return (0);
	return (1);
}
