/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_setup.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/11 23:58:49 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 23:20:46 by jdesbord    ###    #+. /#+    ###.fr     */
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
	return(0);
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
			temp = ft_strjoinrem(temp, ft_dollar(com + *i, &y, file));
			j = *i + y + 1;
		}
		if (com[*i + y] == '\\')
		{
			if (com[*i + y + 1] == '\\' || com[*i + y + 1] == '\"' || com[*i + y + 1] == '$')
			{
				save = ft_strndup(com + j, y - ((j) - (*i)));
				temp = ft_strjoinrem(temp, save);
				free(save);
				y++;
				j = *i + y;
				if (!com[*i + y])
					break ;
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
	int 	y;
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
			temp = ft_strjoinrem(temp, ft_dollar(com + *i, &y, file));
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
	while (args2[i])
	{
		j = 0;
		while (args2[i][j])
		{
			if (args2[i][j] == '\'')
			{
				save = invertedcoma(args2[i], &j);
				temp = ft_strjoinrem(temp, save);
				free(save);
			}
			else if (args2[i][j] == '\"')
			{
				save = doublecoma(args2[i], &j, file);
				temp = ft_strjoinrem(temp, save);
				free(save);
			}
			else
			{
				save = nocoma(args2[i], &j, file);
				temp = ft_strjoinrem(temp, save);
				free(save);
			}
			j++;
		}
		free(args2[i]);
		args2[i] = temp;
		temp = NULL;
		i++;
		if(F->stop == 'o' || F->stop == 's')
			break ;
	}
}

void		ft_converter2(char **args2, t_file *file, int i)
{
	char	*temp;
	char	*save;
	
	temp = NULL;
	while (args2[0][i])
	{
		if (args2[0][i] == '\'')
		{
			save = invertedcoma(args2[0], &i);
			temp = ft_strjoinrem(temp, save);
			free(save);
		}
		else if (args2[0][i] == '\"')
		{
			save = doublecoma(args2[0], &i, file);
			temp = ft_strjoinrem(temp, save);
			free(save);
		}
		else
		{
			save = nocoma(args2[0], &i, file);
			temp = ft_strjoinrem(temp, save);
			free(save);
		}
		i++;
	}
	free(args2[0]);
	args2[0] = temp;
	temp = NULL;
}
