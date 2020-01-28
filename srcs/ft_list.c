/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_list.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 16:56:03 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/25 15:50:53 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	*ft_lstenvnew(char *name, char *content)
{
	t_env *new;

	if (!(new = malloc(sizeof(t_env) * 1)))
		return (NULL);
	new->name = name;
	new->content = content;
	new->next = NULL;
	return (new);
}

t_env	*ft_lstenvlast(t_env *lst)
{
	if (lst == NULL)
		return (NULL);
	return (lst->next ? ft_lstenvlast(lst->next) : lst);
}

void			ft_lstenvadd_back(t_env **alst, t_env *new)
{
	if (!(*alst) || (*alst)->name == NULL)
	{
		*alst = new;
		return ;
	}
	ft_lstenvlast(*alst)->next = new;
}

void	ft_lstenvdelone(t_env *lst, void (*del)(void*))
{
	if (lst == NULL)
		return ;
	if (lst->content)
		del(lst->content);
	if (lst->name)
		del(lst->name);
	free(lst);
}

void			ft_lstenvclear(t_env **lst, void (*del)(void*))
{
	if ((*lst) != NULL)
		ft_lstenvclear(&((*lst)->next), *del);
	ft_lstenvdelone(*lst, del);
	*lst = NULL;
}
