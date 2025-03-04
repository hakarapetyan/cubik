/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:42:58 by hakarape          #+#    #+#             */
/*   Updated: 2025/03/04 23:09:01 by marvin           ###   ########.fr       */
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
// static int set_get_texture(t_map *game, char *tex, int tex_count, char *texture)
// {
// 	static int ira;
	
// 	if(set_texture(&tex_count, &ira))
// 	{
// 		get_texture(tex,&texture, "NO", game);
// 		if (ft_strcmp(texture, game->texture.floor) == 0 || ft_strcmp(texture, game->texture.ceiling) == 0)
// 			floor_and_ceiling(texture, game);	
// 	}
// 	else
// 		return (0);
// 	return (ira);
// }
// int	is_there_texture(char *tex, t_map *game)
// {
	// 	int res;
	
// 	res = 0;
// 	if (!my_strnstr(tex, "NO", int_strlen(tex)) && !(res = set_get_texture(game, tex, game->texture.no, game->texture.north)))
// 		return (0);
// 	else if(!my_strnstr(tex, "SO", int_strlen(tex)) && !(res=set_get_texture(game, tex, game->texture.so, game->texture.south)))
// 		return (0);
// 	else if(!my_strnstr(tex, "WE", int_strlen(tex)) && !(res=set_get_texture(game, tex, game->texture.we, game->texture.west)))
// 		return (0);
// 	else if(!my_strnstr(tex, "EA", int_strlen(tex)) && !(res=set_get_texture(game, tex, game->texture.ea, game->texture.east)))
// 			return (0);	
// 	else if(!my_strnstr(tex, "F", int_strlen(tex)) && !(res=set_get_texture(game, tex, game->texture.f, game->texture.floor)))
// 			return (0);
// 	else if(!my_strnstr(tex, "C", int_strlen(tex)) && !(res=set_get_texture(game, tex, game->texture.c, game->texture.ceiling)))
// 			return (0);
// 	printf("res=%d\n", res);
// 	return (res);
// }
static int helper(char *tex, t_map *game, int *ira)
{
	if (!my_strnstr(tex, "NO", int_strlen(tex)))
	{
		if(set_texture(&(game->texture.no), ira))
			get_texture(tex,&(game->texture.north), "NO", game);
		else
			return (0);
	}
	else if(!my_strnstr(tex, "SO", int_strlen(tex)))
	{
		if(set_texture(&(game->texture.so), ira))
			get_texture(tex, &(game->texture.south), "SO", game);
		else
			return (0);
	}
	else if(!my_strnstr(tex, "WE", int_strlen(tex)))
	{
		if(set_texture(&(game->texture.we), ira))
			get_texture(tex, &(game->texture.west), "WE", game);
		else
			return (0);
	}
	return (1);
}
int	is_there_texture(char *tex, t_map *game)
{
	static int ira;
	
	if(!my_strnstr(tex, "EA", int_strlen(tex)))
	{
		if(set_texture(&(game->texture.ea), &ira))
			get_texture(tex, &(game->texture.east), "EA", game);	
		else
			return (0);	
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
	}
	else if (!helper(tex, game, &ira))
		return (0);
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


