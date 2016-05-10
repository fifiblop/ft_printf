/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:13:19 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/10 18:46:16 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		main(void)
{
	ft_printf("je suis %+ 010.7ld lol", "fou");
	ft_printf("je suis %+ #10.7ld lol", "fou");
	ft_printf("je suis %+-10.7ld lol", "fou");
	ft_printf("je suis %+ 010.-7ld lol", "fou");
	ft_printf("je suis %010.7ld lol", "fou");
	ft_printf("je suis %10.7+ld lol", "fou");
	return (0);
}
