/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 02:43:19 by aaizza            #+#    #+#             */
/*   Updated: 2021/11/19 23:08:20 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_getline(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, str, i + 1);
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_getremain(char *str)
{
	int		i;
	char	*remain;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	remain = malloc((ft_strlen(str) - i + 1) * sizeof(char));
	if (!remain)
		return (NULL);
	i++;
	ft_strlcpy(remain, str + i, ft_strlen(str) - i + 1);
	free(str);
	return (remain);
}

char	*ft_get(int fd, char *save)
{
	char	*buff;
	int		size;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	size = 1;
	while (!ft_ckeckline(save) && size != 0)
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (size == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[size] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*arr[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	arr[fd] = ft_get(fd, arr[fd]);
	if (!arr[fd])
		return (NULL);
	line = ft_getline(arr[fd]);
	arr[fd] = ft_getremain(arr[fd]);
	return (line);
}

#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd1 = open("txxt.txt", 2);
    int fd2 = open("txt.txt", 2);
    printf("%s", get_next_line(fd1));
    printf("%s", get_next_line(fd2));
    printf("%s", get_next_line(fd1));
    printf("%s", get_next_line(fd2));
}