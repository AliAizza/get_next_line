/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 02:40:03 by aaizza            #+#    #+#             */
/*   Updated: 2021/11/19 23:05:45 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include<unistd.h>
#include<stdlib.h>

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int	ft_ckeckline(char *s);
#endif