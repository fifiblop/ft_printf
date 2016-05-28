/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 18:15:22 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/28 12:34:26 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>
#include <stdlib.h>

static char	*add_0x(char *str, t_opt *opt, long long i)
{
	int	size;

	size = ft_strlen(str);
	if ((i > 0 && (!opt->zero && !opt->accu && opt->min_w < size))
		|| (i >= 0 && opt->min_w > size && !opt->zero) || (i > 0 && opt->minus)
		|| (i >= 0 && opt->min_w < size && opt->accu_v < size))
	{
		str = putchar_before_str(str, 'x');
		str = putchar_before_str(str, '0');
	}
	else if ((i == 0 && opt->accu && opt->accu_v > 0)
		|| (i >= 0 && ((opt->accu && opt->accu_v > 0) || opt->min_w > size)))
	{
		write(1, "0x", 2);
	}
	if ((opt->accu && opt->accu_v == 0 && i == 0))
	{
		free(str);
		str = ft_strdup("0x");
	}
	return (str);
}

int			get_size_ptr(t_opt *opt, int size)
{
	if (opt->accu && opt->accu_v > 0 && opt->min_w < opt->accu_v)
		size += 2;
	else if ((opt->accu && opt->accu_v > size)
			|| (opt->zero && opt->min_w > size))
		size += 2;
	return (size);
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
	str = add_0x(str, opt, i);
	size = ft_strlen(str);
	size = get_size_ptr(opt, size);
	print_width_before_num(opt, opt->min_w - size, FALSE);
	ft_putstr(str);
	print_width_after(opt, opt->min_w - size);
	free(str);
	if (opt->min_w > size)
		return (opt->min_w);
	return (size);
}
