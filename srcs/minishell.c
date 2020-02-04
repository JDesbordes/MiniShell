/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 23:53:21 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 03:29:13 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	iscommand2(t_file *file, char **args2)
{
	if (F->stop2 == 't' || F->stop2 == 'z')
	{
		dup2(F->outbackup, 1);
		dup2(F->inbackup, 0);
		F->stop2 = 0;
	}
	if (F->stop == '!')
	{
		F->stop2 = 'z';
		pipe(F->pfd2);
		if ((fork()) == 0)
		{
			dup2(F->pfd2[1], 1);
			exit(0);
		}
		dup2(F->pfd2[0], 0);
		close(F->pfd2[0]);
		close(F->pfd2[1]);
		wait(NULL);
	}
	ft_free_tab(args2);
	if ((F->sep == ';' || F->sep == '|') && (F->stop2 = 't'))
		iscommand(F->args, file);
}

int		iscommand(char *line, t_file *file)
{
	char	**args2;
	int		i;

	F->sep = 0;
	if (!(args2 = ft_getargs(line, file)))
		return (0);
	if ((i = ft_redirection(args2, file)))
	{
		if (i < 0)
		{
			ft_free_tab(args2);
			return (0);
		}
	}
	else if (!ft_manager(args2, file))
	{
		ft_printf("\033[1;31munknown command %s\033[0m\n", args2[0]);
		F->status = 127;
	}
	iscommand2(file, args2);
	return (0);
}

void	ft_minishell_gnl(int fd, char **line, t_file *file)
{
	if (!fd)
	{
		F->pathend = findpath();
		ft_printf("\033[1;32mWELCOME TO MINISHELL\033[0m\n");
		ft_printf("\033[01;33m%s->\033[0m", file->pathend);
	}
	while (ft_input(0) && get_next_line(fd, &(*line)))
	{
		F->stop = 0;
		if (check_syntax((*line)))
			iscommand((*line), file);
		else if (fd)
		{
			free((*line));
			(*line) = NULL;
			break ;
		}
		if (!fd)
			ft_printf("\033[01;33m%s->\033[0m", file->pathend);
		(*line) = NULL;
	}
}

int		minishell(int fd, char **envp)
{
	char	*line;
	int		i;
	t_file	*file;

	i = -1;
	file = ft_calloc(sizeof(t_file), 1);
	file->stop = 1;
	F->inbackup = dup(STDIN_FILENO);
	F->outbackup = dup(STDOUT_FILENO);
	ft_envsetup(envp, file);
	ft_minishell_gnl(fd, &line, file);
	if (line)
	{
		F->stop = 0;
		if (check_syntax(line))
			iscommand(line, file);
		else if (fd)
			free(line);
	}
	if (!fd)
		ft_printf("\033[2;32m\nEXIT\n\033[0m");
	ft_freestruct(file);
	return (0);
}

int		main(int ac, char **av, char **envp)
{
	int fd;

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
