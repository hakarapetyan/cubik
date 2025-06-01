/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:36:23 by hakarape          #+#    #+#             */
/*   Updated: 2025/06/01 16:16:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
// static void print_map(t_map *game)
// {
// 	int i =0;
// 	while(game->m_map[i])
// 	{
// 		// int j=0;
// 		// while(game->m_map[i][j])
// 		// {
// 		// 	printf("%c",game->m_map[i][j]);
// 		// 	j++;	
// 		// }
// 		printf("{%s}\n", game->m_map[i]);
// 		i++;
// 	}
// }
void free_textures(t_map *game)
{
    if (game->texture.no) free(game->texture.north);
    if (game->texture.so) free(game->texture.south);
    if (game->texture.we) free(game->texture.west);
    if (game->texture.ea) free(game->texture.east);
    if (game->texture.floor) free(game->texture.floor);
    if (game->texture.ceiling) free(game->texture.ceiling);
}

static void open_read_init(int argc, int *fd, char **argv, t_map *game)
{
	arg_val(argc, argv);
	open_file(fd, argv);
	init_game(game);
	texture_init(game);
	map_read(*fd, game);
	texture_init(game);
}
static void start_and_fill(t_map *game)
{
	start_validation(game);
	the_last_column_ind(game);
	fill_null(game);
}
static void map_validation(t_map *game)
{
	map_start(game);
	horizontal_wall(game);
	vertical_wall(game);
	check_map_symbols(game);
}
int main(int argc, char **argv)
{
	int		fd;
	t_map	game;
	
	open_read_init(argc, &fd, argv, &game);
	start_and_fill(&game);
	map_validation(&game);
	close(fd);
	free_textures(&game);
	free_mem(game.cub);
	//print_map(&game);
	//system("leaks cub3D");
	return (0);
}