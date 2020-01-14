/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_echo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/11 03:19:38 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 01:23:26 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_echo(char **args)
{
	int		i;

	i = 1;
	while (args && args[i])
	{
		ft_printf("%s", args[i]);
		if (args[i + 1])
			ft_printf(" ");
		i++;
	}
	ft_printf("\n");
	return (1);
}