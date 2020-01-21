/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 02:27:31 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 17:23:05 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct		s_list2
{
	void			*data;
	struct s_list2	*next;
}					t_list2;

int					ft_strcmp(const char *str, const char *str2);
char				*ft_strcpy(char *str, const char *str2);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *str);
ssize_t				ft_write(int fd, const void *str, size_t len);
ssize_t				ft_read(int fd, void *buf, size_t count);
int					ft_atoi_base(char *str, char *base);
int					ft_list2_push_front(t_list2 **addr, void *data);
t_list2				*ft_list2_create_elem(void *content);
int					ft_list2_size(t_list2 *begin_list2);
void 				ft_list2_sort(t_list2 **begin_list2, int (*cmp)());
void				ft_list2_remove_if(t_list2 **begin_list2, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

#endif
