/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/22 11:50:33 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/15 18:49:40 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

char	*uptochar(char *leftover, int c, char **line)
{
	int		i;
	char	*src2;
	char	*temp;

	if (!(src2 = (char *)malloc(sizeof(char) * (ft_strlen2(leftover) + 1))))
	{
		if (leftover)
			free((void *)leftover);
		return (NULL);
	}
	i = 0;
	while (leftover && leftover[i] != c)
	{
		src2[i] = leftover[i];
		i++;
	}
	src2[i] = '\0';
	*line = src2;
	temp = ft_strdup2(ft_strchr2(leftover, c));
	free(leftover);
	return (temp);
}

char	*nextend(char *leftover, int fd)
{
	char	*buf;
	int		i;

	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
	{
		if (leftover)
			free((void *)leftover);
		return (NULL);
	}
	i = BUFFER_SIZE;
	while (!ft_strchr2(leftover, '\n') && i == BUFFER_SIZE)
	{
		i = read(fd, buf, BUFFER_SIZE);
		buf[i == BUFFER_SIZE ? BUFFER_SIZE : i] = '\0';
		leftover = ft_strjoinrem(leftover, buf);
	}
	free(buf);
	return (leftover);
}

int		get_next_line(int fd, char **line)
{
	char			*buf;
	static char		*left[256];

	if (!(buf = malloc(sizeof(char) * (1))))
		return (-1);
	else if (fd < 0 || BUFFER_SIZE < 1 || !line || read(fd, buf, 0) < 0)
	{
		free(buf);
		return (-1);
	}
	free(buf);
	if (left[fd] && ft_strchr2(left[fd], '\n'))
		left[fd] = uptochar(left[fd], '\n', line);
	else if (ft_strchr2(left[fd] = nextend(left[fd], fd), '\n'))
		left[fd] = uptochar(left[fd], '\n', line);
	else if (ft_strchr2(left[fd], '\0'))
	{
		left[fd] = uptochar(left[fd], '\0', line);
		return (0);
	}
	else
		return (-1);
	return (1);
}
