/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillflags2.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 14:33:16 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/12 14:28:57 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		flag_c(t_vals *lst, va_list va)
{
	char *c;

	if (!(c = malloc(sizeof(char) * 2)))
		return (0);
	c[0] = va_arg(va, int);
	c[1] = '\0';
	lst->width = lst->width ? lst->width : 1;
	lst->content = c;
	return (1);
}

int		flag_i(t_vals *lst, va_list va)
{
	long j;
	char *str;

	j = (long)va_arg(va, int);
	if (j < 0)
	{
		lst->addminus = 1;
		j *= -1;
	}
	if (!(lst->content = ft_itoa_base(j, "0123456789", lst->preci)))
		return (0);
	if (lst->addminus == 1 && (lst->minus ||
		(j = lst->width - ft_strlen(lst->content)) < 0))
	{
		lst->addminus = 0;
		str = lst->content;
		if (!(lst->content = ft_strjoindel(ft_strdup("-"),
			lst->content, lst, 0)))
		{
			free(str);
			return (1);
		}
		free(str);
	}
	return (1);
}

char	*flag_s(t_vals *lst, va_list va)
{
	char *str;

	str = va_arg(va, char *);
	if (!str)
	{
		if (lst->preci == -1)
			return (lst->content = ft_strdup("(null)"));
		else
			return (lst->content = ft_substr("(null)", 0, lst->preci));
	}
	else if (lst->preci == -1)
		return (lst->content = ft_strdup(str));
	else
		return (lst->content = ft_substr(str, 0, lst->preci));
}

int		flag_p(t_vals *lst, va_list va)
{
	long j;
	char *str2;

	j = (long)va_arg(va, void *);
	if (!(lst->content = ft_strdup("0x")))
		return (0);
	if (!(str2 = ft_itoa_base(j, "0123456789abcdef", lst->preci)))
		return (0);
	if (!(lst->content = ft_strjoindel(lst->content, str2, lst, 0)))
	{
		free(str2);
		return (0);
	}
	free(str2);
	return (1);
}

int		flag_x(t_vals *lst, va_list va)
{
	char	*str;
	int		i;

	i = 1;
	if (lst->flag == '#')
		if (!(lst->content = lst->convert == 'x' ?
			ft_strdup("0x") : ft_strdup("0X")))
			return (0);
	if (lst->convert == 'x')
	{
		if (!(str = ft_itoa_base(
			va_arg(va, unsigned int), "0123456789abcdef", lst->preci)))
			return (0);
	}
	else if (!(str = ft_itoa_base(
		va_arg(va, unsigned int), "0123456789ABCDEF", lst->preci)))
		return (0);
	if (!(lst->content = ft_strjoindel(lst->content, str, lst, 0)))
		i = 0;
	free(str);
	return (i);
}
