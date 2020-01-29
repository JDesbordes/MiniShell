/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_synthax.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/29 16:08:52 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 16:16:58 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		return_status(int errcode)
{
	if (errcode == 0)
		ft_printf("syntax error near unexpected token |\n");
	if (errcode == 1)
		ft_printf("syntax error near unexpected token ;\n");
	return (0);
}
int		limite(char *s, int i, int cpt)
{
	while (i >= 0 && s[i] != ';' && s[i] != '(' && s[i] != '|')
	{
		if (s[i] == '&' && s[i + 1] == '&' && cpt == 0)
			return (0);
		if (s[i] == '|' && s[i + 1] == '|' && cpt == 0)
			return (0);
		if (ft_isalnum(s[i]))
			cpt++;
		i--;
	}
	return (cpt == 0 ? 0 : 1);
 }

int		check_syntax(char *s, t_file *file)
{
	int		i;
	i = 0;
	while (s[i])
	{
		if ((s[i] == ';') && !limite(s, i - 1, 0))
			return (return_status(1));
		else if (s[i] == '|' && s[i + 1] && s[i + 1] == '|')
		{
			if (!limite(s, i - 1, 0))
				return (return_status(5));
			else
				i++;
		}
		else if ((s[i] == '|') && !limite(s, i - 1, 0))
			return (return_status(0));
		i++;
	}
	return (1);
}