/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cd.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/12 03:53:30 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/12 21:25:34 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_cd(char *args, t_file *file)
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
	temp = ft_strtrimr(join, " \t\b\r\v\f");
	chdir(temp);
	file->pathend = findpath();
	free(temp);
	free(join);
	if (args[i] == ';')
		iscommand(args + i + 1, file);
	return (1);
}
