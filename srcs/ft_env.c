/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_env.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/12 23:29:04 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 19:46:32 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_paths(char *com, char **args2, t_file *file, int i)
{
	struct stat		buffer;
	char			*temp;

	while (com[0] && file->paths && file->paths[i])
	{
		temp = ft_strjoinrem(ft_strjoin(file->paths[i], "/"), com);
		if (stat(temp, &buffer) == 0)
		{
			if (fork() == 0)
			{
				if (execve(temp, args2, file->envp) < 0 &&
					ft_printf("\033[1;31m%s not an executable\033[0m\n", com))
					exit(EXIT_SUCCESS);
			}
			ft_input(file, 1);
			if (F->stop2 == 'z' && !close(F->pfd2[1]))
				close(F->pfd2[0]);
			wait(&F->status);
			free(temp);
			return (1);
		}
		free(temp);
		i++;
	}
	return (0);
}

int		ft_exec(char *com, char **args2, t_file *file)
{
	int		fd;

	if (!ft_strncmp(com, "./", 2) || !ft_strncmp(com, "../", 3) ||
		!ft_strncmp(com, "/", 1))
	{
		if ((fd = open(com, 0)) > 0 && !close(fd))
		{
			if (F->stop == 't')
			{
				if (execve(com, args2, file->envp) < 0 &&
					ft_printf("\033[1;31m%s not an executable\033[0m\n", com))
					exit(EXIT_SUCCESS);
			}
			else if (fork() == 0 && execve(com, args2, file->envp) < 0 &&
					ft_printf("\033[1;31m%s not an executable\033[0m\n", com))
				exit(EXIT_SUCCESS);
			ft_input(file, 2);
			wait(&F->status);
			F->status = WEXITSTATUS(F->status);
			return (1);
		}
	}
	else
		return (ft_paths(com, args2, file, 0));
	return (0);
}

int		ft_env(char **args, t_file *file, int i)
{
	while (F->envp[++i])
	{
		ft_printf("%s\n", F->envp[i]);
	}
	F->status = 0;
	return (1);
}

int		ft_envsetup(char **envp, t_file *file)
{
	int i;

	i = 0;
	file->envp = ft_tabdup(envp);
	while (envp && envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			file->paths = ft_split(envp[i] + 5, ":");
			return (1);
		}
		i++;
	}
	return (0);
}
