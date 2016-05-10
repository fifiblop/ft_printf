/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 18:22:17 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/09 14:26:23 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include <stdlib.h>

int		is_type(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i' ||
		c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X' ||
		c == 'c' || c == 'C')
		return (1);
	return (0);
}

int		is_percent(char c)
{
	return (c == '%' ? 1 : 0);
}

t_opt	*parse_options(char *str_option)
{
	t_opt *opt;

	(void)str_option;
	opt = (t_opt*)ft_memalloc(sizeof(t_opt));
	return (opt);
}

int		parse_format(const char *restrict format, t_list **lst_opt)
{
	int		i;
	int		j;
	int		ret;
	char	*str_option;
	t_opt	*opt;

	i = 0;
	j = 0;
	ret = 0;
	while (format[i])	
	{
		if (format[i] == '%')
		{
			j = i + 1;
			while (!is_type(format[j]) && !is_percent(format[j]))	
				j++;
			str_option = ft_strsub(format, i, (j - i) + 1);
			opt = parse_options(str_option);
			ft_lst_pback(lst_opt, opt, sizeof(t_opt*));
			free(str_option);
			i = j;
		}
		i++;
	}
	return (ret);
}
