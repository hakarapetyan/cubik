/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakarape <hakarape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:42:21 by hakarape          #+#    #+#             */
/*   Updated: 2025/02/24 20:42:24 by hakarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	w_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

char	*word_memory(char const *s, int f_ind, int l_ind)
{
	int		j;
	char	*arr;

	j = 0;
	if (!s)
		return (NULL);
	arr = (char *)malloc(sizeof(char ) * (l_ind - f_ind + 1));
	if (!arr)
		return (NULL);
	while (f_ind < l_ind)
	{
		arr[j] = s[f_ind];
		f_ind++;
		j++;
	}
	arr[j] = '\0';
	return (arr);
}

char	**all_memory(char **split, char const *s, char c)
{
	size_t	i;
	int		j;
	int		first;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			first = i;
			while (s[i] != c && s[i])
				i++;
			split[j] = word_memory(s, first, i);
			j++;
		}
		else
			i++;
	}
	split[j] = 0;
	return (split);
}

void	free_mem(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (w_count(s, c) + 1));
	if (!arr)
		return (NULL);
	arr = all_memory(arr, s, c);
	return (arr);
}