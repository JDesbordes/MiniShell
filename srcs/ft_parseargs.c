/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parseargs.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/13 07:31:13 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 09:15:28 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		nocoma(char *args, int *i, char **join, char *temp)
{
	int y;
	int j;

	y = 0;
	while (args[*i] && (args[*i] == ' ' || (args[*i] >= 9 && args[*i] <= 13)))
		*i += 1;
	j = *i;
	while (args[*i] && args[*i] != ' ' && (args[*i] < 9 || args[*i] > 13)
		&& args[*i] != '\'' && args[*i] != '\"' && args[*i] != ';')
	{
		y++;
		*i += 1;
	}
	if (y >= 1)
	{
		temp = ft_strndup(args + j, y);
		*join = ft_strjoinrem(*join, temp);
		free(temp);
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
	y = 0;
	while (args[i] && args[i] != ';')
	{
		if (args[i] == '\"')
		{
			if (!invertedcoma(args, &i, join, temp))
				return (NULL);
			y++;
		}
		else if (args[i] == '\'')
		{
			if (!doublecoma(args, &i, join, temp))
				return (NULL);
			y++;
		}
		else
		{
			if (nocoma(args, &i, join, temp))
				y++;
			i -= 1;
		}
		i += 1;
	}
	//free (*join);
	return (ft_calloc(sizeof(char *), y + 1));
}

char		**ft_parse(char *args, char *temp, char **join)
{
	char	**args2;
	int		y;
	int		i;
	char	iss;

	y = -1;
	i = 0;
	iss = 't';
	args2 = ft_nbargs(join, args);
	while(args[i] && args[i] != ';')
	{
		if (args[i] == '\"')
		{
			if (!invertedcoma(args, &i, join, temp))
				return (NULL);
			if (iss == 't')
			{
				y++;
				ft_printf("HERE1 : %s\n", *join);
				iss = 'f';
			}
			args2[y] = ft_strjoinrem(args2[y], *join);
		}
		else if (args[i] == '\'')
		{
			if (!doublecoma(args, &i, join, temp))
				return (NULL);
			if (iss == 't')
			{
				y++;
				ft_printf("HERE2 : %s\n", *join);
				iss = 'f';
			}
			args2[y] = ft_strjoinrem(args2[y], *join);
		}
		else
		{
			if (nocoma(args, &i, join, temp))
			{
				if (iss == 't')
				{
					y++;
					ft_printf("HERE3 : %s\n", *join);
					iss = 'f';
				}
				args2[y] = ft_strjoinrem(args2[y], *join);
			}
			else
				iss = 't';
			i -= 1;
		}
		*join = NULL;
		i += 1;
	}
	args2[y + 1] = NULL;
	return (args2);
}

char	**ft_getargs(char *args)
{
	char *temp;
	char *join;
	int i;
	char **args2;

	temp = ft_strtrimr(args, " \t\b\r\v\f");
	free(args);
	args = temp;
	join = ft_strdup("");
	args2 = ft_parse(args, temp, &join);
	i = 0;
	return(args2);
}