/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parseargs.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/13 07:31:13 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/03 18:09:04 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		*ft_convert_dollar(char *nom, t_file *file)
{
	char	*name;
	int		i;
	t_env	*tmp;

	i = 0;
	tmp = F->env;
	while (tmp && tmp->name)
	{
		if (!ft_strcmp(tmp->name, nom))
			return (ft_strdup(tmp->content));
		tmp = tmp->next;
	}
	while (F->envp[i])
	{
		name = ft_strjoin(nom, "=");
		if (!ft_strncmp(name, F->envp[i], ft_strlen(name)))
		{
			free(name);
			return (ft_strdup(ft_strchr(F->envp[i], '=') + 1));
		}
		free(name);
		i++;
	}
	return (ft_strdup(""));
}

char		ft_isseparator(char *args, int *i)
{
	t_env *temp;

	if (args[*i] == '<')
	{
		return ('<');
	}
	else if (args[*i] == '>')
	{
		if (args[*i + 1] == '>')
		{
			*i += 1;
			return ('d');
		}
		else
		{
			return ('>');
		}
	}
	else if (args[*i] == '|')
		return ('|');
	else if (args[*i] == ';')
		return (';');
	return (0);
}

char		**ft_nbargs(char *args, t_file *file, int i)
{
	int y;

	y = 0;
	while (args[i])
	{
		F->sep = ft_isseparator(args, &i);
		if (F->sep == ';' || F->sep == '|')
			break ;
		if (F->sep)
		{
			if (!(ft_redirlst(F->sep, file, args, &i)))
				return (NULL);
		}
		else if ((args[i] == '\'' || args[i] == '\"'))
		{
			if (!ft_countcoma(args, &i, &y, args[i]))
				return (NULL);
		}
		else if (args[i] != ' ' && (args[i] < 9 || args[i] > 13))
			ft_countword(args, &i, &y);
		i++;
	}
	F->stop = 's';
	return (ft_calloc(sizeof(char *), y + 1));
}

char		**ft_parse(char *args, char *temp, t_file *file, int no[3])
{
	char	**args2;

	if (!(args2 = ft_nbargs(args, file, 0)) && ft_printf("multiligne error\n"))
		return (NULL);
	while (args[++no[0]])
	{
		F->sep = ft_isseparator(args, &no[0]);
		if (F->sep == ';' || F->sep == '|')
			break ;
		if (F->sep && ft_redirlst(F->sep, file, args, &no[0]))
			no[1] = no[0];
		else if (args[no[0]] == '\'')
			no[2] += singlecoma2(args, &(args2[no[2]]), &no[0], &no[1]);
		else if (args[no[0]] == '\"')
			no[2] += doublecoma2(args, &(args2[no[2]]), &no[0], &no[1]);
		else if (args[no[0]] != ' ' && (args[no[0]] < 9 || args[no[0]] > 13))
			no[2] += nocoma2(args, &(args2[no[2]]), &no[0], &no[1]);
		else if (args[no[0]] == ' ' || (args[no[0]] >= 9 && args[no[0]] <= 13))
			no[1]++;
	}
	if (F->sep == ';' || F->sep == '|')
		F->args = ft_strdup(args + no[0] + 1);
	F->stop = 0;
	return (args2);
}

char		**ft_getargs(char *args, t_file *file)
{
	char	*temp;
	char	**args2;
	int		ntn[3];

	ntn[0] = -1;
	ntn[1] = 0;
	ntn[2] = 0;
	ft_lstenvclear(&F->direct, free);
	F->sep = 0;
	temp = ft_strtrimr(args, " \t\b\r\v\f");
	free(args);
	args = temp;
	args2 = ft_parse(args, temp, file, ntn);
	free(args);
	return (args2);
}
