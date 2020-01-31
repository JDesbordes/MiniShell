/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_input.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/12 20:09:41 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/31 16:19:41 by jdesbord    ###    #+. /#+    ###.fr     */
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

void	ft_silence(int i)
{
	signal(i, SIG_IGN);
}

void	ft_nl(int i)
{
	ft_printf("\n");
	signal(i, SIG_IGN);
}

int		ft_input(t_file *file, int option)
{
	if (option == 0)
	{
		signal(SIGINT, ft_ctrlC);
		signal(SIGQUIT, ft_ctrlbslash);
	}
	else if (option == 1)
	{
		signal(SIGINT, ft_nl);
		signal(SIGQUIT, ft_silence);
	}
	else
	{
		signal(SIGINT, ft_silence);
		signal(SIGQUIT, ft_silence);
	}
	return (1);
}