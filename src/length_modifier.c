/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_modifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 19:27:29 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/16 18:32:38 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

long long			set_length_modifier(t_opt *opt, va_list *args)
{
	long long i;

	if (opt->mod == hh)
		i = (char)va_arg(*args, long long);
	else if (opt->mod == h)
		i = (short)va_arg(*args, long long);
	else if (opt->mod == l)
		i = (long)va_arg(*args, long long);
	else if (opt->mod == no_m)
		i = (int)va_arg(*args, int);
	else
		i = (long long)va_arg(*args, long long);
	return (i);
}

unsigned long long	set_length_modifier_u(t_opt *opt, va_list *args)
{
	unsigned long long i;

	if (opt->mod == hh)
		i = (unsigned char)va_arg(*args, unsigned long long);
	else if (opt->mod == h)
		i = (unsigned short)va_arg(*args, unsigned long long);
	else if (opt->mod == l)
		i = (unsigned long)va_arg(*args, unsigned long long);
	else
		i = (unsigned long long)va_arg(*args, unsigned long long);
	return (i);
}
