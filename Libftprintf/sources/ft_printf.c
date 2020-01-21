/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 12:53:08 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/12 15:38:07 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strjoindel(char const *s1, char const *s2, t_vals *lst, int test)
{
	int		i;
	int		y;
	char	*result;

	i = 0;
	if (s1 == lst->result)
		i = lst->extrasize;
	else
		i = ft_strlen(s1);
	if (lst->convert == 'c')
		y = test ? 1 : lst->width;
	else
		y = ft_strlen(s2);
	if (!(result = ft_calloc(sizeof(char), (i + y + 1))))
	{
		free((void *)s1);
		return (NULL);
	}
	while (s2 && y--)
		result[i + y] = s2[y];
	while (s1 && i--)
		result[i] = s1[i];
	if (s1)
		free((void *)s1);
	return (result);
}

char	*ft_uptochar(char *str, int c)
{
	int		i;
	char	*src2;

	i = 0;
	while (str && str[i] && str[i] != c)
		i++;
	if (!(src2 = (char *)malloc(sizeof(char) * (i + 1))))
	{
		if (str)
			free((void *)str);
		return (NULL);
	}
	i = 0;
	while (str && str[i] != c)
	{
		src2[i] = str[i];
		i++;
	}
	src2[i] = '\0';
	str = src2;
	return (str);
}

int		readline2(t_vals *stuff, char *str, int *y, int *i)
{
	codelyoko(stuff);
	if (!(stuff->str2 = ft_uptochar(str + *y, '%')))
		return (0);
	if (!(stuff->result = ft_strjoindel(stuff->result, stuff->str2, stuff, 0)))
		return (0);
	stuff->extrasize += ft_strlen(stuff->str2);
	if (stuff->str2)
		free(stuff->str2);
	if (!(*i = ft_pourcent(stuff, str, *i, stuff->ap)))
		return (0);
	if (!(ft_convert(stuff, stuff->ap, stuff->result)))
		return (0);
	*y = *i + 1;
	if (!(stuff->result =
		ft_strjoindel(stuff->result, stuff->content, stuff, 0)))
	{
		free(stuff->content);
		return (0);
	}
	stuff->extrasize += (stuff->convert == 'c')
		? stuff->width : ft_strlen(stuff->content);
	free(stuff->content);
	return (1);
}

int		readline(char *str, t_vals *stuff)
{
	int		i;
	int		y;

	y = 0;
	i = -1;
	while (++i < (int)ft_strlen(str))
	{
		if (str[i] == '%')
		{
			i++;
			if (!(readline2(stuff, str, &y, &i)))
				return (0);
		}
	}
	codelyoko(stuff);
	if (!(stuff->result = ft_strjoindel(stuff->result, str + y, stuff, 0)))
		return (0);
	stuff->extrasize += ft_strlen(str + y);
	return (1);
}

int		ft_printf(const char *str, ...)
{
	int		i;
	t_vals	stuff;

	stuff.extrasize = 0;
	stuff.result = NULL;
	stuff.str2 = NULL;
	va_start(stuff.ap, str);
	if (!(readline((char *)str, &stuff)))
		return (-1);
	i = stuff.extrasize;
	write(1, stuff.result, i);
	free(stuff.result);
	va_end(stuff.ap);
	return (i);
}
