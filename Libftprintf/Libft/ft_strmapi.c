/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 11:17:45 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/09 19:43:52 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*news;

	i = 0;
	while (s[i])
		i++;
	if (!(news = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	news[i] = '\0';
	i = 0;
	while (s[i])
	{
		news[i] = f(i, s[i]);
		i++;
	}
	return (news);
}
