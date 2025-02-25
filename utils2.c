/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakarape <hakarape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:43:12 by hakarape          #+#    #+#             */
/*   Updated: 2025/02/25 14:59:17 by hakarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_strdup(char *s1)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}
int double_strlen(char **argv)
{
	int i;
	
	i = 0;
	if (argv[i] == NULL)
		return (0);
	while (argv[i])
		i++;
	return (i);
}
static long	ft_nbr(const char *str)
{
	int		i;
	long	n;

	n = 0;
	i = 0;
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n);
}

long	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	count;

	sign = 1;
	i = 0;
	count = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign = -1;
			count++;
		}
		else if (str[i] == '+')
			count++;
		i++;
	}
	if (count > 1)
		return (0);
	return (ft_nbr(&str[i]) * sign);
}
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	need_len;

	if (*needle == '\0')
		return ((char *)haystack);
	if (haystack == NULL && len == 0)
		return (NULL);
	need_len = ft_strlen(needle);
	while (*haystack != '\0' && need_len <= len)
	{
		if (ft_strncmp(haystack, needle, need_len) == 0)
			return ((char *)haystack);
		len--;
		haystack++;
	}
	return (NULL);
}