/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_exit.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/14 05:10:04 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 16:13:42 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_exit(char **args2, t_file *file)
{
	ft_printf("\033[2;32mEXIT\n\033[0m");
	exit(EXIT_SUCCESS);
	return (0);
}