/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/30 16:38:14 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/17 21:50:12 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../Libft/libft.h"
# include <stdarg.h>

int					ft_printf(const char *str, ...) __attribute__
						((format(printf,1,2)));
char				*ft_uptochar(char *str, int c);

typedef	struct		s_vals
{
	int				zero;
	int				minus;
	char			flag;
	int				error;
	int				width;
	int				preci;
	int				extrasize;
	char			convert;
	char			*content;
	char			*str2;
	char			*result;
	int				addminus;
	va_list			ap;
}					t_vals;

char				*ft_strjoindel(char const *s1,
						char const *s2, t_vals *lst, int test);
void				ft_setstr(char **str, t_vals *lst, int i);
int					ft_minus(t_vals *lst);
int					flag_c(t_vals *lst, va_list va);
int					flag_i(t_vals *lst, va_list va);
char				*flag_s(t_vals *lst, va_list va);
int					flag_p(t_vals *lst, va_list va);
int					flag_x(t_vals *lst, va_list va);
void				codelyoko(t_vals *lst);
int					readline(char *str, t_vals *stuff);
int					ft_is_conv(char c);
int					ft_is_flag(char c, t_vals *lst);
int					ft_pourcent(t_vals *lst, char *str, int i, va_list va);
int					ft_convert(t_vals *lst, va_list va, char *result);
char				*ft_itoa_base(long int nbr, char *base, int preci);
int					ft_base_len(long int n, char *base);

#endif
