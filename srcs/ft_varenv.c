/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_varenv.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 04:30:11 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/25 15:47:17 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_isvar(char *str)
{
	int i;

	i = 0;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	if (i != 0 && str[i] == '=')
		return (i);
	return (0);
}

int					ft_isexist(t_file *file, char *name, char *content)
{
	t_env	*temp;

	temp = F->env;
	while (temp)
	{
		if (temp->name && !ft_strcmp(temp->name, name))
		{
			free(temp->content);
			temp->content = content;
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}

int					ft_varenv(char **args, t_file *file, int *i)
{
	int		j;
	int		k;
	t_env	*temp;
	char	*name;
	char	*content;

    while (args[*i] && (j = ft_isvar(args[*i])))
	{
		*i += 1;
	}
	k =	0;
	if (!args[*i])
	{
		while (k < *i && (j = ft_isvar(args[k])))
		{
			name = ft_strndup(args[k], j);
			content = ft_strdup(args[k] + j + 1);
			if (!ft_isexist(file, name, content))
			{
				temp = ft_lstenvnew(name , content);
				ft_lstenvadd_back(&F->env, temp);
			}
			k++;
		}
	}
	temp = F->env;
    return (1);
}
