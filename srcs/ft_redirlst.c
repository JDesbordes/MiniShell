/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_redirlst.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/25 13:30:03 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/27 19:18:43 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_getfile(char *args, int *i, t_file *file)
{
	int j;
	int y;
	char *result;
	
	*i += 1;
	j = *i;
	y = 0;
	while (y < 1 && args[*i])
	{
		if (args[*i] == '\'')
		{
			(*i)++;
			while (args[*i] && args[*i] != '\'')
				(*i)++;
			if (!args[*i])
				return (NULL);
			if (!args[*i + 1] || args[*i + 1] == ' ' || (args[*i + 1] >= 9 && args[*i + 1] <= 13) || ft_isseparator(args + 1, i))
				y++;
		}
		else if (args[*i] == '\"')
		{
			(*i)++;
			while (args[*i] && args[*i] != '\"')
				(*i)++;
			if (!args[*i])
				return (NULL);
			if (!args[*i + 1] || args[*i + 1] == ' ' || (args[*i + 1] >= 9 && args[*i + 1] <= 13) || ft_isseparator(args + 1, i))
				y++;
		}
		else if (args[*i] != ' ' && (args[*i] < 9 || args[*i] > 13))
		{
			while (args[*i] && !ft_isseparator(args, i) && (args[*i] != ' ' &&
			args[*i] != '\'' && args[*i] != '\"' &&
			(args[*i] < 9 || args[*i] > 13)))
				(*i)++;
			if (!args[*i] || args[*i] == ' ' || (args[*i] >= 9 && args[*i] <= 13) || ft_isseparator(args, i))
				y++;
			if (!args[*i] || ft_isseparator(args, i))
				break ;
		}
		(*i)++;
	}
	result = ft_strtrimr(ft_strndup(args + j, *i - j), " \t\b\r\v\f");
	ft_converter(&result, file, 0);
	return(result);
}

int		ft_redirlst(char c, t_file *file, char *args, int *i)
{
	t_env	*temp;
	char	*name;
	char	*filename;
	if (F->stop != 's')
		F->stop = 'o';
	if(!(filename = ft_getfile(args, i, file)))
		return (0);
	if (F->stop != 's')
	{
		name = ft_calloc(sizeof(char), 2);
		name[0] = c;
		name[1] = 0;
		temp = ft_lstenvnew(name , filename);
		ft_lstenvadd_back(&F->direct, temp);
	}
	*i -= 1;
	return (1);
}
