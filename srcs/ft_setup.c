/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_setup.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/11 23:58:49 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 09:32:20 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_env_struct(char **envp, t_file *file)
{
	char	**tmp;
	int 	i;
	int 	j;
	t_env	*tmpfile;

	i = 0;
	tmpfile = file->env;
	while (envp[i])
	{
		j = 0;
		tmp = ft_split((char *)envp[i], "=");
		file->env->name = ft_strdup(tmp[0]);
		file->env->content = ft_strdup(tmp[1]);
		while (tmp[j])
		{
			free(tmp[j]);
			j++;
		}
		free(tmp);
		i++;
		file->env->next = envp[i] ? malloc(sizeof(t_env) * 1) : NULL;
		file->env = file->env->next;
	}
	file->env = tmpfile;
}

int		invertedcoma(char *com, int *i, char **join, char *args)
{
	int y;

	y = 1;
	while (com[*i + y] && com[*i + y] != '\"')
		y++;
	if (!com[*i + y])
	{
		ft_printf("\033[1;31mmulti-line not supported\033[0m\n");
		return (0);
	}
	if (y > 1)
		*join = ft_strndup(com + *i + 1, y - 1);
	*i += y;
	return (1);
}

int		doublecoma(char *com, int *i, char **join, char *args)
{
	int y;

	y = 1;
	while (com[*i + y] && com[*i + y] != '\'')
		y++;
	if (!com[*i + y])
	{
		ft_printf("\033[1;31mmulti-line not supported\033[0m\n");
		return (0);
	}
	if (y > 1)
		*join = ft_strndup(com + *i + 1, y - 1);
	*i += y;
	return (1);
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

void				ft_converter(char **args2, t_file *file, int i)
{
	
	while (args2[i])
	{
		
		i++;
	}
}
