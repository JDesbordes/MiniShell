/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_manager.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/04 03:15:52 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 03:26:59 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_manager(char **args2, t_file *file)
{
	int		i;

	i = 0;
	ft_varenv(args2, file, &i);
	ft_converter(args2, file, i - 1);
	if (!args2 || !args2[i])
		return (1);
	if (!ft_strncmp(args2[i], "pwd", 4))
		return (ft_pwd());
	else if (!ft_strncmp(args2[i], "echo", 5))
		return (ft_echo(args2, file, i));
	else if (!ft_strncmp(args2[i], "cd", 3))
		return (ft_cd(args2, file, i + 1));
	else if (!ft_strncmp(args2[i], "exit", 5))
		return (ft_exit(args2, file, i));
	else if (!ft_strncmp(args2[i], "env", 4))
		return (ft_env(file, -1));
	else if (!ft_strncmp(args2[i], "unset", 6))
		return (ft_unset(args2, file, i));
	else if (!ft_strncmp(args2[i], "export", 7))
		return (ft_export(args2, file, i));
	else
		return (ft_exec(args2[i], args2 + i, file));
	return (0);
}

char	*ft_strndup(char *src, int y)
{
	int		i;
	char	*src2;

	i = 0;
	while (src[i] != '\0' && i < y)
		i++;
	if (!(src2 = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (src[i] && i < y)
	{
		src2[i] = src[i];
		i++;
	}
	src2[i] = '\0';
	return (src2);
}

char	*findpath(void)
{
	char	*path;
	char	*buf;
	int		i;

	i = -1;
	buf = getcwd(NULL, _POSIX_PATH_MAX);
	path = ft_strdup(ft_strrchr(buf, '/'));
	free(buf);
	return (path);
}
