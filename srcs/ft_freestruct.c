/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_freestruct.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/31 21:47:41 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 04:44:00 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_freestruct(t_file *file)
{
	 int i;

	 ft_lstenvclear(&F->direct, free);
	 ft_lstenvclear(&F->env, free);
	free(F->pathend);
	i = 0;
	while(F->paths && F->paths[i])
	{
		free(F->paths[i]);
		i++;
	}
	F->paths ? free(F->paths) : 0;
	i = 0;
	while(F->envp && F->envp[i])
	{
		free(F->envp[i]);
		i++;
	}
	F->envp ? free(F->envp) : 0;
	free(file);
}

void 	ft_free_tab(char **tab)
{
	int i;
	
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}