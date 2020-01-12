/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_setup.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/11 23:58:49 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/12 03:20:47 by jdesbord    ###    #+. /#+    ###.fr     */
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
	{
		args = ft_strndup(com + *i + 1, y - 1);
		*join = ft_strjoinrem(*join, args);
	}
	*i += y;
	y == 1 ? 0 : free(args);
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
	{
		args = ft_strndup(com + *i + 1, y - 1);
		*join = ft_strjoinrem(*join, args);
	}
	*i += y;
	y == 1 ? 0 : free(args);
	return (1);
}

int		ft_setup(char *com, char **join, char *args, int *i)
{
    while (com[*i] && (com[*i] < 9 || com[*i] > 13) && com[*i] != ' ' && com[*i] != ';')
	{
		if (com[*i] == '\"')
		{
			if (!invertedcoma(com, i, join, args))
				return (1);
		}
		else if (com[*i] == '\'')
		{
			if (!doublecoma(com, i, join, args))
				return (1);
		}
		else
		{
			args = ft_strndup(com + *i, 1);
			*join = ft_strjoinrem(*join, args);
			free(args);
		}
		*i += 1;
	}
    return (0);
}