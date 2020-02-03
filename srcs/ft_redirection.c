/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_redirection.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/27 15:20:14 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/03 18:31:25 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_readirection(t_file *file, int *fd, int *fd2)
{
	t_env	*temp;

	temp = F->direct;
	*fd = 0;
	*fd2 = 0;
	while (temp)
	{
		if (!ft_strcmp(temp->name, ">"))
		{
			*fd = open(temp->content, O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		}
		else if (!ft_strcmp(temp->name, "d"))
		{
			*fd = open(temp->content, O_WRONLY | O_CREAT | O_APPEND,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		}
		else if (!ft_strcmp(temp->name, "<"))
			if ((*fd2 = open(temp->content, O_RDONLY)) < 0)
				return (-ft_printf("\033[1;31m%s doesn't exist\n\033[0m",
				temp->content));
				temp = temp->next;
	}
	return (1);
}

void	ft_pipe(t_file *file, char **args2)
{
	pid_t	pid;

	F->stop2 = 0;
	pipe(F->pfd);
	if ((pid = fork()) == 0)
	{
		dup2(F->pfd[1], 1);
		ft_manager(args2, file);
		exit(0);
	}
	dup2(F->pfd[0], 0);
	close(F->pfd[0]);
	close(F->pfd[1]);
	while (wait(NULL) > 0)
		;
}

int		ft_redirection(char **args2, t_file *file)
{
	int		fd[2];
	int		backup;

	if (ft_readirection(file, &fd[0], &fd[1]) < 0)
		return (-1);
	if (fd[1])
	{
		F->stop2 = 't';
		dup2(fd[1], 0);
		close(fd[1]);
	}
	if (fd[0])
	{
		F->stop2 = 't';
		dup2(fd[0], 1);
		close(fd[0]);
	}
	if (F->sep == '|' && fd[0])
		F->stop = '!';
	if (F->sep == '|' && !fd[0])
		ft_pipe(file, args2);
	else
		return (0);
	return (1);
}
