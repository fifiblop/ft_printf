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
#include <wchar.h>
#include <stdlib.h>

char	*get_mask(int len_bin)
{
	char	*tab[4];

	tab[0] = "0xxxxxxx";
	tab[1] = "110xxxxx10xxxxxx";
	tab[2] = "1110xxxx10xxxxxx10xxxxxx";
	tab[3] = "11110xxx10xxxxxx10xxxxxx10xxxxxx";
	if (len_bin < 8)
		return (ft_strdup(tab[0]));
	else if (len_bin < 12)
		return (ft_strdup(tab[1]));
	else if (len_bin < 17)
		return (ft_strdup(tab[2]));
	else
		return (ft_strdup(tab[3]));
}

void	print_wchar(char *mask)
{
	int		len_mask;

	len_mask = ft_strlen(mask);
	if (len_mask >= 8)
		ft_putchar(ft_atoi_base(ft_strsub(mask, 0, 8), "01"));
	if (len_mask >= 16)
		ft_putchar(ft_atoi_base(ft_strsub(mask, 8, 8), "01"));
	if (len_mask >= 24)
		ft_putchar(ft_atoi_base(ft_strsub(mask, 16, 8), "01"));
	if (len_mask >= 34)
		ft_putchar(ft_atoi_base(ft_strsub(mask, 24, 8), "01"));
}

void	ft_putwchar(wchar_t c)
{
	char	*bin_c;
	char	*mask;
	int		len_mask;
	int		len_bin;

	bin_c = ft_itoa_base((long long int)c, 2);
	len_bin = ft_strlen(bin_c) - 1;
	mask = get_mask(len_bin);
	len_mask = ft_strlen(mask) - 1;
	while (len_bin >= 0)
	{
		if (mask[len_mask] == 'x')
			mask[len_mask] = bin_c[len_bin--];
		else
			len_mask--;
	}
	len_mask = 0;
	while (mask[len_mask])
		if (mask[len_mask++] == 'x')
			mask[len_mask - 1] = '0';
	print_wchar(mask);
	free(mask);
}

int		ft_wcharlen(wchar_t c)
{
	int	len_bin;

	len_bin = ft_strlen(ft_itoa_base((long long int)c, 2));
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
