/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 18:22:17 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/10 18:48:44 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include <stdlib.h>

void	init_opt(t_opt *opt)
{
	opt->hash = FALSE;
	opt->zero = FALSE;
	opt->plus = FALSE;
	opt->minus = FALSE;
	opt->space = FALSE;
	opt->perc = FALSE;
}

t_opt	get_options(char *str_option)
{
	t_opt opt;

	init_opt(&opt);
	opt.str = ft_strdup(str_option);
	parse_option(str_option, &opt);
	return (opt);
}

int		parse_format(const char *restrict format, t_list **lst_opt)
{
	int		i;
	int		j;
	int		ret;
	char	*str_option;
	t_opt	opt;

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
			opt = get_options(str_option);
			ft_lst_pback(lst_opt, &opt, sizeof(t_opt));
			free(str_option);
			i = j;
		}
		i++;
	}
	return (ret);
}
