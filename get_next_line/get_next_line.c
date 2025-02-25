/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakarape <hakarape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:09:52 by hakarape          #+#    #+#             */
/*   Updated: 2024/07/02 15:52:49 by hakarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	n_check(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = r_string(buffer, fd);
	line = g_string(buffer);
	buffer = c_string(buffer);
	return (line);
}
/*int main()
 {
 	int fd;
 	fd = open("text1.txt", O_RDONLY);
 	//printf("%d\n", fd);
 	fd = open("text4.txt", O_RDONLY);
 	//printf("%d\n", fd);
 	//printf("%d\n", OPEN_MAX);
 	printf("%s", get_next_line(67));
 	//printf("%s", get_next_line(4));
 	//printf("%s", get_next_line(3));
 	//printf("%s", get_next_line(4));
 	// // printf("line: %s", get_next_line(fd));
 	// // printf("line: %s", get_next_line(fd));
 	// // 	printf("line: %s", get_next_line(fd));
 	// // printf("line: %s\n", get_next_line(fd));
 }
// int main(){
// 	int fd = 1000;
// 	//int fd2;
// 	char *line;
// 	//fd2 = open("text1.txt",O_RDONLY);
// 	//printf("%s",get_next_line(fd));
// 	line = get_next_line(fd);
// }*/