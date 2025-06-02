/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakarape <hakarape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:12:57 by hakarape          #+#    #+#             */
/*   Updated: 2025/02/24 20:36:15 by hakarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_game(t_map *game)
{
	game->ind_row = 0;
	game->ind_columns = 0;
	game->start_position = 0;
	game->map_begining = 0;
}

void	texture_init(t_map *game)
{
	game->texture.floor = NULL;
	game->texture.ceiling = NULL;
	game->texture.north = NULL;
	game->texture.south = NULL;
	game->texture.east = NULL;
	game->texture.west = NULL;
	game->texture.no = 0;
	game->texture.so = 0;
	game->texture.we = 0;
	game->texture.ea = 0;
	game->texture.f = 0;
	game->texture.c = 0;
}