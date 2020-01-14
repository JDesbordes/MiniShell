/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_setup.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/11 23:58:49 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 02:07:22 by jdesbord    ###    #+. /#+    ###.fr     */
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
