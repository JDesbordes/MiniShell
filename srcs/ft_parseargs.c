/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parseargs.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/13 07:31:13 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 01:20:48 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

char	**ft_nbargs(char **join, char *args)
{
	int y;
	char *temp;
	int i;

	i = 0;
	y = -1;
	while (args[i])
	{
		if (args[i] == '\"')
		{
			if (!invertedcoma(args, &i, join, temp))
				return (NULL);
			y == -1 ? y += 1 : 0;
		}
		else if (args[i] == '\'')
		{
			if (!doublecoma(args, &i, join, temp))
				return (NULL);
			y == -1 ? y += 1 : 0;
		}
		else
		{
			nocoma(args, &i, join, &y);
			i -= 1;
		}
		if (args[i + 1] != ';')
			free(*join);
		else
		{
			y++;
			i++;
		}
		i += 1;
		*join = NULL;
	}
	return (ft_calloc(sizeof(char *), y + 2));
}

char		**ft_parse(char *args, char *temp, char **join)
{
	char	**args2;
	int		y;
	int		i;

	y = -1;
	i = 0;
	args2 = ft_nbargs(join, args);
	*join = NULL;
	while(args[i])
	{
		if (args[i] == '\"')
		{
			if (!invertedcoma(args, &i, join, temp))
				return (NULL);
			y == -1 ? y += 1 : 0;
			args2[y] = ft_strjoinrem(args2[y], *join);
		}
		else if (args[i] == '\'')
		{
			if (!doublecoma(args, &i, join, temp))
				return (NULL);
			y == -1 ? y += 1 : 0;
			args2[y] = ft_strjoinrem(args2[y], *join);
		}
		else
		{
			if (nocoma(args, &i, join, &y))
				args2[y] = ft_strjoinrem(args2[y], *join);
			i -= 1;
		}
		if (args[i + 1] != ';')
			free(*join);
		else
		{
			args2[y] == NULL ? (args2[y] = ft_strdup(";")) : (args2[++y] = ft_strdup(";"));
			i++;
		}
		i += 1;
		*join = NULL;
	}
	args2[y + 1] = NULL;
	return (args2);
}

char	**ft_getargs(char *args)
{
	char *temp;
	char *join;
	char **args2;

	join = NULL;
	temp = ft_strtrimr(args, " \t\b\r\v\f");
	free(args);
	args = temp;
	args2 = ft_parse(args, temp, &join);
	free(args);
	return(args2);
}