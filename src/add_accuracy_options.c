/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_accuracy_options.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 18:17:09 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/19 13:32:59 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>

char		*putchar_before_str(char *str, char c)
{
	char	*tmp;
	int		size;
	int		i;
	int		j;

	size = ft_strlen(str) + 1;
	if (!(tmp = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	j = 0;
	tmp[i++] = c;
	while (str[j])
		tmp[i++] = str[j++];
	tmp[i] = '\0';
	free(str);
	return (tmp);
}

char		*remove_minus(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	if (str[i] == '-')
	{
		if (!(tmp = (char*)malloc(sizeof(char) * ft_strlen(str))))
			return (NULL);
		i++;
		j = 0;
		while (str[i])
			tmp[j++] = str[i++];
		tmp[j] = '\0';
		free(str);
		return (tmp);
	}
	else
		return (str);
}

char		*put_options(t_opt *opt, char *str, int neg)
{
	if (opt->plus && !neg)
		str = putchar_before_str(str, '+');
	else if (neg)
		str = putchar_before_str(str, '-');
	else if (opt->space)
		str = putchar_before_str(str, ' ');
	return (str);
}

char		*add_acc_opt(t_opt *opt, char *str, int neg)
{
	int		accu;
	int		size;

	if (opt->accu)
	{
		accu = ft_abs(opt->accu_v) - ft_strlen(str);
		if (accu > 0)
		{
			while (accu--)
				str = putchar_before_str(str, '0');
		}
	}
	size = ft_strlen(str);
	if (!opt->zero || opt->min_w < size)
		str = put_options(opt, str, neg);
	return (str);
}
