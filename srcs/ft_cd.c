/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cd.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/12 03:53:30 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/28 20:24:45 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_cd(char **args, t_file *file, int i)
{
	if (!args[i] || !strncmp(args[i], "~", 2))
	{
		/*if (!args[i])
		{
			free(args[i - 1]);
			args = ft_split("cd $HOME", " ");
		}
		else
		{
			free(args[i]);
			args[1] = ft_strdup("$HOME");
		}*/
		args[i] = ft_convert_dollar("HOME", file);
	}
	if ((F->status = chdir(args[i])) == -1)
	{
		ft_printf("%s\n", strerror(errno));
	}
	if (!(ft_strncmp(getcwd(NULL, _POSIX_PATH_MAX), "/", 2)))
		file->pathend = ft_strdup("/");
	else
		file->pathend = findpath();
	return (1);
}
