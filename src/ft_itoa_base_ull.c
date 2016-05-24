/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ull.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 19:14:34 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/24 15:08:29 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include <stdlib.h>

static unsigned long long	ft_nblen(unsigned long long n, int base)
{
	unsigned long long	len;

	len = 0;
	if (n == 0)
		return (1);
	else
	{
		while (n != 0)
		{
			n = n / base;
			len++;
		}
	}
	return (len);
}

static char					get_char_base(long long i, t_cap cap)
{
	if (cap == UPPER)
		return ("0123456789ABCDEF"[i]);
	else
		return ("0123456789abcdef"[i]);
}

char						*ft_itoa_base_ull(unsigned long long n, int base,
							t_cap cap)
{
	char				*str;
	char				*tmp;
	unsigned long long	len;

	if (base < 2 || base > 16)
		return (NULL);
	len = ft_nblen(n, base);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	tmp = str;
	if (str)
	{
		str = str + len;
		*str = '\0';
		if (n == 0)
			*--str = '0';
		while (n != 0)
		{
			*--str = get_char_base(n % base, cap);
			n = n / base;
		}
	}
	return (tmp);
}
