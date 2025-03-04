/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakarape <hakarape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:42:58 by hakarape          #+#    #+#             */
/*   Updated: 2025/03/04 13:42:05 by hakarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_texture(char *str)
{
	printf("word_count=%d\n", w_count(str, ' '));
	if (w_count(str, ' ') != 2)
		return (1);
	return(0);	
}
static int set_texture(int *texture, int *st)
{
	if (*texture != 1)
	{
		*texture = 1;
		(*st)++;
		return (1);
	}
		return (0);
}
int	is_there_texture(char *tex, t_map *game)
{
	static int ira;
	// printf("tex{%d}\n", game->texture.no);
	if (!my_strnstr(tex, "NO", int_strlen(tex)))
	{
		if(set_texture(&(game->texture.no), &ira))
			get_texture(tex,&(game->texture.north), "NO", game);
			// printf("hi\n");
		else
			return (0);
		// ira++;
		// game->texture.no = 1;
	}
	else if(!my_strnstr(tex, "SO", int_strlen(tex)))
	{
		if(set_texture(&(game->texture.so), &ira))
			get_texture(tex, &(game->texture.south), "SO", game);
		// printf("hi\n");
		else
			return (0);
		// ira++;
		// game->texture.so = 1;
	}
	else if(!my_strnstr(tex, "WE", int_strlen(tex)))
	{
		if(set_texture(&(game->texture.we), &ira))
			get_texture(tex, &(game->texture.west), "WE", game);
		// printf("hi\n");
		else
			return (0);
		
		// ira++;
		// game->texture.we = 1;
	}
	else if(!my_strnstr(tex, "EA", int_strlen(tex)))
	{
		if(set_texture(&(game->texture.ea), &ira))
			get_texture(tex, &(game->texture.east), "EA", game);	
		// printf("hi\n");
		else
			return (0);
		// ira++;
		// game->texture.ea = 1;	
	}
	else if(!my_strnstr(tex, "F", int_strlen(tex)))
	{
		if(set_texture(&(game->texture.f), &ira))
		{
			get_texture(tex, &(game->texture.floor), "F", game);
			floor_and_ceiling(game->texture.floor, game);
		}
		else
		return (0);
		// ira++;
		// game->texture.f = 1;	
	}
	else if(!my_strnstr(tex, "C", int_strlen(tex)))
	{
		if(set_texture(&(game->texture.c), &ira))
		{
			get_texture(tex, &(game->texture.ceiling), "C", game);
			floor_and_ceiling(game->texture.ceiling, game);
		}
		else
		return (0);
		// ira++;
		// game->texture.c = 1;
	}
	return (ira);
}

void floor_and_ceiling(char *str, t_map *game)
{
	int	i;
	char **mat;

	i = 0;
	mat = ft_split(str, ',');
	if (double_strlen(mat) != 3)
	{
		free_mem(mat);
		double_error("ERROR\nMAP IS INVALID\n", game->cub, 1, game);//mat free
	}
	while (mat[i])
	{
		if (ft_atoi(mat[i]) < 0 || ft_atoi(mat[i]) > 255)
			{
				free_mem(mat);
				double_error("ERROR\nMAP IS INVALID\n", game->cub, 1, game);//mat free
			}
		i++;	
	}
	free_mem(mat);
}

void get_texture(char *str, char **side, char *id, t_map *game)
{
	int		i;
	char 	**argv;

	i = 0;
	argv = ft_split(str, ' ');
	if (!argv || double_strlen(argv) != 2)
	{
		free_mem(argv);
		double_error("ERROR\nMAP IS INVALID\n", game->cub, 1, game);//argv free
	}
	if (argv[i])
	{
		if(ft_strcmp(argv[i], id) == 0)
		{
			// if (*side) 
			// 	free(*side);
			*side = ft_strdup(argv[++i]);
			free_mem(argv);
		}
		else
		{
			free_mem(argv);
			double_error("ERROR\nMAP IS INVALID\n", game->cub, 1, game);//argv free
		}
	}
}


