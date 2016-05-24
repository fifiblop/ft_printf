/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s_decimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 18:21:19 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/24 15:10:16 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>

int			print_s_decimal(t_opt *opt, va_list *args)
{
	long long	i;
	char		*str;
	int			size;
	t_bool		neg;

	i = set_length_modifier(opt, args);
	neg = (i < 0) ? TRUE : FALSE;
	str = ft_itoa_base_ll(i, 10);
	str = remove_minus(str);
	str = add_acc_opt(opt, str, neg);
	size = ft_strlen(str);
	print_width_before_num(opt, opt->min_w - size, neg);
	if (opt->accu && opt->accu_v == 0)
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
