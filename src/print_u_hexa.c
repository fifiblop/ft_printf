/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 14:48:13 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/28 13:09:25 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>
#include <stdlib.h>

char		*add_sharp(t_opt *opt, int i, char *str, int size)
{
	if ((i != 0 && opt->hash && opt->type == 'x' &&
		!opt->zero && (opt->min_w > size || (opt->accu && opt->accu_v > size)))
		|| ((i > 0 || i != 0) && !opt->zero && !opt->accu && opt->min_w < size
			&& opt->hash && opt->type == 'x'))
	{
		str = putchar_before_str(str, 'x');
		str = putchar_before_str(str, '0');
	}
	else if (i != 0 && opt->hash && opt->type == 'X')
	{
		str = putchar_before_str(str, 'X');
		str = putchar_before_str(str, '0');
	}
	else if (opt->hash && opt->zero && (opt->accu || opt->min_w > size))
	{
		if (opt->type == 'X')
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
	}
	return (str);
}

void		null_options_sconv(t_opt *opt)
{
	opt->plus = FALSE;
	opt->space = FALSE;
}

int			null_accuracy(t_opt *opt, char *str, long long i)
{
	if (opt->accu && opt->accu_v == 0 && i == 0)
	{
		free(str);
		return (1);
	}
	return (0);
}

int			print_u_hexa(t_opt *opt, va_list *args)
{
	unsigned long long	i;
	char				*str;
	int					size;

	null_options_sconv(opt);
	i = set_length_modifier_u(opt, args);
	if (opt->type == 'x')
		str = ft_itoa_base_ull(i, 16, LOWER);
	else
		str = ft_itoa_base_ull(i, 16, UPPER);
	if (null_accuracy(opt, str, i))
		return (0);
	size = ft_strlen(str);
	str = add_acc_opt(opt, str, FALSE);
	add_sharp(opt, i, str, size);
	size = ft_strlen(str);
	if (opt->hash && opt->zero && (opt->accu || opt->min_w > size))
		size += 2;
	print_width_before_num(opt, opt->min_w - size, FALSE);
	ft_putstr(str);
	print_width_after(opt, opt->min_w - size);
	free(str);
	if (opt->min_w > size)
		return (opt->min_w);
	return (size);
}
