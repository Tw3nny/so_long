/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matisgutierreztw3nny <matisgutierreztw3    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:32:20 by matisgutier       #+#    #+#             */
/*   Updated: 2026/02/13 15:36:26 by matisgutier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *msg, t_map *map)
{
	ft_printf("Error : %s\n", msg);
	if (map && map->grid)
		free_grid(map->grid, map->height);
		exit(1);
}