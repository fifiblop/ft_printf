/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 10:50:54 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/10 18:54:44 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	parse_option(char *str_options, t_opt *opt)
{
	int	i;

	i = 1;
	while (str_options[i])
	{
		if (str_options[i] == '#')
			opt->hash = TRUE;
		else if (str_options[i] == '+')
			opt->plus = TRUE;
		else if (str_options[i] == '-')
			opt->minus = TRUE;
		else if (str_options[i] == ' ')
			opt->space = TRUE;
		else if (str_options[i] == '0' && !ft_isdigit(str_options[i - 1]) &&
				str_options[i - 1] != '.')
			opt->zero = TRUE;
		i++;
	}
}

void	parse_min_width(char *str_options, t_opt *opt)
{
	int	i;

	i = 1;
	while (is_option(str_options[i]))
		i++;
	if (str_options[i] == '.')
		opt->min_w = 0;
	else
		opt->min_w = ft_atoi(&str_options[i]);
}
