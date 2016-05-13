/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 18:45:55 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/13 10:41:20 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>
#include <wchar.h>

void	ft_putnchar(char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, &c, 1);
		i++;
	}
}

void	print_width_before(t_opt *opt, int size)
{
	if (size > 0 && !opt->minus && !opt->zero)
		ft_putnchar(' ', size);
	else if (size > 0 && !opt->minus && opt->zero)
		ft_putnchar('0', size);
}

void	print_width_after(t_opt *opt, int size)
{
	if (size > 0 && opt->minus)
		ft_putnchar(' ', size);
}

int		print_c(t_opt *opt, va_list *args)
{
	unsigned char c;

	c = va_arg(*args, int);
	print_width_before(opt, opt->min_w - 1);
	write(1, &c, 1);
	print_width_after(opt, opt->min_w - 1);
	if (opt->min_w > 0)
		return (opt->min_w);
	else
		return (1);
}

/*int		print_C(t_opt *opt, va_list *args)*/
/*{*/
	/*wchar_t c;*/

	/*c = va_arg(*args, wint_t);*/
/*}*/
