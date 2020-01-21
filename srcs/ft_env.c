/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_env.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/12 23:29:04 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/19 23:12:48 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_paths(char *com, char **args2, t_file *file)
{
	struct 	stat   buffer;
	int		i;
	char	*temp;

	i = 0;
	while (com[0] && file->paths && file->paths[i])
	{
		temp = ft_strjoin(file->paths[i], "/");
		temp = ft_strjoinrem(temp, com);
		if (stat (temp, &buffer) == 0)
		{
			if (fork() == 0)
			{
				if (execve(temp, args2 , file->envp) < 0)
				{
					ft_printf("\033[1;31m%s not an executable\033[0m\n", com);
					exit(EXIT_SUCCESS);
				}
			}
			wait(NULL);
			return (1);
		}
		free (temp);
		i++;
	}
	return (0);
}

int		ft_env(char *com, char **args2, t_file *file)
{
	int		fd;
	
	if(!ft_strncmp(com, "./", 2))
	{
		if ((fd = open(com, 0)) > 0)
		{
			close(fd);
			if (fork() == 0)
			{
				if (execve(com, args2 , file->envp) < 0)
				{
					ft_printf("\033[1;31m%s not an executable\033[0m\n", com);
					exit(EXIT_SUCCESS);
				}
			}
			wait(NULL);
			return (1);
		}
	}
	else
		return (ft_paths(com, args2, file));
	return(0);
}

int		ft_envsetup(char **envp, t_file *file)
{
	int i;

	i = 0;
	file->envp = envp;
	while(envp && envp[i])
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
