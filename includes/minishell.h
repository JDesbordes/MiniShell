/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/11 00:32:07 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/28 20:04:12 by jdesbord    ###    #+. /#+    ###.fr     */
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
# include <signal.h>
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
	char			*home;
	char			sep;
	char			stop;
	char			stop2;
	int				status;
	int				pfd[2];
	int				inbackup;
	int				outbackup;
	t_env			*direct;
	t_env			*env;
}					t_file;

int					ft_echo(char **args, t_file *file, int i);
char				*ft_strndup(char *src, int y);
char				*invertedcoma(char *com, int *i);
char				*doublecoma(char *com, int *i, t_file *file);
int					ft_input(t_file *file, int option);
int					ft_cd(char **args, t_file *file, int i);
char				**ft_parse(char *args, char *temp, t_file *file);
int					iscommand(char *line, t_file *file);
char				*findpath(void);
int					ft_exec(char *com, char **args, t_file *file);
int					ft_env(char **args, t_file *file , int i);
int					ft_envsetup(char **envp, t_file *file);
char				**ft_getargs(char *args, t_file *file);
int					ft_exit(char **args2, t_file *file);
int					ft_varenv(char **args, t_file *file, int *i);
t_env				*ft_lstenvnew(char *name, char *content);
t_env				*ft_lstenvlast(t_env *lst);
void				ft_lstenvadd_back(t_env **alst, t_env *new);
void				ft_lstenvdelone(t_env *lst, void (*del)(void*));
void				ft_lstenvclear(t_env **lst, void (*del)(void*));
char				*ft_dollar(char *str, int *i, t_file *file);
void				ft_converter(char **args2, t_file *file, int i);
int					ft_redirlst(char c, t_file *file, char *args, int *i);
int					ft_countcoma(char *args, int *i, int *y, char c);
char				ft_isseparator(char *args, int *i);
void				ft_countword(char *args, int *i, int *y);
int					ft_redirection(char **args2, t_file *file);
int					ft_manager(char **args2, t_file *file);

char 				*ft_interrog(t_file *file);
void				ft_converter2(char **args2, t_file *file, int i);
int     			ft_unset(char **args, t_file *file , int i);
int     			ft_export(char **args, t_file *file , int i);
int					ft_isvar(char *str);
int     			ft_exist_env(char **env, char *args);
char				*ft_convert_dollar(char *nom, t_file *file);

#endif
