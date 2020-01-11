/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/08 15:41:40 by jdesbord     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/20 04:38:25 by jdesbord    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_power2(int *intstr, int j, int sizebase)
{
	int maxj;
	int power;
	int i;
	int answer;

	answer = 0;
	power = 1;
	j--;
	maxj = j;
	while (j >= 0)
	{
		i = maxj;
		while (i > j)
		{
			power *= sizebase;
			i--;
		}
		answer += intstr[j] * power;
		j--;
		power = 1;
	}
	return (answer);
}

int		ft_check_base(char c, char *base)
{
	int i;

	i = 0;
	while (c != base[i] && base[i] != '\0')
	{
		i++;
	}
	if (c == '\t' || c == '\n' || c == '\f' || c == '\v'
			|| c == '\r' || c == ' ')
		return (-3);
	else if (c == '-' || c == '+')
		return (-2);
	else if (base[i] == '\0')
		return (-1);
	else
		return (i);
}

int		ft_atoi_base_check(char *str, char *base, int sizebase, int *intstr)
{
	int sign;
	int i;
	int j;

	sign = 1;
	i = 0;
	while (str[i] != '\0' && ft_check_base(str[i], base) == -3)
		i++;
	while (str[i] != '\0' && ft_check_base(str[i], base) == -2)
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	j = 0;
	while (str[i] != '\0' && ft_check_base(str[i], base) >= 0)
	{
		intstr[j] = ft_check_base(str[i], base);
		i++;
		j++;
	}
	return (ft_power2(intstr, j, sizebase) * sign);
}

int		ft_check_forbidden(char c)
{
	if (c == '\t' || c == '\n' || c == '\f' || c == '\v'
			|| c == '\r' || c == ' ' || c == '+' || c == '-')
		return (1);
	return (0);
}

int		ft_atoi_base(char *str, char *base)
{
	int		i;
	int		intstr[128];
	int		sizebase;

	sizebase = 0;
	while (base[sizebase] != '\0')
	{
		i = 0;
		while (i < sizebase)
		{
			if (base[sizebase] == base[i]
					|| ft_check_forbidden(base[sizebase]) == 1)
				return (0);
			i++;
		}
		sizebase++;
	}
	if (sizebase <= 1)
		return (0);
	return (ft_atoi_base_check(str, base, sizebase, intstr));
}
