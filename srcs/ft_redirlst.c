/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_redirlst.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/25 13:30:03 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/03 21:28:54 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_comafile(char *args, int *i, int *y)
{
	if (args[*i] == '\'')
	{
		(*i)++;
		while (args[*i] && args[*i] != '\'')
			(*i)++;
		if (!args[*i])
			return (-1);
		if (!args[*i + 1] || args[*i + 1] == ' ' || (args[*i + 1] >= 9 &&
			args[*i + 1] <= 13) || ft_isseparator(args + 1, i, 1))
			(*y)++;
		return (1);
	}
	else if (args[*i] == '\"')
	{
		(*i)++;
		while (args[*i] && args[*i] != '\"')
			(*i)++;
		if (!args[*i])
			return (-1);
		if (!args[*i + 1] || args[*i + 1] == ' ' || (args[*i + 1] >= 9 &&
			args[*i + 1] <= 13) || ft_isseparator(args + 1, i, 1))
			(*y)++;
		return (1);
	}
	return (0);
}

int		ft_nocomatose(char *args, int *i, int *y)
{
	if (args[*i] != ' ' && (args[*i] < 9 || args[*i] > 13))
	{
		while (args[*i] && !ft_isseparator(args, i, 0) && (args[*i] != ' ' &&
		args[*i] != '\'' && args[*i] != '\"' &&
		(args[*i] < 9 || args[*i] > 13)))
			(*i)++;
		if (!args[*i] || args[*i] == ' ' ||
			(args[*i] >= 9 && args[*i] <= 13) || ft_isseparator(args, i, 0))
			(*y)++;
		if (!args[*i] || ft_isseparator(args, i, 0))
			return (0);
	}
	return (1);
}

char	*ft_getfile(char *args, int *i, t_file *file)
{
	int		j;
	int		y;
	int		x;
	char	*result;
	char	*temp;

	*i += 1;
	j = *i;
	y = 0;
	while (y < 1 && args[*i])
	{
		if ((x = ft_comafile(args, i, &y)))
		{
			if (x < 0)
				return (NULL);
		}
		else if (!ft_nocomatose(args, i, &y))
			break ;
		(*i)++;
	}
	temp = ft_strndup(args + j, *i - j);
	result = ft_strtrimr(temp, " \t\b\r\v\f");
	free(temp);
	ft_converter2(&result, file, -1);
	return (result);
}

int		ft_redirlst(char c, t_file *file, char *args, int *i)
{
	t_env	*temp;
	char	*name;
	char	*filename;

	if (F->stop != 's')
		F->stop = 'o';
	if (!(filename = ft_getfile(args, i, file)))
		return (0);
	if (F->stop != 's')
	{
		name = ft_calloc(sizeof(char), 2);
		name[0] = c;
		name[1] = 0;
		temp = ft_lstenvnew(name, filename);
		ft_lstenvadd_back(&F->direct, temp);
	}
	else
		free(filename);
	*i -= 1;
	return (1);
}
