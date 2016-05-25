/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 12:19:20 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/25 12:21:30 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_percent(t_opt *opt)
{
	print_width_before(opt, opt->min_w - 1);
	write(1, "%", 1);
	print_width_after(opt, opt->min_w - 1);
	if (opt->min_w > 1)
		return (opt->min_w);
	return (1);
}
