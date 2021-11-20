/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 02:40:03 by aaizza            #+#    #+#             */
/*   Updated: 2021/11/20 22:46:05 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include<unistd.h>
#include<stdlib.h>

int     ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_checkline(char *s);
char    *get_next_line(int fd);
char    *ft_substr(char *s, int start, int len);
#endif