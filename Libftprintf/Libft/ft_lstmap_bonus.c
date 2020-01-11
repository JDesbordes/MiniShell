/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap_bonus.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 16:22:53 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 11:36:30 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list *newlst;

	if (lst == NULL)
		return (NULL);
	if (!(newlst = malloc(sizeof(t_list))))
		return (NULL);
	if (lst->next != NULL)
	{
		if (!(newlst->next = ft_lstmap(lst->next, *f, *del)))
		{
			ft_lstclear(&newlst, *del);
			return (NULL);
		}
	}
	else
		newlst->next = NULL;
	if (lst->content)
		newlst->content = f(lst->content);
	return (newlst);
}
