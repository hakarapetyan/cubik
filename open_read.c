/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:42:35 by hakarape          #+#    #+#             */
/*   Updated: 2025/06/02 00:51:00 by marvin           ###   ########.fr       */
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

	line = get_next_line(fd);
	if (!line)
		ft_error("ERROR\nTERE IS NOTHING TO READ\n", line);
	game->ind_row = 0;
	while (2)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		line = ft_strjoin(line, tmp);
		free(tmp);
		game->ind_row++;
		if (!line)
			ft_error("ERROR\nIT CAN NOT BE JOINED\n", line);
	}
	before_split(line, game);
	game->cub = ft_split(line, '\n');
	if (!game->cub)
		ft_error("ERROR\nREADING MAP\n", line);
	free(line);
	line=NULL;
	free(tmp);
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
	if((tmp = ft_strnstr(tex, "SO", int_strlen(tex))) && game->texture.so != 1)
	{
		game->texture.so = 1;
		(*count)++;
		return (tmp);
	}
	if((tmp = ft_strnstr(tex, "WE", int_strlen(tex))) && game->texture.we != 1)
	{
		game->texture.we = 1;
		(*count)++;
		return (tmp);
	}
	if((tmp = ft_strnstr(tex, "EA", int_strlen(tex))) && game->texture.ea != 1)
	{
		game->texture.ea = 1;
		(*count)++;
		return (tmp);
	}
	if((tmp = ft_strnstr(tex, "F", int_strlen(tex))) && game->texture.f != 1)
	{
		game->texture.f = 1;
		(*count)++;
		return (tmp);
	}
	if((tmp = ft_strnstr(tex, "C", int_strlen(tex))) && game->texture.c != 1)
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
void before_split(char *line, t_map *game)
{
	char *tmp;
	int	i;
	long len;
	static int count;

	i = 0;
	count = 0;
	tmp = check_texture_in_line(line,&count, game);
	if (tmp == NULL)
	{
		free(line);//avelacrats
		double_error("ERROR\nINVALID TEXTURE\n", NULL, 1, game);
	}
	while ((tmp = check_texture_in_line(line,&count, game)) && count != 6)
		;
		len = the_last_char_of_map(tmp);
		if (len <= 0)
			return ;//avelacvats
		printf("tmp=%s\n", tmp);
		while (tmp[i] && tmp[i] != '\n')
			i++;
			if (tmp[i + 1])
			{
			printf("tmp=%c\n", tmp[i+2]);
			i++;
			if (tmp[i] && (tmp[i] == ' ' || tmp[i] == '\n'))

				while (tmp[i] && (tmp[i] == ' ' || tmp[i] == '\n'))
					i++;
			if (tmp[i] && tmp[i] == '1' && tmp[i + 1] && i <= len)
			{
				while (tmp[i] && i <= len)
				{
					if (tmp[i + 1] && tmp[i] == '\n' && tmp[i + 1] == '\n' && i<= len)
						double_error("ERROR\nINVALID LINE\n", NULL, 1, game);
					i++;
				}
			}
			else
			{
				free(line);//avelacrats
				double_error("ERROR\nINVALID LIIIIIIINE\n", NULL, 1, game);
			}
		}		
}

