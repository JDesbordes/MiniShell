/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 23:53:21 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/11 21:07:51 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		iswhitespace(char c)
{
	
}

void	iscommand(char *line)
{
	char	*str;
	int		i;

	str = ft_strtrimr(line, " \t\b\r\v\f");
	free(line);
	i = 0;
	if (!str)
		return ;
	if (!ft_strncmp(str + i, "pwd", 3))
		ft_printf("%s\n", getcwd(NULL, _POSIX_PATH_MAX));
	else if (!ft_strncmp(str + i, "echo", 4) && (str[i+4] == 0 || str[i+4] == ';' || str[i+4] == ' '))
		ft_echo(str, &i);
	else
		ft_printf("\033[1;31munknown command %s\033[0m\n",ft_split(str," \t\b\r\v\f")[0]);
}

char	*findpath(void)
{
	char	**path;
	char	*buf;
	int		i;

	i = -1;
	path = ft_split(getcwd(NULL, _POSIX_PATH_MAX), "/");
	while (path[++i])
		if (path[i + 1])
			free(path[i]);
	buf = path[--i];
	free(path);
	ft_printf("\033[01;33m%s->\033[0m", buf);
	return (buf);
}

int		minishell(int fd)
{
	char	*line;
	char	*buf;
	int		i;

	buf = malloc(sizeof(char) * _POSIX_PATH_MAX);
	ft_printf("\033[0;32mWELCOME TO MINISHELL\033[0m\n");
	i = -1;
	if (!fd)
		buf = findpath();
	while (get_next_line(fd, &line))
	{
		iscommand(line);
		if (!fd)
			ft_printf("\033[01;33m%s->\033[0m", buf);
	}
	free(buf);
	return (0);
}

int		main(int ac, char **av)
{
	int fd;

	if (ac == 1)
	{
		minishell(0);
	}
	else if (ac >= 2)
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
			ft_printf("minishell: %s is not a file\n", av[1]);
		else
			minishell(fd);
	}
	return (0);
}
