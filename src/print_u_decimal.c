/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_decimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 18:30:39 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/24 16:09:21 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>
#include <stdlib.h>

int		print_u_decimal(t_opt *opt, va_list *args)
{
	unsigned long long	i;
	char				*str;
	int					size;

	null_options_sconv(opt);
	i = set_length_modifier_u(opt, args);
	str = ft_itoa_base_ull(i, 10, LOWER);
	opt->space = FALSE;
	str = add_acc_opt(opt, str, FALSE);
	size = ft_strlen(str);
	print_width_before_num(opt, opt->min_w - size, FALSE);
	if (opt->accu && opt->accu_v == 0 && i == 0)
	{
		free(str);
		return (0);
	}
	ft_putstr(str);
	print_width_after(opt, opt->min_w - size);
	free(str);
	if (opt->min_w > size)
		return (opt->min_w);
	return (size);
}
