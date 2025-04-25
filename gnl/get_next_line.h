/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:04:30 by mrocher           #+#    #+#             */
/*   Updated: 2023/11/07 13:19:48 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

int			ft_strlen(char const *str);
char		*ft_strjoin(char const *s1, char const *s2);
char		*join_free(char *buffer, char *buf);
char		*get_next_line(int fd);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strchr(const char *s, int c);

#endif