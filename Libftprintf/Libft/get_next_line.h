/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/23 10:14:30 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/15 17:47:17 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# define BUFFER_SIZE 64

char		*ft_strchr2(const char *s, int c);
char		*ft_strjoinrem(char const *s1, char const *s2);
size_t		ft_strlen2(const char *str);
char		*ft_strdup2(const char *src);
char		*uptochar(char *leftover, int c, char **line);
char		*nextend(char *leftover, int fd);
int			get_next_line(int fd, char **line);

#endif
