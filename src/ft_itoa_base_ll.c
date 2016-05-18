/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ll.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 19:15:00 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/16 17:06:21 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static long long	ft_nblen(long long n)
{
	long long		len;

	len = 0;
	if (n == 0)
		return (1);
	else
	{
		while (n != 0)
		{
			n = n / 10;
			len++;
		}
	}
	return (len);
}

static long long	ft_absll(long long n)
{
	return (n < 0 ? -n : n);
}

char				*ft_itoa_base_ll(long long n, int base)
{
	char			*str;
	long long		len;
	int				sign;

	if (base < 2 || base > 16)
		return (NULL);
	len = ft_nblen(n);
	sign = (n < 0) ? 1 : 0;
	str = NULL;
	str = (char*)malloc(sizeof(char) * (len + sign + 1));
	if (str)
	{
		str = str + len + sign;
		*str = '\0';
		if (n == 0)
			*--str = '0';
		while (n != 0)
		{
			*--str = "0123456789ABCDEF"[ft_absll(n % base)];
			n = n / base;
		}
		if (sign)
			*--str = '-';
	}
	return (str);
}
