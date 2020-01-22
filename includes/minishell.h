/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/11 00:32:07 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 09:32:33 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <errno.h>
# include "../Libftprintf/includes/ft_printf.h"
# include "../libasm/testsrcs/main.h"

# define F file

typedef struct		s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
}					t_env;

typedef struct		s_file
{
	char			*pathend;
	char			**paths;
	char			**envp;
	char			*args;
	char			sep;
	t_env			*env;
}					t_file;

int					ft_echo(char **args, int i);
char				*ft_strndup(char *src, int y);
int					invertedcoma(char *com, int *i, char **join, char *args);
int					doublecoma(char *com, int *i, char **join, char *args);
int					ft_input(t_file *file);
int					ft_cd(char **args, t_file *file);
char				**ft_parse(char *args, char *temp, t_file *file);
int					iscommand(char *line, t_file *file);
char				*findpath(void);
int					ft_env(char *com, char **args, t_file *file);
int					ft_envsetup(char **envp, t_file *file);
char				**ft_getargs(char *args, t_file *file);
int					ft_exit(char **args2, t_file *file);
int					ft_varenv(char **args, t_file *file, int *i);
t_env				*ft_lstenvnew(char *name, char *content);
t_env				*ft_lstenvlast(t_env *lst);
void				ft_lstenvadd_back(t_env **alst, t_env *new);
void				ft_lstenvdelone(t_env *lst, void (*del)(void*));
void				ft_lstenvclear(t_env **lst, void (*del)(void*));
void				ft_env_struct(char **envp, t_file *file);
void				ft_dollar(char **args2, t_file *file);
void				ft_converter(char **args2, t_file *file, int i);

#endif
