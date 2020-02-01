/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_input.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/12 20:09:41 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 03:50:17 by jdesbord    ###    #+. /#+    ###.fr     */
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
	ft_printf("Quit: 3\n");
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
		signal(SIGQUIT, ft_silence);
	}
	else if (option == 1)
	{
		signal(SIGINT, ft_nl);
		signal(SIGQUIT, ft_ctrlbslash);
	}
	else
	{
		signal(SIGINT, ft_silence);
		signal(SIGQUIT, ft_silence);
	}
	return (1);
}