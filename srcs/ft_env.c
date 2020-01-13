/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_env.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/12 23:29:04 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 05:03:43 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_env(char *com,char *args, t_file *file)
{
	int		fd;
	
	if(!ft_strncmp(com, "./", 2) && (fd = open(com, 0)) > 0)
	{
		close(fd);
		if (fork() == 0)
		{
			char *newargv2[] = {com, NULL};
			execve(com, newargv2 , NULL);
			/*char *newargv[] = {"/bin/ls", NULL};
			if (execve("/bin/ls", newargv , NULL) < 0)
			{
				ft_printf("No such file or directory\n");
				exit(EXIT_SUCCESS);
			}*/
		}
	}
	else
		return (0);
	wait(NULL);
	return(1);
}
