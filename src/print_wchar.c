/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 16:02:48 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/27 15:01:20 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <wchar.h>

int		print_wchar(t_opt *opt, va_list *args)
{
	wchar_t c;
	int		size;

	c = va_arg(*args, wint_t);
	size = ft_wcharlen(c);
	print_width_before(opt, opt->min_w - 1);
	ft_putwchar(c);
	print_width_after(opt, opt->min_w - 1);
	if (opt->min_w > 0)
		return (opt->min_w);
	return (size);
}
