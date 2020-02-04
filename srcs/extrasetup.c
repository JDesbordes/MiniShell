/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   extrasetup.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/04 02:36:22 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 03:25:37 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			ft_backslash(char c, char **str)
{
	char *result;

	result = ft_calloc(sizeof(char), 2);
	result[0] = c;
	*str = ft_strjoinrem(*str, result);
	free(result);
	return (0);
}

char		*invertedcoma(char *com, int *i)
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

int			coma_dollar(int lo[3], char *com, char **temp, t_file *file)
{
	char *save;

	if (com[lo[2] + lo[0]] == '$')
	{
		save = ft_strndup(com + lo[1], lo[0] - ((lo[1]) - (lo[2])));
		*temp = ft_strjoinrem(*temp, save);
		free(save);
		save = ft_dollar(com + lo[2], &lo[0], file);
		*temp = ft_strjoinrem(*temp, save);
		free(save);
		lo[1] = lo[2] + lo[0] + 1;
	}
	return (lo[1]);
}

int			dblcoma_bckslash(int lo[3], char *com, char **temp)
{
	char *save;

	if (com[lo[2] + lo[0]] == '\\')
	{
		if (com[lo[2] + lo[0] + 1] == '\\' || com[lo[2] + lo[0] + 1] == '\"'
		|| com[lo[2] + lo[0] + 1] == '$')
		{
			save = ft_strndup(com + lo[1], lo[0] - ((lo[1]) - (lo[2])));
			*temp = ft_strjoinrem(*temp, save);
			free(save);
			lo[0]++;
			if (!com[lo[2] + lo[0]])
				return (0);
			lo[1] = lo[2] + lo[0];
		}
	}
	return (lo[1]);
}
