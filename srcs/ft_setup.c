/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_setup.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/11 23:58:49 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/03 20:27:44 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_backslash(char c, char **str)
{
	char *result;

	result = ft_calloc(sizeof(char), 2);
	result[0] = c;
	*str = ft_strjoinrem(*str, result);
	free(result);
	return (0);
}

char	*invertedcoma(char *com, int *i)
{
	int y;
	int j;

	y = 1;
	j = *i;
	while (com[*i + y] && com[*i + y] != '\'')
		y++;
	if (y > 1)
	{
		*i += y;
		return (ft_strndup(com + j + 1, y - 1));
	}
	*i += y;
	return (ft_strdup(""));
}

char		*doublecoma(char *com, int *i, t_file *file)
{
	int		y;
	int		j;
	char	*temp;
	char	*save;

	y = 1;
	j = *i + 1;
	temp = NULL;
	while (com[*i + y] && com[*i + y] != '\"')
	{
		if (com[*i + y] == '$')
		{
			save = ft_strndup(com + j, y - ((j) - (*i)));
			temp = ft_strjoinrem(temp, save);
			free(save);
			save = ft_dollar(com + *i, &y, file);
			temp = ft_strjoinrem(temp, save);
			free(save);
			j = *i + y + 1;
		}
		if (com[*i + y] == '\\')
		{
			if (com[*i + y + 1] == '\\' || com[*i + y + 1] == '\"'
			|| com[*i + y + 1] == '$')
			{
				save = ft_strndup(com + j, y - ((j) - (*i)));
				temp = ft_strjoinrem(temp, save);
				free(save);
				y++;
				if (!com[*i + y])
					break ;
				j = *i + y;
			}
		}
		y++;
	}
	save = ft_strndup(com + j, y - ((j) - (*i)));
	temp = ft_strjoinrem(temp, save);
	free(save);
	*i += y;
	return (temp);
}

char		*nocoma(char *com, int *i, t_file *file)
{
	int		y;
	int		j;
	char	*temp;
	char	*save;

	y = 0;
	j = *i;
	temp = NULL;
	while (com[*i + y] && com[*i + y] != '\"' && com[*i + y] != '\'')
	{
		if (com[*i + y] == '$')
		{
			save = ft_strndup(com + j, y - ((j) - (*i)));
			temp = ft_strjoinrem(temp, save);
			free(save);
			save = ft_dollar(com + *i, &y, file);
			temp = ft_strjoinrem(temp, save);
			free(save);
			j = *i + y + 1;
		}
		if (com[*i + y] == '\\')
		{
			save = ft_strndup(com + j, y - ((j) - (*i)));
			ft_backslash(com[*i + y + 1], &save);
			temp = ft_strjoinrem(temp, save);
			free(save);
			y++;
			if (!com[*i + y])
				break ;
			j = *i + y + 1;
		}
		y++;
	}
	save = ft_strndup(com + j, y - ((j) - (*i)));
	temp = ft_strjoinrem(temp, save);
	free(save);
	*i += y - 1;
	return (temp);
}

void		ft_converter(char **args2, t_file *file, int i)
{
	int		j;
	char	*temp;
	char	*save;

	temp = NULL;
	while (args2[++i])
	{
		j = -1;
		while (args2[i][++j])
		{
			if (args2[i][j] == '\'')
				save = invertedcoma(args2[i], &j);
			else if (args2[i][j] == '\"')
				save = doublecoma(args2[i], &j, file);
			else
				save = nocoma(args2[i], &j, file);
			temp = ft_strjoinrem(temp, save);
			free(save);
		}
		free(args2[i]);
		args2[i] = temp;
		temp = NULL;
		if (F->stop == 'o' || F->stop == 's')
			break ;
	}
}

void		ft_converter2(char **args2, t_file *file, int i)
{
	char	*temp;
	char	*save;

	temp = NULL;
	while ((*args2)[++i])
	{
		if ((*args2)[i] == '\'')
			save = invertedcoma(*args2, &i);
		else if ((*args2)[i] == '\"')
			save = doublecoma(*args2, &i, file);
		else
			save = nocoma(*args2, &i, file);
		temp = ft_strjoinrem(temp, save);
		free(save);
	}
	free(*args2);
	*args2 = temp;
	temp = NULL;
}
