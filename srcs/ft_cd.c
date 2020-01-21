/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cd.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <nepage-l@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/12 03:53:30 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 19:47:03 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_cd(char **args, t_file *file)
{
	if (!args[1] || !strncmp(args[1], "~", 2))
	{
		if (!args[1])
		{
			free(args[0]);
			args = ft_split("cd $HOME", " ");
		}
		else
		{
			free(args[1]);
			args[1] = ft_strdup("$HOME");
		}
		ft_dollar(args, file);
	}
	if (chdir(args[1]) == -1)
	{
		ft_printf("%s\n", strerror(errno));
	}
	if (!(ft_strncmp(getcwd(NULL, _POSIX_PATH_MAX), "/", 2)))
		file->pathend = ft_strdup("/");
	else
		file->pathend = findpath();
	return (1);
}
