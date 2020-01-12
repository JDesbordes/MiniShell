/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/11 00:32:07 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/12 03:24:30 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <limits.h>
# include "../Libftprintf/includes/ft_printf.h"

int		ft_echo(char *args);
int     ft_setup(char *com, char **join, char *args, int *i);
char	*ft_strndup(char *src, int y);
int		invertedcoma(char *com, int *i, char **join, char *args);
int		doublecoma(char *com, int *i, char **join, char *args);

#endif
