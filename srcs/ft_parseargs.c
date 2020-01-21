/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parseargs.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <nepage-l@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/13 07:31:13 by jdesbord     #+#   ##    ##    #+#       */
<<<<<<< HEAD
/*   Updated: 2020/01/20 21:39:21 by nepage-l    ###    #+. /#+    ###.fr     */
=======
/*   Updated: 2020/01/21 16:51:56 by jdesbord    ###    #+. /#+    ###.fr     */
>>>>>>> ddb517fb376860809bc4e6f910020f6e96fa85a3
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		ft_dollar(char **args2, t_file *file)
{
<<<<<<< HEAD
	int		i;
	int		check;
=======
	/*int		i;
>>>>>>> ddb517fb376860809bc4e6f910020f6e96fa85a3
	char	*tmp;
	t_env	*tmpfile;

	i = 0;
	while (args2[i])
	{
		check = 1;
		if (args2[i][0] == '$')
		{
			tmp = ft_substr(args2[i], 1, ft_strlen(args2[i]));
			tmp = ft_strjoinrem(tmp, "="); 
			free(args2[i]);
			tmpfile = file->env;
			while(file->env)
			{
				if (!ft_strncmp(tmp, file->env->str, ft_strlen(tmp) + 1))
				{
					args2[i] = ft_strdup(file->env->content);
					check = 0;
				}
				file->env = file->env->next;
			}
			check ? args2[i] = ft_strdup("") : 0;
			file->env = tmpfile;
		}

		i++;
	}*/
}

char	ft_isseparator(char *args, int *i)
{
<<<<<<< HEAD
	int k;
	int j;

	k = 0;
	if (args[*i] && (args[*i] == ' ' || (args[*i] >= 9 && args[*i] <= 13)))
		*y += 1;
	*y == -1 ? *y += 1 : 0;
	while (args[*i] && (args[*i] == ' ' || (args[*i] >= 9 && args[*i] <= 13)))
		*i += 1;
	j = *i;
	while (args[*i] && args[*i] != ' ' && (args[*i] < 9 || args[*i] > 13)
			&& args[*i] != '\'' && args[*i] != '\"' && args[*i] != ';')
=======
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
>>>>>>> ddb517fb376860809bc4e6f910020f6e96fa85a3
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
	/*ft_printf("leftover = %s\n", F->args);
	y = 0;
	while (args2[y])
	{
		ft_printf("%s\n", args2[y]);
		y++;
	}
	ft_printf("sep = %c\n", F->sep);*/
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
	//ft_dollar(args2, file);
	return(args2);
}
