/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_octal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 11:02:59 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/27 14:55:23 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>
#include <stdlib.h>

int		set_sharp(t_opt *opt, int size, long long i)
{
	if ((i != 0 && opt->hash) ||
		(opt->hash && opt->accu && opt->accu_v == 0 && i == 0))
	{
		write(1, "0", 1);
		if (opt->hash && opt->accu && opt->accu_v == 0 && i == 0)
			return (0);
		size++;
	}
	return (size);
}

int		print_u_octal(t_opt *opt, va_list *args)
{
	unsigned long long	i;
	char				*str;
	int					size;

	null_options_sconv(opt);
	i = set_length_modifier_u(opt, args);
	str = ft_itoa_base_ull(i, 8, LOWER);
	str = add_acc_opt(opt, str, FALSE);
	size = ft_strlen(str);
	print_width_before_num(opt, opt->min_w - size, FALSE);
	if (opt->accu && opt->accu_v >= size && opt->hash)
		opt->hash = FALSE;
	if ((size = set_sharp(opt, size, i)) == 0)
		return (1);
	if (null_accuracy(opt, str, i))
		return (0);
	ft_putstr(str);
	print_width_after(opt, opt->min_w - size);
	free(str);
	if (opt->min_w > size)
		return (opt->min_w);
	return (size);
}
