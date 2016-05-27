/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 17:00:43 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/27 19:01:11 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>

void	ft_putnstr(char *str, int n)
{
	int i;

	i = 0;
	while (i < n && str[i])
		write(1, &str[i++], 1);
}

int		print_str(t_opt *opt, va_list *args)
{
	char	*str;
	int		size;

	if ((str = va_arg(*args, char*)) == NULL)
		str = "(null)";
	size = ft_strlen(str);
	if (opt->accu && opt->accu_v < size)
		size = opt->accu_v;
	print_width_before(opt, opt->min_w - size);
	ft_putnstr(str, size);
	print_width_after(opt, opt->min_w - size);
	if (opt->min_w > size)
		return (opt->min_w);
	return (size);
}
