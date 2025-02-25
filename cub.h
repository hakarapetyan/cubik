/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakarape <hakarape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:54:15 by hakarape          #+#    #+#             */
/*   Updated: 2025/02/25 16:33:50 by hakarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

# define HEIGHT 50
# define WIDTH 50
# define SCREEN_W 1920
# define SCREEN_H 1080

# define UP_W 126
# define DOWN_S 125
# define LEFT_A 123
# define RIGHT_D 124
# define ESC 53
# define SPACE 32

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;


typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
	int		no;
	int		so;
	int		we;
	int		ea;
	int		f;
	int		c;
}  t_texture;

typedef struct s_map
{
	char	**m_map;
	char	**cub;
	int		ind_row;
	int		ind_columns;
	int		start_position;
	int		map_begining;
	t_texture	texture;
}	t_map;

typedef enum s_side
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
}	t_side;

long	int_strlen(char *str);
void	ft_error(char *str, char *str1);
int		is_cub(char *str);
void	map_read(int fd, t_map *game);
char	**ft_split(char const *s, char c);
void	free_mem(char **split);
void	arg_val(int argc, char **argv);
void	open_file(int *fd, char **argv);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		are_spaces_in_empty_line(char *str);
int		start_validation(t_map *game);
char	*word_memory(char const *s, int f_ind, int l_ind);
char	**all_memory(char **split, char const *s, char c);
char	**ft_split(char const *s, char c);
int		check_texture(char *str);
int		w_count(char const *s, char c);
int		ft_strcmp(const char *s1, const char *s2);
int		is_there_texture(char *tex, t_map *game);
void	get_texture(char *str, char **side, char *id, t_map *game);
void	double_error(char *str, char **split, int flag, t_map *game);
int		my_strnstr(char *haystack, char *needle, int len);
int		spaces_in_map(t_map *game);
void	map_start(t_map *game);
int		my_strchr(const char *s, int c);
int		check_char_in_map(char *str, t_map *game);
void	init_game(t_map *game);
int		double_strlen(char **argv);
char	*ft_strtrim(char *s1, char *set);
void	horizontal_wall(t_map *game);
void	vertical_wall(t_map *game);
void	check_map_symbols(t_map *game);
// void	trim_map(t_map *game);
void	before_split(char *line, t_map *game);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	the_last_column_ind(t_map *game);
void	fill_null(t_map *game);
void	floor_and_ceiling(char *str, t_map *game);
char	*ft_strdup(char *s1);
long	ft_atoi(char *str);
void	texture_init(t_map *game);
void	free_textures(t_map *game);
#endif