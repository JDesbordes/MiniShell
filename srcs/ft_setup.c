/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_setup.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/11 23:58:49 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 08:54:34 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		invertedcoma(char *com, int *i, char **join, char *args)
{
	int y;

	y = 1;
	while (com[*i + y] && com[*i + y] != '\"')
		y++;
	if (!com[*i + y])
	{
		ft_printf("\033[1;31mmulti-line not supported\033[0m\n");
		return (0);
	}
	if (y > 1)
		*join = ft_strndup(com + *i + 1, y - 1);
	*i += y;
	return (1);
}

int		doublecoma(char *com, int *i, char **join, char *args)
{
	int y;

	y = 1;
	while (com[*i + y] && com[*i + y] != '\'')
		y++;
	if (!com[*i + y])
	{
		ft_printf("\033[1;31mmulti-line not supported\033[0m\n");
		return (0);
	}
	if (y > 1)
		*join = ft_strndup(com + *i + 1, y - 1);
	*i += y;
	return (1);
}

char	**semicolon(char **args2, int *i)
{
	int j;
	int y;
	char **cutargs;

	if (!args2[*i])
		return (NULL);
	j = *i;
	while (args2[*i] && ft_strncmp(args2[*i], ";", 2))
		*i += 1;
	cutargs = ft_calloc(sizeof(char *), (*i - j + 1));
	y = 0;
	while (y < *i - j)
	{
		cutargs[y] = args2[j + y];
		y++;
	}
	if (args2[*i] && args2[*i][0] == ';')
		*i += 1;
	return(cutargs);
}

int		nocoma(char *args, int *i, char **join, int *y)
{
	int k;
	int j;

	k = 0;
	if (args[*i] && (args[*i] == ' ' || (args[*i] >= 9 && args[*i] <= 13)))
		*y += 1;
	*y == -1 ? *y += 1 : 0;
	while (args[*i] && (args[*i] == ' ' || (args[*i] >= 9 && args[*i] <= 13)))
		*i += 1;
	j = *i;
	while (args[*i] && args[*i] != ' ' && (args[*i] < 9 || args[*i] > 13)
		&& args[*i] != '\'' && args[*i] != '\"' && args[*i] != ';')
	{
		k++;
		*i += 1;
	}
	if (k >= 1)
	{
		*join = ft_strndup(args + j, k);
		return (1);
	}
	return (0);
}
