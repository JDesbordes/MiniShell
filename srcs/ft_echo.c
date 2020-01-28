/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_echo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/11 03:19:38 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/28 19:38:00 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_echo(char **args, t_file *file, int i)
{
	int option;

	option = 0;
	i++;
	if (args[1])
	{
		if (!ft_strcmp(args[1], "-n"))
		{
			option = 1;
			i++;
		}
		while (args && args[i])
		{
			if (args[i][0])
			{
				ft_printf("%s", args[i]);
				if (args[i + 1])
					ft_printf(" ");
			}
			i++;
		}
	}
	option ? 0 : ft_printf("\n");
	F->status = 0;
	return (1);
}
