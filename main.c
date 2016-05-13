/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:13:19 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/13 10:47:24 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int		main(void)
{
	/*ft_putendl("-----options tests-----");*/
	/*ft_printf("je suis %+ 010.7ld lol %.3%", "fou");*/
	/*ft_printf("je suis %+ #10.7ld lol", "fou");*/
	/*ft_printf("je suis %+-10.7ld lol", "fou");*/
	/*ft_printf("je suis %+ 010.-7ld lol", "fou");*/
	/*ft_printf("je suis %010.7ld lol", "fou");*/
	/*ft_printf("je suis %10.7+ld lol", "fou");*/
	/*ft_putendl("-----minimum width tests-----");*/
	/*ft_printf("%.6d", 42);*/
	/*ft_printf("%7.6d", 42);*/
	/*ft_printf("%+0# 26d", 42);*/
	/*ft_printf("%+026d", 42);*/
	/*ft_printf("%+0# 26.-7565d", 42);*/
	/*ft_putendl("-----length modifier tests-----");*/
	/*ft_printf("%.6hd", 42);*/
	/*ft_printf("%7.6d", 42);*/
	/*ft_printf("%+0# ll26d", 42);*/
	/*ft_printf("%+026zd", 42);*/
	/*ft_printf("%+0# 26.-7565hhd", 42);*/
	/*ft_printf("%.3%", 42);*/
	/*ft_putendl("-----type tests-----");*/
	/*ft_printf("%.6hd", 42);*/
	/*ft_printf("%7.6c", 42);*/
	/*ft_printf("%+0# ll26p", 42);*/
	/*ft_printf("%+026zD", 42);*/
	/*ft_printf("%+0# 26.-7565hhi", 42);*/
	/*ft_printf("%.3%", 42);*/
	ft_putendl("-----char tests-----");
	ft_printf("top %c\n", 'c');
	ft_printf("top %+02.1c\n", 'c');
	ft_printf("top %010c\n", 'c');
	ft_printf("top %-02c\n", 'c');
	ft_printf("top %+0.1c\n", 'c');
	return (0);
}
