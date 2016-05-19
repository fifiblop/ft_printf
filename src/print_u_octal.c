/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_octal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 11:02:59 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/19 17:37:29 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>
#include <stdlib.h>

#include <stdio.h>
int		print_u_octal(t_opt *opt, va_list *args)
{
	unsigned long long	i;
	char				*str;
	int					size;

	i = set_length_modifier_u(opt, args);
	str = ft_itoa_base_ull(i, 8);
	str = add_acc_opt(opt, str, FALSE);
	size = ft_strlen(str);
	print_width_before_num(opt, opt->min_w - size, FALSE);
	/*ft_putstr(str);*/
	print_width_after(opt, opt->min_w - size);
	/*free(str);*/
	if (opt->min_w > size)
		return (opt->min_w);
	return (size);
	return (0);
}
