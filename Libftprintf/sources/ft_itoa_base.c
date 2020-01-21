/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 15:33:29 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 23:50:38 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_base_len(long int n, char *base)
{
	int i;
	int intbase;

	if (n < 0)
		return (ft_base_len(n + 4294967296, base));
	i = 0;
	intbase = 0;
	while (base[intbase] != '\0')
		intbase++;
	while (n >= intbase)
	{
		i++;
		n /= intbase;
	}
	i++;
	return (i);
}

char	*ft_print_base(long int nbr, int *based, int len, char *base)
{
	int			i;
	int			size;
	char		*str;

	i = 0;
	size = ft_base_len(nbr, base);
	if (!(str = ft_calloc(len + 1, sizeof(char))))
		return (0);
	while (len - size)
	{
		str[i++] = '0';
		len--;
	}
	size--;
	while (size >= 0)
	{
		str[i] = base[based[size]];
		size--;
		i++;
	}
	free(based);
	return (str);
}

char	*ft_itoa_base(long int nbr, char *base, int preci)
{
	long int	intbase;
	long int	nb;
	int			i;
	int			*based;
	int			len;

	if (preci == 0 && nbr == 0)
		return (ft_strdup("\0"));
	if (nbr < 0)
		return (ft_itoa_base(nbr - 4294967296, base, preci));
	i = 0;
	nb = nbr;
	intbase = ft_strlen(base);
	if (!(based = ft_calloc(ft_base_len(nbr, base), sizeof(int))))
		return (0);
	preci > ft_base_len(nbr, base) ? (len = preci) :
		(len = ft_base_len(nbr, base));
	while (nb >= intbase)
	{
		based[i++] = nb % intbase;
		nb /= intbase;
	}
	based[i] = nb % intbase;
	return (ft_print_base(nbr, based, len, base));
}
