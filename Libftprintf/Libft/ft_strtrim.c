/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 15:52:29 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 08:41:22 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		getsize(char const *s1, char const *set, int option)
{
	int i;
	int j;
	int results[2];

	i = -1;
	results[0] = 0;
	while (s1[++i])
	{
		j = -1;
		while (set[++j])
			if (s1[i] == set[j] && results[0] == i)
				results[0]++;
	}
	results[1] = i - 1;
	while (s1[--i] && i > 0)
	{
		j = -1;
		while (set[++j])
			if (s1[i] == set[j] && results[1] == i)
				results[1]--;
	}
	if (option == 0)
		return (results[1] - results[0]);
	else
		return (results[0]);
}

char			*ft_strtrimr(char *s1, char const *set)
{
	char	*newstr;
	int		start;
	int		size;
	int		i;

	if ((size = getsize(s1, set, 0)) < 0)
		size = 0;
	if (!(newstr = malloc(sizeof(char) * (size + 2))))
		return (NULL);
	start = getsize(s1, set, 1);
	i = 0;
	while (i <= size)
	{
		newstr[i] = s1[start];
		start++;
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
