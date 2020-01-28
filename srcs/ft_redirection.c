/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_redirection.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/27 15:20:14 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/28 14:11:49 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_redirection(char **args2, t_file *file)
{
	pid_t	pid;
	t_env	*temp;
	int		fd;
	int		fd2;
	int		backup;

	temp = F->direct;
	fd2 = 0;
	fd = 0;
	F->inbackup = dup(STDIN_FILENO);
	F->outbackup = dup(STDOUT_FILENO);
	while (temp)
	{
		if (!ft_strcmp(temp->name, ">"))
		{
			fd = open(temp->content, O_WRONLY | O_CREAT | O_TRUNC,
            S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		}
		else if (!ft_strcmp(temp->name, "d"))
		{
			fd = open(temp->content, O_WRONLY | O_CREAT | O_APPEND,
            S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		}
		else if (!ft_strcmp(temp->name, "<"))
		{
			fd2 = open(temp->content, O_RDONLY);
		}
		temp = temp->next;
	}
	if (fd2 || fd || F->sep == '|')
	{
		if (fd2)
		{
			dup2(fd2, 0);
			ft_manager(args2, file);
			close(fd2);
			dup2(F->inbackup, 0);
		}
		if (fd)
		{
			dup2(fd, 1);
			ft_manager(args2, file);
			close(fd);
			dup2(F->outbackup, 1);
		}
		if (F->sep == '|')
		{
			if (F->stop == 't')
			{
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
				while(wait(NULL) > 0)
					;
			}
			else if (fork() == 0)
			{
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
				while(wait(NULL) > 0)
					;
			}
			else
			{
				wait(NULL);
				if (F->stop == 't')
					exit (0);
				while (F->sep != ';' && F->sep && (args2 = ft_getargs(F->args, file)))
					;
				if (F->sep)
					iscommand(F->args, file);
				else
					return (-1);
			}
		}
	}
	else
		return (0);
	return (1);
}