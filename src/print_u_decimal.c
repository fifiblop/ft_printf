/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_decimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 18:30:39 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/13 19:28:14 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>
#include <stdlib.h>

int					print_u_decimal(t_opt *opt, va_list *args)
{
	unsigned long long	i;
	char				*str;

	i = set_length_modifier_u(opt, args);
	str = ft_itoa_base_ull(i, 10);
	ft_putstr(str);
	free(str);
	return (0);
}
