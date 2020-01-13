/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_echo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/11 03:19:38 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/12 20:50:26 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_parse(char *args, int *i, char *temp, char **join)
{
	while(args[*i] && args[*i] != ';')
	{
		if (args[*i] == '\"')
		{
			if (!invertedcoma(args, i, join, temp))
				return (1);
		}
		else if (args[*i] == '\'')
		{
			if (!doublecoma(args, i, join, temp))
				return (1);
		}
		else
		{
			temp = ft_strndup(args + *i, 1);
			*join = ft_strjoinrem(*join, temp);
			free(temp);
		}
		*i += 1;
	}
	return (0);
}

int		ft_echo(char *args)
{
	int		i;
	char	*temp;
	char 	*join;
	
	i = 0;
	temp = ft_strtrimr(args, " \t\b\r\v\f");
	free(args);
	args = temp;
	join = ft_strdup("");
	if (ft_parse(args, &i, temp, &join))
		return (1);
	ft_printf("%s", join);
	return (1);
}