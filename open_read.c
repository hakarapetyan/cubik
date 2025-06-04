/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:42:35 by hakarape          #+#    #+#             */
/*   Updated: 2025/06/04 15:01:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	open_file(int *fd, char **argv)
{
	*fd = open(argv[1], O_RDONLY);
	if (*fd == -1)
		ft_error("ERROR\nOPENING FILE\n", NULL);
}
void	map_read(int fd, t_map *game)
{
	char	*line;
	char	*tmp;
	char	*trim;
	static int count;

	count = 0;
	line = get_next_line(fd);
	if (!line)
		ft_error("ERROR\nTERE IS NOTHING TO READ\n", line);
	game->ind_row = 0;
	while (2)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		//trim = ft_strtrim(tmp,"\n\t\v");
		line = ft_strjoin(line, tmp);
		free(tmp);
		// free(trim);
		game->ind_row++;
		if (!line)
			ft_error("ERROR\nIT CAN NOT BE JOINED\n", line);
	}
	printf("line=%s\n",line);
	game->cub = ft_split(line, '\n');
	int i =0;
	if (!game->cub)
		ft_error("ERROR\nREADING MAP\n", line);
		
	while(game->cub[i])
	{
		printf("game=%s\n",game->cub[i]);
		before_split(game->cub[i],&count, game);
		i++;
	}
	free(line);
	line=NULL;
	free(tmp);
}
static int	which_texture_is_passed(char *line)
{
	static int	count;

	if (ft_strncmp(line, "NO", 2) == 0)
		count++;
	else if (ft_strncmp(line, "SO", 2) == 0)
		count++;
	else if (ft_strncmp(line, "EA", 2) == 0)
		count++;
	else if (ft_strncmp(line, "WE", 2) == 0)
		count++;
	else if (ft_strncmp(line, "F", 1) == 0)
		count++;
	else if (ft_strncmp(line, "C", 1) == 0)
		count++;
	return (count);
}
static char *check_texture_in_line(char *tex, int *count, t_map *game)
{
	char *tmp;
	
	if ((tmp = ft_strnstr(tex, "NO", int_strlen(tex))) && game->texture.no != 1)
	{
		game->texture.no = 1;
		(*count)++;
		return (tmp);
	}
	else if((tmp = ft_strnstr(tex, "SO", int_strlen(tex))) && game->texture.so != 1)
	{
		game->texture.so = 1;
		(*count)++;
		return (tmp);
	}
	else if((tmp = ft_strnstr(tex, "WE", int_strlen(tex))) && game->texture.we != 1)
	{
		game->texture.we = 1;
		(*count)++;
		return (tmp);
	}
	else if((tmp = ft_strnstr(tex, "EA", int_strlen(tex))) && game->texture.ea != 1)
	{
		game->texture.ea = 1;
		(*count)++;
		return (tmp);
	}
	else if((tmp = ft_strnstr(tex, "F", int_strlen(tex))) && game->texture.f != 1)
	{
		game->texture.f = 1;
		(*count)++;
		return (tmp);
	}
	else if((tmp = ft_strnstr(tex, "C", int_strlen(tex))) && game->texture.c != 1)
	{
		game->texture.c = 1;
		(*count)++;
		return (tmp);
	}
			return (NULL);
}
static long the_last_char_of_map(char *line)
{
	long	len;

	len = int_strlen(line) - 1;
	if (len >= 0 && line[len] && (line[len] == '\n' || line[len] == ' '))
	{
		while (len >= 0 && line[len] && (line[len] == '\n' || line[len] == ' '))
				len--;
	}
	return (len);
}
#include <ctype.h>
void before_split(char *line,int *count, t_map *game)
{
	char *tmp;
	int	i;
	long len;
}

