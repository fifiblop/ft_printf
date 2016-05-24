/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 18:15:22 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/24 18:57:25 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>
#include <stdlib.h>

static char	*add_0x(char *str, long long i)
{
	if (i >= 0)
	{
		str = putchar_before_str(str, 'x');
		str = putchar_before_str(str, '0');
	}
	return (str);
}

int			print_ptr(t_opt *opt, va_list *args)
{
	unsigned long long	i;
	char				*str;
	int					size;

	null_options_sconv(opt);
	i = (long long)va_arg(*args, void*);
	str = ft_itoa_base_ull(i, 16, LOWER);
	str = add_acc_opt(opt, str, FALSE);
	str = add_0x(str, i);
	if (opt->accu && opt->accu_v == 0)
	{
		free(str);
		str = ft_strdup("0x");
	}
	size = ft_strlen(str);
	print_width_before_num(opt, opt->min_w - size, FALSE);
	ft_putstr(str);
	print_width_after(opt, opt->min_w - size);
	free(str);
	if (opt->min_w > size)
		return (opt->min_w);
	return (size);
}
