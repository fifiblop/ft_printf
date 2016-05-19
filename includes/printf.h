/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 18:21:49 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/19 11:05:13 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef enum		e_bool
{
	TRUE = 1, FALSE = 0
}					t_bool;

typedef	enum		e_mod
{
	hh, h, ll, l, j, z, no_m
}					t_mod;

typedef struct		s_opt
{
	char			*str;
	t_bool			hash;
	t_bool			zero;
	t_bool			plus;
	t_bool			minus;
	t_bool			space;
	int				min_w;
	t_bool			accu;
	int				accu_v;
	t_mod			mod;
	char			type;
}					t_opt;

int					ft_printf(const char *restrict format, ...);
int					parse_format(const char *restrict format, t_list **lst_opt);

void				parse_option(char *str_options, t_opt *opt);
void				parse_min_width(char *str_options, t_opt *opt);
void				parse_accuracy(char *str_options, t_opt *opt);
void				parse_length_modifier(char *str_options, t_opt *opt);
void				parse_type(char *str_options, t_opt *opt);

int					print_format(const char *format, t_list **lst_opt,
					va_list *args);
int					print_arg(t_opt *opt, va_list *args);
int					print_arg2(t_opt *opt, va_list *args);

int					print_c(t_opt *opt, va_list *args);
int					print_str(t_opt *opt, va_list *args);
int					print_s_decimal(t_opt *opt, va_list *args);
int					print_u_decimal(t_opt *opt, va_list *args);
int					print_u_octal(t_opt *opt, va_list *args);

int					is_option(char c);
int					is_length_modifier(char c);
int					is_type(char c);
int					is_percent(char c);

void				print_bool(t_bool bool);
void				print_mod(t_mod mod);
void				print_opt(t_opt *opt);

void				ft_putnchar(char c, int n);
char				*putchar_before_str(char *str, char c);
char				*remove_minus(char *str);
char				*add_acc_opt(t_opt *opt, char *str, int neg);
void				print_width_before(t_opt *opt, int size);
void				print_width_after(t_opt *opt, int size);
void				print_width_before_num(t_opt *opt, int size, t_bool neg);
long long			set_length_modifier(t_opt *opt, va_list *args);
unsigned long long	set_length_modifier_u(t_opt *opt, va_list *args);

char				*ft_itoa_base_ll(long long n, int base);
char				*ft_itoa_base_ull(unsigned long long n, int base);
#endif
