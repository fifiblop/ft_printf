/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s_decimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 18:21:19 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/13 19:30:38 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>
#include <stdlib.h>

int			print_s_decimal(t_opt *opt, va_list *args)
{
	long long	i;
	char		*str;
	int			size;

	i = set_length_modifier(opt, args);
	str = ft_itoa_base_ll(i, 10);
	size = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (0);
}
