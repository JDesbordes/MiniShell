/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 12:21:40 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 14:00:34 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	str = (char *)s;
	j = -1;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			j = i;
		}
		i++;
	}
	if (j > -1)
		return (str + j);
	else if (str[i] == c)
		return (str + i);
	return (NULL);
}
