/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_unset.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/22 15:40:18 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 02:17:40 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_interrog(t_file *file)
{
	if (F->status != 127)
		return (ft_itoa(F->status));
	return (ft_itoa(127));
}

int		ft_exist_envp(char *env, char **args, int j)
{
	int		i;
	char	*tmp;

	i = 1;
	while (args[i])
	{
		j ? tmp = ft_strjoin(args[i], "=") :
		(tmp = ft_strdup(args[i]));
		if (!ft_strncmp(env, tmp, ft_strlen(tmp)))
		{
			free(tmp);
			return (1);
		}
		i++;
		free(tmp);
	}
	return (0);
}

void	ft_unset_t_env(char **args, t_file *file)
{
	t_env *tmp;
	t_env *suiv;

	tmp = F->env;
	while (F->env && ft_exist_envp(F->env->name, args, 0))
	{
		tmp = F->env;
		F->env = F->env->next;
		ft_lstenvdelone(tmp, free);
	}
	suiv = F->env;
	while (suiv && suiv->next)
	{
		if (ft_exist_envp(suiv->name, args, 0))
		{
			tmp = suiv->next;
			suiv->next = tmp->next;
			ft_lstenvdelone(tmp, free);
		}
		if (suiv->next)
			suiv = suiv->next;
	}
}

int		ft_unset(char **args, t_file *file, int i)
{
	char	**new;
	int		j[2];
	int		count;

	count = 0;
	j[0] = 0;
	j[1] = 0;
	while (F->envp[j[1]])
	{
		if (!ft_exist_envp(F->envp[j[1]], args + i, 1))
			j[0]++;
		j[1]++;
	}
	new = (char **)ft_calloc(sizeof(char *), j[0] + 1);
	j[0] = 0;
	while (j[0] < j[1])
	{
		if (!ft_exist_envp(F->envp[j[0]], args + i, 1))
			new[count++] = ft_strdup(F->envp[j[0]]);
		j[0]++;
	}
	ft_free_tab(F->envp);
	F->envp = new;
	ft_unset_t_env(args + i, file);
	return (1);
}
