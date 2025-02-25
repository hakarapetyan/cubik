/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakarape <hakarape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:13:22 by hakarape          #+#    #+#             */
/*   Updated: 2024/07/02 15:52:10 by hakarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, unsigned int start,
size_t len)
{
	size_t	i;
	int		j;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	j = start;
	while (s[j] && i < len)
	{
		str[i] = s[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*arr;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	arr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (arr == NULL)
		return (NULL);
	if (s1)
		while (s1[++i])
			arr [i] = s1[i];
	while (s2[j])
		arr[i++] = s2[j++];
	arr[i] = '\0';
	free(s1);
	return (arr);
}

char	*r_string(char *buf, int fd)
{
	char	*tmp;
	int		count;

	count = 1;
	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	while (count != 0 && !n_check(buf))
	{
		count = read(fd, tmp, BUFFER_SIZE);
		if (count == -1)
		{
			free(buf);
			free(tmp);
			tmp = NULL;
			buf = NULL;
			return (NULL);
		}
		tmp[count] = '\0';
		buf = ft_strjoin(buf, tmp);
	}
	free(tmp);
	return (buf);
}

char	*g_string(char *buf)
{
	char	*tmp;
	int		i;
	int		len;

	i = 0;
	if (!buf || !buf[0])
		return (NULL);
	len = ft_strlen(buf);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (NULL);
	while (buf[i] && buf[i] != '\n')
	{
		tmp[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
	{
		tmp[i] = buf[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*c_string(char *buf)
{
	int		len;
	char	*final;
	int		i;

	if (!buf)
		return (NULL);
	len = ft_strlen(buf);
	i = 0;
	if (!buf)
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	final = ft_substr(buf, i + 1, len - i);
	free(buf);
	return (final);
}

// int main(){
//    char buf[] = "barev\nkl";
//     // char *aff;
//     // fd = open("text", O_RDONLY);
//     // aff = n_string(buf, fd);
//     printf("%zu", ft_strlen(buf));
//     // printf("%s", r_string(buf, fd));
//     // printf("%s", r_string(buf, fd));
// 	//  printf("%s", r_string(buf, fd));
// 	//   printf("%s", r_string(buf, fd));
// 	//    printf("%s", r_string(buf, fd));
// }