/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_input.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/12 20:09:41 by jdesbord     #+#   ##    ##    #+#       */
<<<<<<< HEAD
/*   Updated: 2020/01/20 20:14:58 by nepage-l    ###    #+. /#+    ###.fr     */
=======
/*   Updated: 2020/01/20 06:14:15 by jdesbord    ###    #+. /#+    ###.fr     */
>>>>>>> ddb517fb376860809bc4e6f910020f6e96fa85a3
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_ctrlC(int i)
{
<<<<<<< HEAD
	char *tmp;

	tmp = findpath();
	ft_printf("\n\033[01;33m%s->\033[0m", tmp);
	free(tmp);
=======
	ft_printf("\n\033[01;33m%s->\033[0m", findpath());
>>>>>>> ddb517fb376860809bc4e6f910020f6e96fa85a3
}

void	ft_ctrlbslash(int i)
{
	signal(i, SIG_IGN);
}

int		ft_input(t_file *file)
{
	signal(SIGINT, ft_ctrlC);
	signal(SIGQUIT, ft_ctrlbslash);
	return (1);
}