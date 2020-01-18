/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cd.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <nepage-l@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/12 03:53:30 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/18 12:01:55 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_cd(char **args, t_file *file)
{
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
