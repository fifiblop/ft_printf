/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 14:48:13 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/24 19:07:56 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>
#include <stdlib.h>

static int	add_sharp(t_opt *opt, int i, int size)
{
	if (i != 0 && opt->hash && opt->type == 'x')
	{
		write(1, "0x", 2);
		size += 2;
	}
	if (i != 0 && opt->hash && opt->type == 'X')
	{
		write(1, "0X", 2);
		size += 2;
	}
	return (size);
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
	str = add_acc_opt(opt, str, FALSE);
	size = ft_strlen(str);
	print_width_before_num(opt, opt->min_w - size, FALSE);
	size = add_sharp(opt, i, size);
	ft_putstr(str);
	print_width_after(opt, opt->min_w - size);
	free(str);
	if (opt->min_w > size)
		return (opt->min_w);
	return (size);
}
