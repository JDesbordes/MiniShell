/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_input.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <nepage-l@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/12 20:09:41 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/18 16:08:41 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_ctrlC(int i)
{
	signal(i, SIG_IGN);
}

void	ft_ctrlbslash(int i)
{
	signal(i, SIG_IGN);
}

int		ft_input(t_file *file)
{
	char c;
	
	signal(SIGINT, ft_ctrlC);
	signal(SIGQUIT, ft_ctrlbslash);

	return (1);
}