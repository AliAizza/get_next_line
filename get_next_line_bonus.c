/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 04:36:06 by aaizza            #+#    #+#             */
/*   Updated: 2021/11/21 04:39:11 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_till_line(char *s)
{
	int	i;

	i = 0;
	if (!s[0])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	return (ft_substr(s, 0, i + 1));
}

char	*ft_get_remain(char *s)
{
	int	i;

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

char	*ft_read_line(int fd, char *s)
{
	char	*str;
	int		i;

	str = malloc (BUFFER_SIZE + 1);
	i = 1;
	while (!ft_checkline(s) && i)
	{
		i = read (fd, str, BUFFER_SIZE);
		if (i == -1)
		{
			free (str);
			return (NULL);
		}
		str[i] = '\0';
		s = ft_strjoin(s, str);
	}
	free (str);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*new;
	static char	*rem[1024];
	char		*l;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	rem[fd] = ft_read_line(fd, rem[fd]);
	if (!rem[fd])
		return (NULL);
	new = ft_till_line(rem[fd]);
	l = rem[fd];
	rem[fd] = ft_get_remain(rem[fd]);
	free(l);
	return (new);
}