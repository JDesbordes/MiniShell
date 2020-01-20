/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parseargs.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <nepage-l@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/13 07:31:13 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 21:39:21 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		ft_dollar(char **args2, t_file *file)
{
	int		i;
	int		check;
	char	*tmp;
	t_env	*tmpfile;

	i = 0;
	while (args2[i])
	{
		check = 1;
		if (args2[i][0] == '$')
		{
			tmp = ft_substr(args2[i], 1, ft_strlen(args2[i]));
			tmp = ft_strjoinrem(tmp, "="); 
			free(args2[i]);
			tmpfile = file->env;
			while(file->env)
			{
				if (!ft_strncmp(tmp, file->env->str, ft_strlen(tmp) + 1))
				{
					args2[i] = ft_strdup(file->env->content);
					check = 0;
				}
				file->env = file->env->next;
			}
			check ? args2[i] = ft_strdup("") : 0;
			file->env = tmpfile;
		}

		i++;
	}
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

char	**ft_getargs(char *args, t_file *file)
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
	ft_dollar(args2, file);
	return(args2);
}
