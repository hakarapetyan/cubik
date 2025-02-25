/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakarape <hakarape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:36:31 by hakarape          #+#    #+#             */
/*   Updated: 2025/02/24 20:44:24 by hakarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] && s2[i]) && (s1[i] == s2[i]) && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while ((s1[i] == s2[i]) && s1[i])
		i++;
	return ((unsigned char )(s1[i]) - (unsigned char )(s2[i]));
}
int	my_strnstr(char *haystack, char *needle, int len)
{
	int	need_len;

	if (*needle == '\0')
		return (-1);
	if (haystack == NULL && len == 0)
		return (-1);
	need_len = ft_strlen(needle);
	while (*haystack != '\0' && need_len <= len)
	{
		if (ft_strncmp(haystack, needle, need_len) == 0)
			return (0);
		len--;
		haystack++;
	}
	return (-1);
}
int	my_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}
char	*ft_strtrim(char *s1, char *set)
{
	int		i;
	int		j;
	int		k;
	char	*arr;

	i = 0;
	if (!s1 || !set)
	return (NULL);
	k = ft_strlen(set);
	while (s1[i] && my_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1) - 1;
	while (j > i && my_strchr(set, s1[j]))
		j--;
	k = 0;
	arr = (char *)malloc(sizeof(char) * ((j - i) + 2));
	if (arr == NULL)
		return (NULL);
	while (i <= j)
		arr[k++] = s1[i++];
	arr[k] = '\0';
	return (arr);
}
