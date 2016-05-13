/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 17:45:20 by pdelefos          #+#    #+#             */
/*   Updated: 2016/04/28 17:46:04 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_base_number(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != c)
		i++;
	return (i);
}

static int	ft_strlenp(char *str)
{
	int	t;

	t = 1;
	while (str[t] != '-' && str[t] != '+' && str[t] != '\0')
		t++;
	if (str[0] == '-' || str[0] == '+')
		return (t - 1);
	else
		return (t);
}

static int	ft_check_base(char *base)
{
	int	t;
	int	w;

	w = 0;
	t = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[t])
	{
		w = t + 1;
		if (base[t] == '-' || base[t] == '+')
			return (0);
		if (base[t] <= '!' || base[t] >= '~')
			return (0);
		while (base[w])
		{
			if (base[t] == base[w])
				return (0);
			w++;
		}
		t++;
	}
	return (1);
}

static int	ft_check_str(char *str, char *base, int i)
{
	int	p;
	int	k;
	int	t;

	p = -1;
	k = 0;
	if (str[p + 1] == '\0')
		return (0);
	if (ft_check_base(base) != 0)
	{
		while (base[++p])
		{
			t = i - 1;
			while (str[++t] != '-' && str[t] && str[t] != '+')
			{
				if (str[t] == base[p] && str[t] != '-' && str[t] != '+')
					k++;
			}
		}
		if (k != ft_strlenp(str))
			return (0);
		return (1);
	}
	return (0);
}

int			ft_atoi_base(char *str, char *base)
{
	int	i;
	int	t;
	int	n;

	i = 0;
	t = 0;
	n = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
			|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	t = (str[i] == '-') ? 1 : 0;
	i = ((str[0] == '-') || (str[0] == '+')) ? i + 1 : i;
	if (ft_check_str(str, base, i))
	{
		while (str[i] != '\0' && str[i] != '+' && str[i] != '-')
		{
			n = n * (ft_strlenp(base));
			n = n + ft_find_base_number(str[i], base);
			i++;
		}
		return ((t == 1) ? -n : n);
	}
	return (0);
}
