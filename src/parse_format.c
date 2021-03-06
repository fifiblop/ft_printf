/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 18:22:17 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/25 12:12:02 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include <stdlib.h>

void			init_opt(t_opt *opt)
{
	opt->hash = FALSE;
	opt->zero = FALSE;
	opt->plus = FALSE;
	opt->minus = FALSE;
	opt->space = FALSE;
	opt->min_w = 0;
	opt->accu = FALSE;
	opt->accu_v = 0;
	opt->mod = no_m;
	opt->type = '0';
}

void			set_longtype(t_opt *opt)
{
	if (opt->type == 'D' || opt->type == 'O' || opt->type == 'U')
	{
		if (ft_isupper(opt->type))
		{
			opt->mod = l;
			opt->type = ft_tolower(opt->type);
		}
	}
}

static t_opt	get_options(const char *format, int start, int size)
{
	t_opt	opt;
	char	*str_option;

	init_opt(&opt);
	str_option = ft_strsub(format, start, (size - start) + 1);
	opt.opt_str = ft_strdup(str_option);
	parse_option(str_option, &opt);
	parse_min_width(str_option, &opt);
	parse_accuracy(str_option, &opt);
	parse_length_modifier(str_option, &opt);
	parse_type(str_option, &opt);
	set_longtype(&opt);
	free(str_option);
	return (opt);
}

int				parse_format(const char *format, t_list **lst_opt)
{
	int		i;
	int		j;
	int		ret;
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
			opt = get_options(format, i, j);
			ft_lst_pback(lst_opt, &opt, sizeof(t_opt));
			i = j;
		}
		i++;
	}
	return (ret);
}
