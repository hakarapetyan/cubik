/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakarape <hakarape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:42:49 by hakarape          #+#    #+#             */
/*   Updated: 2025/02/24 20:42:49 by hakarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int are_spaces_in_empty_line(char *str)
{
	int i;

	i = 0;
	if(str != NULL && str[i] == SPACE)
	{
		while(str[i] && (str[i] == SPACE))
			i++;
		if (str[i] == '\0')
			return (1);
	}
	return(0);
}
static int start_validation_helper(t_map *game, int i)
{
	int tex;

	tex = 0;
	while(game->cub[i])
	{
		tex = is_there_texture(game->cub[i], game);
		if (tex == 0)
			double_error("ERROR\nINVALID TEXTURE\n", game->cub, 1, game);
		if (tex == 6)
		{
			i++;
			if (game->cub[i])
				game->m_map = &game->cub[i];
			else
				double_error("ERROR\nINVALID TEXTURE\n", game->cub, 1, game);
			return (0);	
		}
		i++;
	}
	if (tex != 6)
		double_error("ERROR\nINVALID TEXTURE\n", game->cub, 0, game);
	return (1);
}
int start_validation(t_map *game)
{
	int i;
	
	i = 0;
	game->m_map = NULL;
	if (game->cub[i])
	{
		while (game->cub[i] && are_spaces_in_empty_line(game->cub[i]))
			i++;
		if(game->cub[i] && !start_validation_helper(game, i))
			return (0);
	}
	return(0);
}
