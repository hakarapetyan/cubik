/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   during_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:42:12 by hakarape          #+#    #+#             */
/*   Updated: 2025/06/01 15:58:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	spaces_in_map(t_map *game)
{
	int	i;

	i = 0;
	while(game->m_map[i])
	{
		if (my_strchr(game->m_map[i], '1'))
			game->map_begining = 1;
		if (game->m_map[game->ind_row] && are_spaces_in_empty_line(game->m_map[game->ind_row]))
			while (game->m_map[game->ind_row] && are_spaces_in_empty_line(game->m_map[game->ind_row]))
				game->ind_row--;
		if (are_spaces_in_empty_line(game->m_map[i]) && game->map_begining == 1 && i <= game->ind_row)
			double_error("ERROR\nSPACES IN EMPTY LINE\n", game->cub, 1, game);
		i++;
	}
	return(0);
}

int check_char_in_map(char *str, t_map *game)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'N' || str[i] == 'E' || str[i] == 'W' || str[i] == 'S')
			game->start_position++;
		if(str[i] != 'N' && str[i] != 'E' && str[i] != 'W' && str[i] != 'S' && str[i] != '0' && str[i] != '1' && str[i] != ' ')
			double_error("2ERROR\nINVALID CHAR\n", game->cub, 1, game);	
		i++;
	}
	return (0);
}
void	map_start(t_map *game)
{
	int	i;

	i = 0;
	game->ind_row = double_strlen(game->m_map) - 1;
	while (game->m_map[i] && !check_char_in_map(game->m_map[i], game))
		i++;
	if(game->start_position != 1)
		double_error("3ERROR\nINVALID CHAR\n", game->cub, 1, game);
	if (!spaces_in_map(game))
		printf("good\n");
	
}