/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ull.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 19:14:34 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/19 17:39:37 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

static unsigned long long	ft_nblen(unsigned long long n)
{
	unsigned long long	len;

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

char						*ft_itoa_base_ull(unsigned long long n, int base)
{
	char				*str;
	char				*tmp;
	unsigned long long	len;

	if (base < 2 || base > 16)
		return (NULL);
	len = ft_nblen(n);
	printf("%llo\n", n);
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
			*--str = "0123456789ABCDEF"[n % base];
			n = n / base;
		}
	}
	return (tmp);
}
