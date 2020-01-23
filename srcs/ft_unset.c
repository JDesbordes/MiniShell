/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_unset.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/22 15:40:18 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 18:38:06 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int     ft_exist_envp(char *env, char **args)
{
    int     i;
	char 	*tmp;

    i = 1;
    while (args[i])
    {
		tmp = ft_strjoin(args[i], "=");
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

int     ft_unset(char **args, t_file *file, int i)
{
    char   **new;
	int		j;

	if (!args[1])
		ft_printf("unset: not enough arguments\n");
    else
    {
		while(F->envp[i])
		{
			if (ft_exist_envp(F->envp[i], args))
			{
				j = i;
				while (F->envp[j] && F->envp[j + 1])
				{
					ft_strcpy(F->envp[j], F->envp[j + 1]);
					j++;
				}
				F->envp[j] = NULL;
			}
			i++;
		}
    }
    return (1);
}

