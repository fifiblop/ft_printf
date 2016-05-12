/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 10:50:54 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/12 18:08:57 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>

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

void	parse_accuracy(char *str_options, t_opt *opt)
{
	int	i;

	i = 0;
	while (str_options[i])
	{
		if (str_options[i] == '.')
		{
			opt->accu = TRUE;
			opt->accu_v = ft_atoi(&str_options[i + 1]);
			return ;
		}
		i++;
	}
}

void	parse_length_modifier(char *str_options, t_opt *opt)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (!is_length_modifier(str_options[i]) && str_options[i])
		i++;
	if (is_length_modifier(str_options[i]))
	{
		tmp = ft_strsub(str_options, i, 2);
		if (tmp[0] == 'h' && tmp[1] == 'h')
			opt->mod = hh;
		else if (tmp[0] == 'h' && tmp[1] != 'h')
			opt->mod = h;
		else if (tmp[0] == 'l' && tmp[1] == 'l')
			opt->mod = ll;
		else if (tmp[0] == 'l' && tmp[1] != 'l')
			opt->mod = l;
		else if (tmp[0] == 'j')
			opt->mod = j;
		else if (tmp[0] == 'z')
			opt->mod = z;
		free(tmp);
	}
}

void	parse_type(char *str_options, t_opt *opt)
{
	int	size;

	size = ft_strlen(str_options) - 1;
	if (is_type(str_options[size]) || is_percent(str_options[size]))
		opt->type = str_options[size];
}
