/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_input.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <nepage-l@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/12 20:09:41 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 20:14:58 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_ctrlC(int i)
{
	char *tmp;

	tmp = findpath();
	ft_printf("\n\033[01;33m%s->\033[0m", tmp);
	free(tmp);
}

void	ft_ctrlbslash(int i)
{
	signal(i, SIG_IGN);
}

int		ft_input(t_file *file)
{
	signal(SIGINT, ft_ctrlC);
	signal(SIGQUIT, ft_ctrlbslash);
	return (1);
}