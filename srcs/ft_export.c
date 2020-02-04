/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_export.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 15:38:46 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 03:23:46 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_export_print(t_file *file, int i)
{
	char	**print;
	char	*temp;
	int		j;

	i = 0;
	print = ft_tabdup(file->envp);
	ft_sort_string_tab(print);
	while (print[i])
	{
		j = 0;
		while (print[i][j] != '=')
			j++;
		temp = ft_strndup(print[i], j);
		ft_printf("declare -x %s=\"%s\"\n", temp, ft_strchr(print[i], '=') + 1);
		free(temp);
		i++;
	}
	i = -1;
	while (print[++i])
		free(print[i]);
	free(print);
	return (1);
}

int		ft_exist_env(char **env, char *args)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] != '=')
			j++;
		tmp = ft_strndup(env[i], j + 1);
		if (!ft_strncmp(args, tmp, ft_strlen(tmp)))
		{
			free(tmp);
			ft_strcpy(env[i] + j, ft_strchr(args, '='));
			return (1);
		}
		i++;
		free(tmp);
	}
	return (0);
}

void	ft_export_envp(char **args, t_file *file, t_env *tmp, int i)
{
	int		j;

	tmp = F->env;
	while (tmp && tmp->name && j != -1)
	{
		if (!ft_strcmp(tmp->name, args[i]))
		{
			j = 0;
			F->envp = ft_tabjoinrem(F->envp, tmp->name);
			while (F->envp[j + 1])
				j++;
			F->envp[j] = ft_strjoinrem(F->envp[j], "=");
			F->envp[j] = ft_strjoinrem(F->envp[j], tmp->content);
			j = -1;
		}
		tmp = tmp->next;
	}
}

int		ft_export(char **args, t_file *file, int i)
{
	t_env	*tmp;

	tmp = NULL;
	if (!args[i + 1])
		return (ft_export_print(file, i));
	while (args[i])
	{
		if (!args[i][0] || ft_isdigit(args[i][0]))
		{
			F->status = 1;
			ft_printf("export: `%s': not a valid identifier\n", args[i]);
			return (1);
		}
		if (!ft_isvar(args[i]))
			ft_export_envp(args, file, tmp, i);
		else if (!ft_exist_env(F->envp, args[i]))
			F->envp = ft_tabjoinrem(F->envp, args[i]);
		i++;
	}
	return (1);
}

char	*ft_dollar(char *str, int *i, t_file *file)
{
	int		j;
	char	*temp;
	char	*result;

	*i += 1;
	j = *i;
	while (str[*i] && str[*i] != ' ' && str[*i] != '\"' &&
		str[*i] != '\'' && str[*i] != '$')
		*i += 1;
	temp = ft_strndup(str + j, *i - j);
	*i -= 1;
	if (!ft_strcmp(temp, "?"))
	{
		free(temp);
		return (ft_interrog(file));
	}
	result = ft_convert_dollar(temp, file);
	free(temp);
	return (result);
}
