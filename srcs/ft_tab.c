/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tab.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/01 20:06:20 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 20:06:53 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_tabdup(char **tab)
{
	int		i;
	char	**dup;

	i = 0;
	while (tab[i])
		i++;
	if (!(dup = ft_calloc(sizeof(char *), i + 1)))
		return (NULL);
	i = 0;
	while (tab[i])
	{
		dup[i] = ft_strdup(tab[i]);
		i++;
	}
	return (dup);
}

char	**ft_tabjoinrem(char **tab, char *str)
{
	int		i;
	int		j;
	char	**new;

	i = 0;
	while (tab[i])
		i++;
	new = (char **)ft_calloc(sizeof(char *), i + 2);
	i = -1;
	while (tab[++i])
		new[i] = ft_strdup(tab[i]);
	new[i] = ft_strdup(str);
	new[i + 1] = NULL;
	ft_free_tab(tab);
	return (new);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	char	*temp;

	i = 0;
	while (tab[i + 1] != 0)
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}
