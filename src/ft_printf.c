/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 18:09:14 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/09 14:41:00 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include <stdarg.h>
#include <stdlib.h>

void	print_bool(t_bool bool)
{
	if (bool == TRUE)
		ft_putstr("true");
	else
		ft_putstr("false");
}

void	print_opt(t_opt *opt)
{
	ft_putstr("-> hash : ");
	print_bool(opt->hash);
	ft_putstr("| zero : ");
	print_bool(opt->zero);
	ft_putstr("| plus : ");
	print_bool(opt->plus);
	ft_putstr("| minus : ");
	print_bool(opt->minus);
	ft_putstr("| space : ");
	print_bool(opt->space);
	ft_putnl();
	ft_putstr("| min_width : ");
	ft_putstr("| accuracy : ");
	ft_putstr("| modifier : ");
	ft_putstr("| type : ");
	ft_putstr("| percent : ");
	print_bool(opt->perc);
	ft_putnl();
}

int		ft_printf(const char *restrict format, ...)
{
	va_list	args;
	t_list	*lst_opt;
	t_opt	*opt;

	va_start(args, format);
	lst_opt = NULL;
	parse_format(format, &lst_opt);
	while (lst_opt)
	{
		opt = lst_opt->content;
		print_opt(opt);
		free(lst_opt->content);
		lst_opt = lst_opt->next;
	}
	va_end(args);
	return (0);
}
