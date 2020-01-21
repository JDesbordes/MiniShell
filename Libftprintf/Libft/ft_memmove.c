/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 15:35:33 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/23 09:59:16 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (!(dest) && !(src))
		return (NULL);
	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	i = -1;
	if (str1 == str2)
		return (dest);
	if (str1 < str2)
		while (++i != (int)n)
			str1[i] = str2[i];
	else
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			str1[i] = str2[i];
			i--;
		}
	}
	dest = str1;
	return (dest);
}
