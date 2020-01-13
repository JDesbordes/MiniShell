/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_input.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/12 20:09:41 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 04:53:08 by jdesbord    ###    #+. /#+    ###.fr     */
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
	ft_printf("CTRL-\\\n");
}

int		ft_input()
{
	char c;
	
	signal(SIGINT, ft_ctrlC);
	signal(SIGQUIT, ft_ctrlbslash);
	return (1);
}