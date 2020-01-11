/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_substr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 14:20:50 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/09 13:41:44 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	size_t	i;
	char	*src2;

	i = 0;
	while (src[i] != '\0')
		i++;
	if (start > i)
		len = 0;
	if (!(src2 = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (len == 0)
	{
		src2[0] = '\0';
		return (src2);
	}
	i = 0;
	while (i < len)
	{
		src2[i] = src[start + i];
		i++;
	}
	src2[i] = '\0';
	return (src2);
}
