/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_exit.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/14 05:10:04 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 03:43:53 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_exit(char **args2, t_file *file, int i)
{
	ft_printf("\033[2;32mEXIT\n\033[0m");
	if (!args2[i + 1])
		exit(EXIT_SUCCESS);
	else
		exit(ft_atoi(args2[i + 1]));
	return (0);
}