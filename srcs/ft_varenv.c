/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_varenv.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 04:30:11 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 02:17:13 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int					ft_isvar(char *str)
{
	int i;

	i = 0;
	if (ft_isdigit(str[i]))
		return (0);
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	if (i != 0 && str[i] == '=')
		return (i);
	return (0);
}

int					ft_temp(t_env *temp, char *name, char *content)
{
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

int					ft_isexist(t_file *file, char *name, char *content)
{
	t_env	*temp;
	int		i;
	char	*tmp;

	temp = F->env;
	tmp = ft_strjoin(name, "=");
	i = 0;
	while (F->envp[i])
	{
		if (!ft_strncmp(F->envp[i], tmp, ft_strlen(tmp)))
		{
			ft_strcpy(F->envp[i] + ft_strlen(tmp), content);
			free(tmp);
			return (1);
		}
		i++;
	}
	free(tmp);
	return (ft_temp(temp, name, content));
}

char				*ft_contentenv(char *com, t_file *file)
{
	int		p;
	char	*tmp;

	p = 0;
	tmp = ft_strdup(com);
	ft_converter2(&tmp, file, -1);
	return (tmp);
}

int					ft_varenv(char **args, t_file *file, int *i)
{
	int		j;
	int		k;
	t_env	*temp;
	char	*name;
	char	*content;

	while (args[*i] && (j = ft_isvar(args[*i])))
		*i += 1;
	if (!(k = 0) && !args[*i])
	{
		while (k < *i && (j = ft_isvar(args[k])))
		{
			name = ft_strndup(args[k], j);
			content = ft_contentenv(args[k] + j + 1, file);
			if (!ft_isexist(file, name, content))
			{
				temp = ft_lstenvnew(name, content);
				ft_lstenvadd_back(&F->env, temp);
			}
			else
				free(name);
			k = k + 1;
		}
	}
	return (1);
}
