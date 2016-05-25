/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 14:53:13 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/25 12:13:00 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_bool(t_bool bool)
{
	if (bool == TRUE)
		ft_putstr("true");
	else
		ft_putstr("false");
}

void	print_mod(t_mod mod)
{
	if (mod == hh)
		ft_putstr("hh");
	if (mod == h)
		ft_putstr("h");
	if (mod == ll)
		ft_putstr("ll");
	if (mod == l)
		ft_putstr("l");
	if (mod == j)
		ft_putstr("j");
	if (mod == z)
		ft_putstr("z");
	if (mod == no_m)
		ft_putstr("no_m");
}

void	print_opt(t_opt *opt)
{
	ft_putstr(opt->opt_str);
	ft_putstr(" -> hash : ");
	print_bool(opt->hash);
	ft_putstr(" | zero : ");
	print_bool(opt->zero);
	ft_putstr(" | plus : ");
	print_bool(opt->plus);
	ft_putstr(" | minus : ");
	print_bool(opt->minus);
	ft_putstr(" | space : ");
	print_bool(opt->space);
	ft_putnl();
	ft_putstr("     -> min_width : ");
	ft_putnbr(opt->min_w);
	ft_putstr(" | accuracy : ");
	print_bool(opt->accu);
	ft_putstr(", ");
	ft_putnbr(opt->accu_v);
	ft_putstr(" | modifier : ");
	print_mod(opt->mod);
	ft_putstr(" | type : ");
	ft_putchar(opt->type);
	ft_putnl();
}
