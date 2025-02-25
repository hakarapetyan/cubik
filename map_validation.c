/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakarape <hakarape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:42:39 by hakarape          #+#    #+#             */
/*   Updated: 2025/02/25 16:31:01 by hakarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// void trim_map(t_map *game)
// {
//     int i;
//     char *tmp;

//     i = 0;
//     while(game->m_map[i])
//     {
//         tmp = game->m_map[i];
//         game->m_map[i] = ft_strtrim(game->m_map[i]," ");
//         free(tmp);
//         tmp = NULL;
//         i++;
//     }
// }
void the_last_column_ind(t_map *game)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (game->m_map[i])
    {
        while (game->m_map[i])
        {
            j = 0;
            while (game->m_map[i][j])
                j++;
            if (j-1 > game->ind_columns)
                game->ind_columns = j - 1;
            i++;
        }
    }
}

static int check_one_and_symb(char *str, char s, char symb, t_map *game)
{
    if (!s)
    return (0); 
    if (s != '1' && s != symb && s != 'N' && s != 'E' && s != 'W' && s != 'S') 
            double_error(str, game->cub, 1, game);
    return (1);
}

void check_map_symbols(t_map *game)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (game->m_map[i])
    {
        j = 0;
        while (game->m_map[i][j])
        {
            if (game->m_map[i][j] == '0')
            {
               if (j < (int_strlen(game->m_map[i]) - 1) && game->m_map[i][j + 1])
                check_one_and_symb("ERROR\nINVALID symbS\n", game->m_map[i][j + 1], '0', game);
                if (j != 0 && game->m_map[i][j - 1])
                    check_one_and_symb("ERROR\nINVALID symbS\n", game->m_map[i][j - 1], '0', game);
                if (i != 0 && game->m_map[i - 1][j])
                    check_one_and_symb("ERROR\nINVALID symbS\n", game->m_map[i - 1][j], '0', game);
                if (i != game->ind_row  && game->m_map[i + 1][j])
                    check_one_and_symb("ERROR\nINVALID symbS\n", game->m_map[i + 1][j], '0', game);
            }
            j++;
        }
        i++;
    }
}

static char *reallocation(char *str, int  columns)
{
	int	i;
	char *real;

	i = 0;
	if (!str)
		return (NULL);
	real = malloc(sizeof(char) * (columns + 2));
	if (!real)
		return (NULL);
	if (!str[i])
		return (NULL) ;
	while (str[i])
	{
		real[i] = str[i];
		i++;
	}
	while (i <= columns)
	{
		real[i] = ' ';
		i++;	
	}
	real[i] = '\0';
	return (real);	
}
void fill_null(t_map *game)
{
    int i;
    int j;
	char *tmp;
    i = 0;

    if(!game || !game->m_map)
		return ;
    while (i < game->ind_row)
    {
        if (!game->m_map[i])
			return ;
        j = int_strlen(game->m_map[i]) - 1;
        if (j < game->ind_columns)
        {
            while (j < game->ind_columns)
            {
				tmp = game->m_map[i];
                game->m_map[i] = reallocation(game->m_map[i], game->ind_columns);
				//free kartsum em
				free(tmp);
                j++; 
            }
        }
        i++;
    }
}
