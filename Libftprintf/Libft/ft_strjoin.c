/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 14:39:50 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 22:04:19 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		y;
	char	*result;

	i = 0;
	while (s1[i] != '\0')
		i++;
	y = 0;
	while (s2[y] != '\0')
		y++;
	if (!(result = malloc(sizeof(char) * (y + i + 1))))
		return (NULL);
	i = -1;
	y = 0;
	while (s1[++i])
		result[i] = s1[i];
	while (s2[y])
	{
		result[i + y] = s2[y];
		y++;
	}
	result[i + y] = '\0';
	return (result);
}
