/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 23:53:21 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/12 03:21:18 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_manager(char *com, char *args)
{
	if (!com)
		return (0);
	if (!ft_strncmp(com, "pwd", 4))
		return (ft_printf("%s\n", getcwd(NULL, _POSIX_PATH_MAX)));
	else if (!ft_strncmp(com, "echo", 5))
		return (ft_echo(args));
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

int		iscommand(char *line)
{
	char	*com;
	char	*args;
	char	*join;
	int i;

	com = ft_strtrimr(line, " \t\b\r\v\f");
	join = ft_strdup("");
	free(line);
	i = 0;
	
	if(ft_setup(com, &join, args, &i))
	{
		free(com);
		return(0);
	}
	args = ft_strdup(com + i);
	free(com);
	if(!ft_manager(join, args))
		ft_printf("\033[1;31munknown command %s\033[0m\n", join);
	while(1)
	{
		
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
	ft_printf("\033[01;33m%s->\033[0m", buf);
	return (buf);
}

int		minishell(int fd)
{
	char	*line;
	char	*buf;
	int		i;

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
