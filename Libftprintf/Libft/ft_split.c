/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 17:17:19 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/11 03:05:41 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int				ischaracter(char character, char *c)
{
	int i;

	i = 0;
	while (c[i])
	{
		if (c[i] == character)
			return (1);
		i++;
	}
	return (0);
}

static int		count_word(char *str, char *c)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (ischaracter(str[i], c))
			i++;
		if (str[i] && !ischaracter(str[i], c))
			word++;
		while (str[i] && !ischaracter(str[i], c))
			i++;
	}
	return (word);
}

static char		**fill_split(char *s, char *c, char **split, int word)
{
	int		i;
	int		ind;
	int		j;

	i = 0;
	ind = 0;
	split[word] = 0;
	while (split[i])
	{
		j = 0;
		while (ischaracter(s[ind], c))
			ind++;
		while (s[ind] && !ischaracter(s[ind], c))
			split[i][j++] = s[ind++];
		split[i++][j] = 0;
	}
	return (split);
}

static char		**free_split(char **split, int word)
{
	int		i;

	i = 0;
	while (i < word)
		if (split[i])
			free(split[i++]);
	free(split);
	return (NULL);
}

char			**ft_split(char const *s, char *c)
{
	char	**split;
	int		i;
	int		len;
	int		ind;

	i = 0;
	len = 0;
	ind = 0;
	if (!(split = (char **)ft_calloc(
					count_word((char*)s, c) + 1, sizeof(char *))))
		return (NULL);
	while (i < count_word((char*)s, c))
	{
		len = 0;
		while (ischaracter(s[ind], c))
			ind++;
		while (s[ind] && !ischaracter(s[ind++], c))
			len++;
		ind--;
		if (len > 0)
			if (!(split[i++] = (char *)malloc(sizeof(char) * (len + 1))))
				return (free_split(split, count_word((char*)s, c)));
	}
	return (fill_split((char *)s, c, split, count_word((char*)s, c)));
}
