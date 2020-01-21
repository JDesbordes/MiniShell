/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_create_elem.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 14:33:51 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 17:23:05 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "main.h"

t_list2	*ft_create_elem(void *content)
{
	t_list2 *new;

	if (!(new = malloc(sizeof(t_list2) * 1)))
		return (NULL);
	new->data = content;
	new->next = NULL;
	return (new);
}
