/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_exit.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/14 05:10:04 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 03:28:47 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_exit(char **args2, t_file *file, int i)
{
	ft_printf("\033[2;32mEXIT\n\033[0m");
	ft_freestruct(file);
	if (!args2[i + 1])
	{
		ft_free_tab(args2);
		exit(EXIT_SUCCESS);
	}
	else
	{
		i = ft_atoi(args2[i + 1]);
		ft_free_tab(args2);
		exit(i);
	}
	return (0);
}
