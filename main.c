/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:13:19 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/18 18:59:43 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
#include <locale.h>

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
	/*ft_putendl("-----char tests-----");*/
	/*ft_printf("top |%c|\n", 'c');*/
	/*ft_printf("top |%+02.1c|\n", 'c');*/
	/*ft_printf("top |%010c|\n", 'c');*/
	/*ft_printf("top |%-02c|\n", 'c');*/
	/*ft_printf("top |%+0.1c|\n", 'c');*/
	/*ft_putendl("-----int tests-----");*/
	/*ft_printf("%hd\n", 327677);*/
	/*printf("%hd\n", 327677);*/
	/*ft_printf("%lld\n", 128);*/
	/*printf("%llD\n", 128);*/
	/*ft_printf("%-12#.-17c", 42);*/
	/*printf("%d\n", ft_printf("%hhu\n", 255));*/
	/*printf("%d\n", printf("%hhu\n", 255));*/
	/*ft_printf("%d", 42);*/
	/*ft_printf("%010.4d\n", -42);*/
	/*printf("%010.4d\n", -42);*/
	/*ft_printf("%10.4d\n", -42);*/
	/*printf("%10.4d\n", -42);*/
	/*ft_printf("%0.4d\n", -42);*/
	/*printf("%0.4d\n", -42);*/
	/*ft_printf("%10d\n", 42);*/
	/*printf("%10d\n", 42);*/
	/*printf("----- +d : 42 -----\n");*/
	/*ft_printf("%+d\n", 42);*/
	/*printf("%+d\n", 42);*/
	printf("----- .2d : -1 -----\n");
	ft_printf("%.2d\n", -1);
	printf("%.2d\n", -1);
	printf("----- +5.2d : 1 -----\n");
	ft_printf("%+5.2d\n", 1);
	printf("%+5.2d\n", 1);
	printf("----- +05.2d : 1 -----\n");
	ft_printf("%+05.2d\n", 1);
	printf("%+05.2d\n", 1);
	printf("----- +03d : 1 -----\n");
	ft_printf("%+03d\n", 1);
	printf("%+03d\n", 1);
	printf("----- +3d : 1 -----\n");
	ft_printf("%+3d\n", 1);
	printf("%+3d\n", 1);
	printf("----- 010d : -42 -----\n");
	ft_printf("%010d\n", -42);
	printf("%010d\n", -42);
	printf("----- 10d : -42 -----\n");
	ft_printf("%10d\n", -42);
	printf("%10d\n", -42);
	printf("----- 03d : 0 -----\n");
	ft_printf("% 03d\n", 0);
	printf("% 03d\n", 0);
	printf("----- 3d : 0 -----\n");
	ft_printf("% 3d\n", 0);
	printf("% 3d\n", 0);
	printf("----- .4d : 424242 -----\n");
	ft_printf("%.4d\n", 424242);
	printf("%.4d\n", 424242);
	printf("----- +03d : 123456 -----\n");
	ft_printf("%+03d\n", 123456);
	printf("%+03d\n", 123456);
	printf("----- .d : 0 -----\n");
	ft_printf("%.d\n", 0);
	printf("%.d\n", 0);
	printf("----- .0d : 0 -----\n");
	ft_printf("%.0d\n", 0);
	printf("%.0d\n", 0);
	return (0);
}
