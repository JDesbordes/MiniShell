/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/11 00:32:07 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 01:32:22 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <limits.h>
# include "../Libftprintf/includes/ft_printf.h"

typedef struct		s_file
{
	char	*pathend;
	int		done;
}					t_file;

int		ft_echo(char *args);
int     ft_setup(char *com, char **join, char *args, int *i);
char	*ft_strndup(char *src, int y);
int		invertedcoma(char *com, int *i, char **join, char *args);
int		doublecoma(char *com, int *i, char **join, char *args);
int		ft_input();
int		ft_cd(char *args, t_file *file);
int		ft_parse(char *args, int *i, char *temp, char **join);
int		iscommand(char *line, t_file *file);
char	*findpath(void);
int		ft_env(char *com, char *args, t_file *file);

#endif
