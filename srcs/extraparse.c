/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   extraparse.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/25 13:44:06 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/27 17:21:58 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_countcoma(char *args, int *i, int *y, char c)
{
	(*i)++;
	while (args[*i] && args[*i] != c)
		(*i)++;
	if (!args[(*i)])
		return (0);
	(*i)++;
	if (!args[(*i)] || ft_isseparator(args, i) || args[*i] == ' ' || (args[*i] >= 9 && args[*i] <= 13))
		(*y)++;
	(*i)--;
	return (1);
}

void	ft_countword(char *args, int *i, int *y)
{
	int j;

	j = 0;
	(*y)++;
	while (args[(*i)] && !ft_isseparator(args, i) && (args[(*i)] != ' ' && args[(*i)] != '\''
	&& args[(*i)] != '\"' && (args[(*i)] < 9 || args[(*i)] > 13)) && !(j = 0))
		(*i)++;
	(*i)--;
}
