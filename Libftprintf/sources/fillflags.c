/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillflags.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 12:53:08 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/12 14:40:49 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		flag_u(t_vals *lst, va_list va)
{
	lst->content = ft_itoa_base(
		va_arg(va, unsigned int), "0123456789", lst->preci);
	return (1);
}

int		flag_percent(t_vals *lst)
{
	char *str;

	if (!(str = malloc(sizeof(char) * 2)))
		return (0);
	str[0] = '%';
	str[1] = '\0';
	lst->content = str;
	return (1);
}

int		flag_n(va_list va, char *result)
{
	*(va_arg(va, int*)) = ft_strlen(result);
	return (1);
}

int		ft_whitespaces(t_vals *lst, int i)
{
	char	*str;

	if ((i = lst->width - (lst->convert == 'c' ? 1 :
		ft_strlen(lst->content))) > 0 && lst->convert != 'n')
	{
		if (!(str = ft_calloc(sizeof(char), (i + 1))))
			return (0);
		ft_setstr(&str, lst, i);
		if (!lst->minus)
		{
			if (!(str = ft_strjoindel(str, lst->content, lst, 1)))
				i = 0;
			free(lst->content);
			lst->content = str;
		}
		else
		{
			if (!(lst->content = ft_strjoindel(lst->content, str, lst, 0)))
				i = 0;
			free(str);
		}
	}
	else
		i = 1;
	return (i);
}

int		ft_convert(t_vals *lst, va_list va, char *result)
{
	int i;

	i = 1;
	if (lst->convert == 'c')
		i = flag_c(lst, va);
	else if (lst->convert == 's')
		!flag_s(lst, va) ? i-- : i;
	else if (lst->convert == 'p')
		i = flag_p(lst, va);
	else if (lst->convert == 'd' || lst->convert == 'i')
		i = flag_i(lst, va);
	else if (lst->convert == 'x' || lst->convert == 'X')
		i = flag_x(lst, va);
	else if (lst->convert == 'u')
		i = flag_u(lst, va);
	else if (lst->convert == '%')
		i = flag_percent(lst);
	else if (lst->convert == 'n')
		i = flag_n(va, result);
	i = ft_whitespaces(lst, 0);
	if (i)
		return (1);
	free(result);
	free(lst->content);
	return (0);
}
