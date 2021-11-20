/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 02:43:19 by aaizza            #+#    #+#             */
/*   Updated: 2021/11/20 23:53:44 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char *ft_till_line(char *s)
{
    int i;

    if (!s ||!s[0])
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (ft_substr(s, 0, i + 1));
}

char *ft_readline(int fd, char *str)
{
	int i;
	char *s;

	s = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 1;
	while (!ft_checkline(s) && i != 0)
	{
		i = read(fd, s, BUFFER_SIZE);
		if (i == -1)
		{
			free(s);
			return (NULL);
		}
		s[i] = '\0';
		str = ft_strjoin(str, s);
	}
	free(s);
	return (str);
}

char *ft_getremain(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '\n')
			return (ft_substr(s, i + 1, ft_strlen(s)));
		i++;
	}
	return (0);
}

char *get_next_line(int fd)
{
	static char *r = 0;
	char *n;
	char *a;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	r = ft_readline(fd, r);
	if (!r)
		return (NULL);
	n = ft_till_line(r);
	a = r;
	r = ft_getremain(r);
	free(a);
	return (n);
}

// #include <fcntl.h>
// #include <stdio.h>

// int main()
// {
// 	int fd1 = open("txxt.txt", O_RDWR);
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd1));
// }