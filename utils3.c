/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:36:12 by hakarape          #+#    #+#             */
/*   Updated: 2025/06/01 22:36:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

long	int_strlen(char *str)
{
	long	i;

	i = 0;
	if (!str || !(*str))
		return (0);
	while (str[i])
		i++;
	return (i);
}
int	is_cub(char *str)
{
	int	n;

	n = int_strlen(str);
	if (str[n - 1] == 'b' && str[n - 2] == 'u'
		&& str[n - 3] == 'c' && str[n - 4] == '.')
		return (1);
	return (0);
}
void	ft_error(char *str, char *str1)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	free(str1);
	exit(1);
}
void	double_error(char *str, char **split, int flag, t_map *game)
{
	int	i;

	i = 0;
	if (str)
		write(2, str, int_strlen(str));
	if (str == NULL || split == NULL)
		exit(1);
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
	if (flag)
		free_textures(game);
	exit(1);
}
void	arg_val(int argc, char **argv)
{
	if (argc != 2)
		ft_error("ERROR\nARGC != 2\n", NULL);
	if (!is_cub(argv[1]))
		ft_error("ERROR\nIS NOT CUB\n", NULL);
}