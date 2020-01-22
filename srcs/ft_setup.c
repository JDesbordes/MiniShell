/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_setup.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/11 23:58:49 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 16:31:41 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

	y = 1;
	j = *i + 1;
	temp = NULL;
	while (com[*i + y] && com[*i + y] != '\"')
	{
		if (com[*i + y] == '$')
		{
			temp = ft_strjoinrem(temp, ft_strndup(com + j, y - ((j) - (*i))));
			temp = ft_strjoinrem(temp, ft_dollar(com + *i, &y, file));
			j = *i + y + 1;
		}
		y++;
	}
	temp = ft_strjoinrem(temp, ft_strndup(com + j, y - ((j) - (*i))));
	*i += y;
	return (temp);
}

char		*nocoma(char *com, int *i, t_file *file)
{
	int 	y;
	int		j;
	char	*temp;

	y = 0;
	j = *i;
	temp = NULL;
	while (com[*i + y] && com[*i + y] != '\"' && com[*i + y] != '\'')
	{
		if (com[*i + y] == '$')
		{
			temp = ft_strjoinrem(temp, ft_strndup(com + j, y - ((j) - (*i))));
			temp = ft_strjoinrem(temp, ft_dollar(com + *i, &y, file));
			j = *i + y + 1;
		}
		y++;
	}
	temp = ft_strjoinrem(temp, ft_strndup(com + j, y - ((j) - (*i))));
	*i += y - 1;
	return (temp);
}

void		ft_converter(char **args2, t_file *file, int i)
{
	int		j;
	char	*temp;
	
	temp = NULL;
	while (args2[i])
	{
		j = 0;
		while (args2[i][j])
		{
			if (args2[i][j] == '\'')
				temp = ft_strjoinrem(temp, invertedcoma(args2[i], &j));
			else if (args2[i][j] == '\"')
				temp = ft_strjoinrem(temp, doublecoma(args2[i], &j, file));
			else
				temp = ft_strjoinrem(temp, nocoma(args2[i], &j, file));
			j++;
		}
		free(args2[i]);
		args2[i] = temp;
		temp = NULL;
		i++;
	}
}
