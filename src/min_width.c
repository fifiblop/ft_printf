/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 13:38:59 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/18 18:15:40 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		print_width_before(t_opt *opt, int size)
{
	if (size > 0 && !opt->minus && !opt->zero)
		ft_putnchar(' ', size);
	else if (size > 0 && !opt->minus && opt->zero)
		ft_putnchar('0', size);
}

void		print_width_after(t_opt *opt, int size)
{
	if (size > 0 && opt->minus)
		ft_putnchar(' ', size);
}

static int	options_min_w(t_opt *opt, int size, t_bool neg)
{
	if (!neg && opt->plus)
	{
		ft_putchar('+');
		size--;
	}
	else if (neg)
	{
		ft_putchar('-');
		size--;
	}
	else if (opt->space)
	{
		ft_putchar(' ');
		size--;
	}
	return (size);
}

void		print_width_before_num(t_opt *opt, int size, t_bool neg)
{
	if (size > 0 && !opt->minus && opt->zero && !opt->accu)
	{
		size = options_min_w(opt, size, neg);
		ft_putnchar('0', size);
	}
	else if (size > 0 && !opt->minus)
		ft_putnchar(' ', size);
}
