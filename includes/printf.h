/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 18:21:49 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/10 18:46:50 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"

typedef enum	e_bool
{
	TRUE = 1, FALSE = 0
}				t_bool;

typedef	enum	e_mod
{
	hh, h, ll, l, j, z
}				t_mod;

typedef	enum	e_type
{
	s, S, p, d, D, i, o, O, u, U, x, X, c, C
}				t_type;

typedef struct	s_opt
{
	char		*str;
	t_bool		hash;
	t_bool		zero;
	t_bool		plus;
	t_bool		minus;
	t_bool		space;
	int			min_w;
	int			accu;
	t_mod		mod;
	t_type		type;
	t_bool		perc;
}				t_opt;

int		ft_printf(const char *restrict format, ...);
int		parse_format(const char *restrict format, t_list **lst_opt);

void	parse_option(char *str_options, t_opt *opt);
void	parse_min_width(char *str_options, t_opt *opt);

int		is_option(char c);
int		is_type(char c);
int		is_percent(char c);

#endif
