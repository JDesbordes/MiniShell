/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parseargs.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/13 07:31:13 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 14:03:15 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		*ft_convert_dollar(char *nom, t_file *file)
{
	char	*name;
	int 	i;
	int 	j;
	t_env	*tmp;
	
	i = 0;
	tmp = F->env;
	while (tmp && tmp->name)
	{
		if (!ft_strcmp(tmp->name, nom))
			return(ft_strdup(tmp->content));
		tmp = tmp->next;
	}
	while (F->envp[i])
	{
		j = 0;
		while (F->envp[i][j] != '=')
			j++;
		name = ft_strndup(F->envp[i], j);
		if (!ft_strcmp(name, nom))
		{
			free(name);
			return(ft_strdup(F->envp[i] + j + 1));
		}
		i++;
	}
	return (ft_strdup(""));
}

char		*ft_dollar(char *str, int *i, t_file *file)
{
	int j;
	char *temp;

	*i += 1;
	j = *i;
	while (str[*i] && str[*i] != ' ' && str[*i] != '\"' &&
		str[*i] != '\'' && str[*i] != '$')
	{
		*i += 1;
	}
	temp = ft_strndup(str + j, *i - j);
	*i -= 1;
	return (ft_convert_dollar(temp, file));
}

char	ft_isseparator(char *args, int *i)
{
	if (args[*i] == '<')
		return('<');
	else if (args[*i] == '>')
	{
		if (args[*i + 1] == '>')
		{
			return('d');
			*i += 1;
		}
		else
		{
			return('>');
		}
	}
	else if (args[*i] == '|')
	{
		return('|');
	}
	else if (args[*i] == ';')
	{
		return(';');
	}
	return (0);
}

char	**ft_nbargs(char *args, t_file *file)
{
	int y;
	int j;
	int i;

	i = 0;
	y = 0;
	while (args[i])
	{
		j = 0;
		if ((F->sep = ft_isseparator(args, &i)))
			break;
		if (args[i] == '\'')
		{
			i++;
			while (args[i] && args[i] != '\'')
				i++;
			if (!args[i])
				return (NULL); //error on multiligne
			i++;
			if (!args[i] || ft_isseparator(args, &i))
				y++;
			i--;
		}
		else if (args[i] == '\"')
		{
			i++;
			while (args[i] && args[i] != '\"')
				i++;
			if (!args[i])
				return (NULL); //error on multiligne
			i++;
			if (!args[i] || ft_isseparator(args, &i))
				y++;
			i--;
		}
		else
		{
			if ((args[i] == ' ' || (args[i] >= 9 && args[i] <= 13)) && (j = 1))
				y++;
			while (args[i] && (args[i] == ' ' || (args[i] >= 9 && args[i] <= 13)))
				i++;
			while (args[i] && !ft_isseparator(args, &i) && (args[i] != ' ' && args[i] != '\''
			&& args[i] != '"' && (args[i] < 9 || args[i] > 13)) && !(j = 0))
				i++;
			if (!args[i])
				y++;
			if (ft_isseparator(args, &i) && --j)
				y++;
			i--;
			
		}
		i++;
	}
	return (ft_calloc(sizeof(char *), y + 1));
}

char		**ft_parse(char *args, char *temp, t_file *file)
{
	char	**args2;
	int		y;
	int		i;
	int 	j;
	int		k;

	y = -1;
	i = 0;
	if(!(args2 = ft_nbargs(args, file)))
	{
		ft_printf("multiligne error\n");
		return (NULL);
	}
	i = 0;
	y = 0;
	k = 0;
	while (args[i])
	{
		j = 0;
		if ((F->sep = ft_isseparator(args, &i)))
			break;
		if (args[i] == '\'')
		{
			i++;
			while (args[i] && args[i] != '\'')
				i++;
			i++;
			if (!args[i] || ft_isseparator(args, &i))
			{
				args2[y] = ft_strndup(args + k, i - k);
				k = i;
				y++;
			}
			i--;
		}
		else if (args[i] == '\"')
		{
			i++;
			while (args[i] && args[i] != '\"')
				i++;
			i++;
			if (!args[i] || ft_isseparator(args, &i))
			{
				args2[y] = ft_strndup(args + k, i - k);
				k = i;
				y++;
			}
			i--;
		}
		else
		{
			if ((args[i] == ' ' || (args[i] >= 9 && args[i] <= 13)) && (j = 1))
			{
				args2[y] = ft_strndup(args + k, i - k);
				k = i;
				y++;
			}
			while (args[i] && (args[i] == ' ' || (args[i] >= 9 && args[i] <= 13)))
			{
				k++;
				i++;
			}
			while (args[i] && !ft_isseparator(args, &i) && (args[i] != ' ' && args[i] != '\''
			&& args[i] != '"' && (args[i] < 9 || args[i] > 13)) && !(j = 0))
				i++;
			if (!args[i])
			{
				args2[y] = ft_strndup(args + k, i - k);
				k = i;
				y++;
			}
			if (ft_isseparator(args, &i) && --j)
			{
				args2[y] = ft_strndup(args + k, i - k);
				k = i;
				y++;
			}
			i--;
			
		}
		i++;
	}
	if (F->sep)
		F->args = ft_strdup(args + i + 1);
	return (args2);
}

char	**ft_getargs(char *args, t_file *file)
{
	char *temp;
	char **args2;

	temp = ft_strtrimr(args, " \t\b\r\v\f");
	free(args);
	args = temp;
	args2 = ft_parse(args, temp, file);
	free(args);
	return(args2);
}
