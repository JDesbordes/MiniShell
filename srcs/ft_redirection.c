/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_redirection.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/27 15:20:14 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 19:34:36 by jdesbord    ###    #+. /#+    ###.fr     */
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
			if ((fd2 = open(temp->content, O_RDONLY)) < 0)
				return (-ft_printf("\033[1;31m%s doesn't exist\n\033[0m", temp->content));
		}
		temp = temp->next;
	}
	if (fd2)
	{
		F->stop2 = 't';
		dup2(fd2, 0);
		close(fd2);
	}
	if (fd)
	{
		F->stop2 = 't';
		dup2(fd, 1);
		close(fd);
	}
	//case with redirection plus | so (ls > ble | ls > blu) works
	if (F->sep == '|' && fd)
		F->stop = '!';
	if (F->sep == '|' && !fd)
	{
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
		while(wait(NULL) > 0)
			;
	}
	else
		return (0);
	return (1);
}