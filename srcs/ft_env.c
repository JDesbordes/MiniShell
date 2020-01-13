/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_env.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/12 23:29:04 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 06:42:51 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_paths(char *com, char **args2, t_file *file)
{
	struct stat   buffer;
	int i;
	char	*temp;

	i = 0;
	while (file->paths && file->paths[i])
	{
		temp = ft_strjoin(file->paths[i], "/");
		temp = ft_strjoinrem(temp, com);
		if ((stat (temp, &buffer) == 0) && fork() == 0)
		{
			char *newargv2[] = {temp, NULL};
			if (execve(temp, args2 , NULL) < 0)
			{
				ft_printf("\033[1;31m%s not an executable\033[0m\n", com);
				exit(EXIT_SUCCESS);
			}
		}
		free (temp);
		i++;
	}
}

int		ft_env(char *com, char **args2, t_file *file)
{
	int		fd;
	
	if(!ft_strncmp(com, "./", 2) && (fd = open(com, 0)) > 0)
	{
		close(fd);
		if (fork() == 0)
		{
			char *newargv2[] = {com, NULL};
			if (execve(com, args2 , NULL) < 0)
			{
				ft_printf("\033[1;31m%s not an executable\033[0m\n", com);
				exit(EXIT_SUCCESS);
			}
		}
	}
	else
		ft_paths(com, args2, file);
	wait(NULL);
	return(1);
}

int		ft_envsetup(char **envp, t_file *file)
{
	int i;

	i = 0;
	while(envp && envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			file->paths = ft_split(envp[i], ":");
			return (1);
		}
		i++;
	}
	return (0);
}
