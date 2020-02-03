/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cd.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/12 03:53:30 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 19:08:39 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_cd(char **args, t_file *file, int i)
{
	char *str;

	if (!args[i] || !strncmp(args[i], "~", 2))
	{
		str = ft_convert_dollar("HOME", file);
		if ((F->status = chdir(str)) == -1)
			ft_printf("HOME not set\n");
		free(str);
	}
	else if ((F->status = chdir(args[i])) == -1)
		ft_printf("%s\n", strerror(errno));
	if (!(ft_strncmp(str = getcwd(NULL, _POSIX_PATH_MAX), "/", 2)))
	{
		free(F->pathend);
		F->pathend = ft_strdup("/");
	}
	else
	{
		free(F->pathend);
		F->pathend = findpath();
	}
	free(str);
	return (1);
}
