/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 18:21:49 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/09 14:35:38 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"

typedef enum	e_bool
{
	TRUE, FALSE
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

#endif
