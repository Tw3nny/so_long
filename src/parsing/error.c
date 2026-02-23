/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matiguti <matiguti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:32:20 by matisgutier       #+#    #+#             */
/*   Updated: 2026/02/17 11:08:23 by matiguti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	error(char *msg, t_map *map)
{
	ft_printf("Error\n : %s\n", msg);
	if (map && map->grid)
		free_grid(map->grid, map->height);
	exit(1);
}
