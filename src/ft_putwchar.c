/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 14:22:47 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/27 15:00:12 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include <wchar.h>
#include <stdlib.h>

int		ft_wcharlen(wchar_t c)
{
	int			len;

	len = 0;
	if (c <= 0x7F)
		len++;
	else if (c > 0x10FFFF)
		return (-1);
	else
		while (c && ++len > 0)
			c = c >> 6;
	return (len);
}

int		ft_wstrlen(wchar_t *str)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
		size += ft_wcharlen(str[i++]);
	return (size);
}

int		ft_putwchar(wint_t x)
{
	size_t	j;
	char	c[4];
	wint_t	tmp;

	j = 1;
	if (x <= 0x7F)
		return (write(1, &x, 1));
	if (x > 0x1FFFFF)
		return (-1);
	while (1)
	{
		tmp = 63u & x;
		if (!(x >>= 6))
			break ;
		c[4 - j++] = 128u | tmp;
	}
	c[4 - j] = (-128 >> (j - 1)) | tmp;
	return (write(1, &(c[4 - j]), j));
}
