/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 23:53:21 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 02:36:26 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_manager(char **args2, t_file *file)
{
	int i;

	i = 0;
	if (!args2 || !args2[0])
		return (1);
	if (!ft_strncmp(args2[0], "pwd", 4))
		return (ft_printf("%s\n", getcwd(NULL, _POSIX_PATH_MAX)));
	else if (!ft_strncmp(args2[0], "echo", 5))
		return (ft_echo(args2));
	else if (!ft_strncmp(args2[0], "cd", 3))
		return (ft_cd(args2, file));
	else
		return (ft_env(args2[0], args2, file));
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

int		iscommand(char *line, t_file *file)
{
	char	*args;
	char	**args2;
	char	**cutargs;
	int		i;

	i = 0;
	if(!(args2 = ft_getargs(line)))
		return(0);
	while ((cutargs = semicolon(args2, &i)))
	{
		if(!ft_manager(cutargs, file))
			ft_printf("\033[1;31munknown command %s\033[0m\n", cutargs[0]);
		free(cutargs);
	}
	return (0);
}

char	*findpath(void)
{
	char	**path;
	char	*buf;
	int		i;

	i = -1;
	path = ft_split(buf = getcwd(NULL, _POSIX_PATH_MAX), "/");
	free(buf);
	while (path[++i])
		if (path[i + 1])
			free(path[i]);
	buf = path[--i];
	free(path);
	return (buf);
}

int		minishell(int fd, char **envp)
{
	char	*line;
	int		i;
	t_file	*file;

	i = -1;
	file = malloc(sizeof(t_file) * 1);
	ft_envsetup(envp, file);
	if (!fd)
	{
		file->pathend = findpath();
		ft_printf("\033[0;32mWELCOME TO MINISHELL\033[0m\n\033[01;33m%s->\033[0m", file->pathend);
	}
	while (ft_input() && get_next_line(fd, &line))
	{
		iscommand(line, file);
		if (!fd)
			ft_printf("\033[01;33m%s->\033[0m", file->pathend);
	}
	if (line[0])
		iscommand(line, file);
	if (!fd)
		ft_printf("\033[2;32m\nEXIT\n\033[1m");
	if (!fd)
		free(file->pathend);
	return (0);
}

int		main(int ac, char **av, char** envp)
{
	int fd;
	int i;

	i = 0;
	if (ac == 1)
		minishell(0, envp);
	else if (ac >= 2)
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
			ft_printf("minishell: %s is not a file\n", av[1]);
		else
			minishell(fd, envp);
	}
	return (0);
}
