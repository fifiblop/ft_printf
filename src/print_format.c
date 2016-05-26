/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 16:44:31 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/25 16:53:31 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>

int		print_arg(t_opt *opt, va_list *args)
{
	if (opt->type == '%')
		return (print_percent(opt));
	else if (opt->type == 's' && opt->mod != l)
		return (print_str(opt, args));
	else if (opt->type == 'S' || (opt->type == 's' && opt->mod == l))
		return (print_wstr(opt, args));
	else if (opt->type == 'p')
		return (print_ptr(opt, args));
	else if (opt->type == 'd' || opt->type == 'i')
		return (print_s_decimal(opt, args));
	else if (opt->type == 'o')
		return (print_u_octal(opt, args));
	return (print_arg2(opt, args));
}

int		print_arg2(t_opt *opt, va_list *args)
{
	if (opt->type == 'u')
		return (print_u_decimal(opt, args));
	else if (opt->type == 'x' || opt->type == 'X')
		return (print_u_hexa(opt, args));
	else if (opt->type == 'c' && opt->mod != l)
		return (print_c(opt, args));
	else if (opt->type == 'C' || (opt->type == 'c' && opt->mod == l))
		return (print_C(opt, args));
	return (0);
}

int		print_format(const char *format, t_list **lst_opt, va_list *args)
{
	int		i;
	int		ret;
	t_opt	*opt;
	t_list	*lst;

	i = 0;
	ret = 0;
	lst = *lst_opt;
	while (format[i])
	{
		if (format[i] == '%')
		{
			opt = lst->content;
			ret += print_arg(opt, args);
			lst = lst->next;
			i += ft_strlen(opt->opt_str) - 1;
		}
		else
			ret += write(1, &format[i], 1);
		i++;
	}
	return (ret);
}
