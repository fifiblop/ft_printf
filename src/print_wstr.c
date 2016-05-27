/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 13:42:16 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/27 15:02:18 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_putnwstr(wchar_t *str, int n)
{
	int	ret;
	int	size;
	int	i;
	int	nb;

	ret = 0;
	i = 0;
	nb = n;
	while (ret <= nb)
	{
		size = ft_wcharlen(str[i]);
		if (size <= n)
		{
			ret += size;
			ft_putwchar(str[i++]);
			n -= size;
		}
		else
			break ;
	}
	return (ret);
}

int		get_realsize(wchar_t *str, int nb)
{
	int	i;
	int	j;
	int size;

	i = nb;
	j = 0;
	while (str[j])
	{
		size = ft_wcharlen(str[j++]);
		if (size <= i)
			i -= size;
		else
			break ;
	}
	return (nb - i);
}

int		print_wstr(t_opt *opt, va_list *args)
{
	wchar_t	*str;
	int		size;

	if ((str = va_arg(*args, wchar_t*)) == NULL)
		str = L"(null)";
	size = ft_wstrlen(str);
	if (opt->accu && opt->accu_v < size)
		size = get_realsize(str, opt->accu_v);
	print_width_before(opt, opt->min_w - size);
	size = ft_putnwstr(str, size);
	print_width_after(opt, opt->min_w - size);
	if (opt->min_w > size)
		return (opt->min_w);
	return (size);
}
