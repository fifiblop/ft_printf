/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 18:45:55 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/13 17:15:10 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>
#include <wchar.h>

int		print_c(t_opt *opt, va_list *args)
{
	unsigned char c;

	c = va_arg(*args, int);
	print_width_before(opt, opt->min_w - 1);
	write(1, &c, 1);
	print_width_after(opt, opt->min_w - 1);
	if (opt->min_w > 0)
		return (opt->min_w);
	return (1);
}
