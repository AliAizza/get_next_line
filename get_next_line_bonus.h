/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 04:38:25 by aaizza            #+#    #+#             */
/*   Updated: 2021/11/21 19:40:14 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include<unistd.h>
# include<stdlib.h>

int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_checkline(char *s);
char	*get_next_line(int fd);
char	*ft_substr(char *s, int start, int len);
#endif