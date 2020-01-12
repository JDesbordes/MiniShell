/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_echo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/11 03:19:38 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/12 03:34:53 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_echo(char *args)
{
	int		i;
	char	*temp;
	char 	*join;
	
	temp = ft_strtrimr(args, " \t\b\r\v\f");
	free(args);
	args = temp;
	join = ft_strdup("");
	i = 0;
	while(args[i] && args[i] != ';')
	{
		if (args[i] == '\"')
		{
			if (!invertedcoma(args, &i, &join, temp))
				return (1);
		}
		else if (args[i] == '\'')
		{
			if (!doublecoma(args, &i, &join, temp))
				return (1);
		}
		else
		{
			temp = ft_strndup(args + i, 1);
			join = ft_strjoinrem(join, temp);
			free(temp);
		}
		i++;
	}
	ft_printf("%s", join);
	return (1);
}