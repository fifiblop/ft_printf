/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 10:49:09 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/12 18:08:09 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_option(char c)
{
	if (c == '#' || c == '+' || c == '-' || c == ' ' || c == '0')
		return (1);
	return (0);
}

int		is_length_modifier(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (1);
	return (0);
}

int		is_type(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i' ||
		c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X' ||
		c == 'c' || c == 'C')
		return (1);
	return (0);
}

int		is_percent(char c)
{
	return (c == '%' ? 1 : 0);
}
