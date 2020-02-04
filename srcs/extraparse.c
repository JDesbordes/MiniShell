/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   extraparse.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/25 13:44:06 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/03 21:23:42 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_countcoma(char *args, int *i, int *y, char c)
{
	(*i)++;
	while (args[*i] && args[*i] != c)
	{
		if (c == '\"' && args[*i] == '\\')
		{
			if (args[*i + 1] == '\\' || args[*i + 1] == '\"' ||
				args[*i + 1] == '$')
			{
				(*i)++;
				if (!args[(*i)])
					break ;
			}
		}
		(*i)++;
	}
	if (!args[(*i)])
		return (0);
	(*i)++;
	if (!args[(*i)] || ft_isseparator(args, i, 1) || args[*i] == ' ' ||
		(args[*i] >= 9 && args[*i] <= 13))
		(*y)++;
	(*i)--;
	return (1);
}

void	ft_countword(char *args, int *i, int *y)
{
	int j;

	j = 0;
	(*y)++;
	while (args[(*i)] && !ft_isseparator(args, i, 1) && (args[(*i)] != ' '
		&& args[(*i)] != '\'' && args[(*i)] != '\"' && (args[(*i)] < 9 ||
		args[(*i)] > 13)) && !(j = 0))
	{
		if (args[(*i)] == '\\')
			(*i)++;
		if (!args[(*i)])
			break ;
		(*i)++;
	}
	(*i)--;
}

int		singlecoma2(char *args, char **args2, int *i, int *k)
{
	(*i)++;
	while (args[*i] && args[*i] != '\'')
		(*i)++;
	(*i)++;
	if (!args[*i] || ft_isseparator(args, i, 1) || args[*i] == ' ' ||
		(args[*i] >= 9 && args[*i] <= 13))
	{
		*args2 = ft_strndup(args + *k, *i - *k);
		*k = *i;
		(*i)--;
		return (1);
	}
	(*i)--;
	return (0);
}

int		nocoma2(char *args, char **args2, int *i, int *k)
{
	while (args[*i] && !ft_isseparator(args, i, 1) && (args[*i] != ' ' &&
		args[*i] != '\'' && args[*i] != '\"' && (args[*i] < 9 ||
		args[*i] > 13)))
	{
		if (args[*i] == '\\')
			(*i)++;
		if (!args[*i])
			break ;
		(*i)++;
	}
	if (!args[*i] || ft_isseparator(args, i, 1) || args[*i] == ' ' ||
		(args[*i] >= 9 && args[*i] <= 13))
	{
		*args2 = ft_strndup(args + *k, *i - *k);
		*k = *i;
		(*i)--;
		return (1);
	}
	(*i)--;
	return (0);
}

int		doublecoma2(char *args, char **args2, int *i, int *k)
{
	(*i)++;
	while (args[*i] && args[*i] != '\"')
	{
		if (args[*i] == '\\')
		{
			if (args[*i + 1] == '\\' || args[*i + 1] == '\"' ||
				args[*i + 1] == '$')
				(*i)++;
		}
		(*i)++;
	}
	(*i)++;
	if (!args[*i] || ft_isseparator(args, i, 1) || args[*i] == ' ' ||
		(args[*i] >= 9 && args[*i] <= 13))
	{
		*args2 = ft_strndup(args + *k, *i - *k);
		*k = *i;
		(*i)--;
		return (1);
	}
	(*i)--;
	return (0);
}
