/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 13:27:09 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 13:31:01 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t y;
	size_t sizea;
	size_t sizeb;

	sizea = 0;
	sizeb = 0;
	while (dest[sizea] != '\0')
		sizea++;
	while (src[sizeb] != '\0')
		sizeb++;
	if (size <= sizea)
		return (sizeb + size);
	i = 0;
	while (dest[i] != '\0' && i < size - 1)
		i++;
	y = 0;
	while (src[y] != '\0' && size - 1 > i)
	{
		dest[i] = src[y];
		i++;
		y++;
	}
	dest[i] = '\0';
	return (sizea + sizeb);
}
