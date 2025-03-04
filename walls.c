/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakarape <hakarape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:43:21 by hakarape          #+#    #+#             */
/*   Updated: 2025/02/24 20:43:21 by hakarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int check_one_and_space(char *str, char s,t_map *game)
{
    if (!s)
        return (0); 
    if (s != '1' && s != ' ')
        double_error(str, game->cub, 1, game);
    return (1);
}
static void empty_line_spaces(t_map *game, int *i)
{
    if (game->m_map[*i] && are_spaces_in_empty_line(game->m_map[*i]))
        while (game->m_map[*i] && are_spaces_in_empty_line(game->m_map[*i]))
            (*i)++;

}
static void last_horizontal_wall(t_map *game)
{
	int	i;
	int	j;

    i = game->ind_row;
	j = 0;
    if (game->m_map[i] && are_spaces_in_empty_line(game->m_map[i]))
        while (game->m_map[i] && are_spaces_in_empty_line(game->m_map[i]))
            i--;
    if (game->m_map[i])
    { 
        j = 0;
        while (game->m_map[i][j])
        {
           if(!check_one_and_space("ERROR\nHORIZONTAL WALL IS INVALID\n", game->m_map[i][j],game))
                break;
            j++;    
        }
    }
}
void horizontal_wall(t_map *game)
{
    int j;
    int i;

    j = 0;
    i = 0;
	empty_line_spaces(game, &i);
    if (game->m_map[i])
    {
        while (game->m_map[i][j])
        {
            if (!check_one_and_space("ERROR\nHORIZONTAL WALL IS INVALID\n", game->m_map[i][j],game))
            break;
            j++;        
        }
    }
	last_horizontal_wall(game);
}
static void last_vertical_wall(t_map *game)
{
    int i;
    int j;

    i=0;
    j=0;
    if (game->m_map[i])
    { 
        while (game->m_map[i])
        {
           j = game->ind_columns;
           if (game->m_map[i][j])
           {
                if (game->m_map[i][j] == SPACE)
                {
                    while (j >= 0 && game->m_map[i][j] && game->m_map[i][j] == SPACE)
                        j--;
                }
                if (j >= 0 && game->m_map[i][j] && game->m_map[i][j] != '1')
                    double_error("ERROR\nVERTICAL WALL IS INVALID\n", game->cub, 1, game);     
           }
            i++;
        }
    }   
}
void vertical_wall(t_map *game)
{
    int i;

    int j ;
    j = 0;
    i = 0;
    empty_line_spaces(game, &i);
    if (game->m_map[i])
    {   
        while(game->m_map[i])
        {
            j = 0;
            if(!are_spaces_in_empty_line(game->m_map[i]))
            {
                while (game->m_map[i][j] && game->m_map[i][j] == SPACE)
                    j++;
                if (game->m_map[i][j] && game->m_map[i][j] != '1')
                double_error("ERROR\nVERTICAL WALL IS INVALID\n", game->cub, 1, game);
            }
            i++;
        }
    }
    last_vertical_wall(game);
}
