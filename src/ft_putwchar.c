/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 14:22:47 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/25 19:03:24 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include <wchar.h>
#include <stdlib.h>

int		ft_wcharlen(wchar_t c)
{
		int		len_bin;
		char	*tmp;

		tmp = ft_itoa_base_ll((long long)c, 2);
		len_bin = ft_strlen(tmp);
		free(tmp);
		if (len_bin < 8)
				return (1);
		else if (len_bin < 12)
				return (2);
		else if (len_bin < 17)
				return (3);
		else
				return (4);
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

int		ft_putwchar(wchar_t c)
{
		int					i;
		unsigned long int	tmp;
		unsigned char		mask;
		unsigned char		tab[4];

		if ((mask = 127u) && c <= 0x7F)
		{
				ft_putchar((char)c);
				return (1);
		}
		if (!(i = 0) && c > 0x10FFFF)
				return (-1);
		while (c)
		{
				tmp = 63u & c;
				c = c >> 6;
				if (c)
						tab[i++] = tmp | 128u;
				else if ((mask = mask >> i))
						tab[i] = (tmp | (~mask)) & (~(64u >> i));
		}
		mask = (unsigned char)i + 1;
		while (i + 1 > 0)
				ft_putchar(tab[i--]);
		return (mask);
}
