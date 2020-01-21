/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_input.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/12 20:09:41 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 06:14:15 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_ctrlC(int i)
{
	ft_printf("\n\033[01;33m%s->\033[0m", findpath());
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