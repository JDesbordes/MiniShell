/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   readflags.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/30 18:56:35 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/12 15:40:01 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_setstr(char **str, t_vals *lst, int i)
{
	ft_memset(*str,
			(!lst->minus && (lst->zero && lst->preci == -1)) ? '0' : ' ', i);
	if (lst->addminus == 1)
	{
		if (!lst->minus && (lst->zero && lst->preci == -1))
			(*str)[0] = '-';
		else
			(*str)[i - 1] = '-';
	}
}

void	codelyoko(t_vals *lst)
{
	lst->preci = -1;
	lst->error = 0;
	lst->flag = 0;
	lst->zero = 0;
	lst->minus = 0;
	lst->addminus = 0;
	lst->width = 0;
	lst->convert = 0;
	lst->str2 = NULL;
	lst->content = NULL;
}

int		ft_is_conv(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'n'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int		ft_is_flag(char c, t_vals *lst)
{
	if (!lst->flag || lst->flag == c)
	{
		if (c == ' ' || c == '+' || c == '#')
		{
			lst->flag = c;
			return (1);
		}
	}
	if (c == '0')
	{
		lst->zero = 1;
		return (1);
	}
	if (c == '-')
	{
		lst->minus = 1;
		return (1);
	}
	if (!ft_is_conv(c) && c != '*' && c != '.' && !ft_isdigit(c))
		lst->error = 1;
	return (0);
}

int		ft_pourcent(t_vals *lst, char *str, int i, va_list va)
{
	while (ft_is_flag(str[i], lst))
		i++;
	if (lst->error)
	{
		free(lst->result);
		return (0);
	}
	str[i] == '*' ? (lst->width = va_arg(va, int)) :
		(lst->width = ft_atoi(str + i));
	str[i] == '*' ? i++ : i;
	while ((!ft_is_conv(str[i]) && str[i] != '.') || ft_isdigit(str[i]))
		i++;
	if (str[i] == '.')
		str[i + 1] == '*' ? (lst->preci = va_arg(va, int))
		: (lst->preci = ft_atoi(str + i + 1));
	while (!ft_is_conv(str[i]) && str[i])
		i++;
	if (ft_is_conv(str[i]))
		lst->convert = str[i];
	else
		return (0);
	return (i);
}
