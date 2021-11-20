/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 02:35:54 by aaizza            #+#    #+#             */
/*   Updated: 2021/11/21 00:20:40 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	s = malloc((i + j + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		s[i] = s1[i];
	while (s2[j])
		s[i++] = s2[j++];
	s[i] = '\0';
	return (s);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	int		j;
	char	*a;
	char	*sub;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	a = (char *)s;
	i = 0;
	j = 0;
	while (i < len && a[start + i])
		i++;
	sub = malloc((i + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (j < i)
	{
		sub[j] = a[start + j];
		j++;
	}
	sub[j] = '\0';
	return (sub);
}

int ft_checkline(char *s)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
