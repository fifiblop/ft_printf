/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 13:38:59 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/13 13:40:23 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
