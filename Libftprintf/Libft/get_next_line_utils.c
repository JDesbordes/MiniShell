/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/22 16:36:39 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/15 17:47:33 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen2(const char *str)
{
	size_t		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup2(const char *src)
{
	int		i;
	char	*src2;

	i = 0;
	while (src && src[i] != '\0')
		i++;
	if (i == 0)
		return (NULL);
	if (!(src2 = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (src && src[i])
	{
		src2[i] = src[i];
		i++;
	}
	src2[i] = '\0';
	return (src2);
}

char	*ft_strchr2(const char *s, int c)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	str = (char *)s;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			return (str + i + 1);
		}
		i++;
	}
	if (str[i] == c)
		return (str + i);
	return (NULL);
}

char	*ft_strjoinrem(char const *s1, char const *s2)
{
	int		i;
	int		y;
	char	*result;

	i = ft_strlen2(s1);
	y = ft_strlen2(s2);
	if (!(result = malloc(sizeof(char) * (i + y + 1))))
	{
		if (s1)
			free((void *)s1);
		return (NULL);
	}
	result[i + y] = '\0';
	while (s2 && y--)
		result[i + y] = s2[y];
	while (s1 && i--)
		result[i] = s1[i];
	if (s1)
		free((void *)s1);
	return (result);
}
