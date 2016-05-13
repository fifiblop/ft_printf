/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 16:44:31 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/13 10:05:23 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>

int		print_arg(t_opt *opt, va_list *args)
{
	if (opt->type == '%')
		return (write(1, "%", 1));
	else if (opt->type == 's')
		return (0);
	else if (opt->type == 'S')
		return (0);
	else if (opt->type == 'p')
		return (0);
	else if (opt->type == 'd' || opt->type == 'i')
		return (0);
	else if (opt->type == 'D')
		return (0);
	else if (opt->type == 'o')
		return (0);
	return (print_arg2(opt, args));
}

int		print_arg2(t_opt *opt, va_list *args)
{
	(void)args;
	if (opt->type == 'O')
		return (0);
	else if (opt->type == 'u')
		return (0);
	else if (opt->type == 'U')
		return (0);
	else if (opt->type == 'x' || opt->type == 'X')
		return (0);
	else if (opt->type == 'c' && opt->mod != l)
		return (print_c(opt, args));
	else if (opt->type == 'C' && (opt->type == 'c' && opt->mod == l))
		return (0);
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
			i += ft_strlen(opt->str) - 1;
		}
		else
			ret += write(1, &format[i], 1);
		i++;
	}
	return (ret);
}
