/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_setup.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/11 23:58:49 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 03:26:09 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		*doublecoma(char *com, int *i, t_file *file)
{
	int		lo[4];
	char	*temp;
	char	*save;

	lo[0] = 1;
	lo[1] = *i + 1;
	lo[2] = *i;
	temp = NULL;
	while (com[lo[2] + lo[0]] && com[lo[2] + lo[0]] != '\"')
	{
		lo[1] = coma_dollar(lo, com, &temp, file);
		if (!(lo[3] = dblcoma_bckslash(lo, com, &temp))
		&& (lo[1] = lo[3]))
			break ;
		lo[0]++;
	}
	save = ft_strndup(com + lo[1], lo[0] - ((lo[1]) - (lo[2])));
	temp = ft_strjoinrem(temp, save);
	free(save);
	*i += lo[0];
	return (temp);
}

int			nocoma_bckslash(int lo[3], char *com, char **temp)
{
	char *save;

	if (com[lo[2] + lo[0]] == '\\')
	{
		save = ft_strndup(com + lo[1], lo[0] - ((lo[1]) - (lo[2])));
		ft_backslash(com[lo[2] + lo[0] + 1], &save);
		*temp = ft_strjoinrem(*temp, save);
		free(save);
		lo[0]++;
		if (!com[lo[2] + lo[0]])
			return (0);
		lo[1] = lo[2] + lo[0] + 1;
	}
	return (lo[1]);
}

char		*nocoma(char *com, int *i, t_file *file)
{
	int		lo[4];
	char	*temp;
	char	*save;

	lo[0] = 0;
	lo[1] = *i;
	lo[2] = *i;
	temp = NULL;
	while (com[lo[2] + lo[0]] && com[lo[2] + lo[0]] != '\"' &&
	com[lo[2] + lo[0]] != '\'')
	{
		lo[1] = coma_dollar(lo, com, &temp, file);
		if (!(lo[3] = nocoma_bckslash(lo, com, &temp))
		&& (lo[1] = lo[3]))
			break ;
		lo[0]++;
	}
	save = ft_strndup(com + lo[1], lo[0] - ((lo[1]) - (lo[2])));
	temp = ft_strjoinrem(temp, save);
	free(save);
	*i += lo[0] - 1;
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
