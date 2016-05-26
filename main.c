/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:13:19 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/25 17:52:21 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
#include <locale.h>

int		main(void)
{
	/*ft_putendl("-----options tests-----");*/
	/*ft_putendl("-----|+ 010.7ld : 42-----");*/
	/*ft_printf("lol %+ 010.7ld\n", 42);*/
	/*printf("lol %+ 010.7ld\n", 42);*/
	/*ft_putendl("-----|+ #10.7ld : 42-----");*/
	/*ft_printf("lol %+ #10.7ld\n", 42);*/
	/*printf("lol %+ #10.7ld\n", 42);*/
	/*ft_putendl("-----|+-10.7ld : -42-----");*/
	/*ft_printf("lol %+-10.7ld\n", -42);*/
	/*printf("lol %+-10.7ld\n", -42);*/
	/*ft_putendl("-----|+ 010.7ld : -42-----");*/
	/*ft_printf("lol %+ 010.-7ld\n", -42);*/
	/*printf("lol %+ 010.-7ld\n", -42);*/
	/*ft_putendl("-----|010.7ld : 42-----");*/
	/*ft_printf("lol %010.7ld\n", 42);*/
	/*printf("lol %010.7ld\n", 42);*/
	/*ft_putendl("-----|10.7ld : 42-----");*/
	/*ft_printf("lol %10.7+ld\n", 42);*/
	/*printf("lol %10.7+ld\n", 42);*/

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

	/*printf("-----|+d : 42|-----\n");*/
	/*ft_printf("%+d\n", 42);*/
	/*printf("%+d\n", 42);*/
	/*printf("-----|.2d : -1|-----\n");*/
	/*ft_printf("%.2d\n", -1);*/
	/*printf("%.2d\n", -1);*/
	/*printf("-----|+5.2d : 1|-----\n");*/
	/*ft_printf("%+5.2d\n", 1);*/
	/*printf("%+5.2d\n", 1);*/
	/*printf("-----|+05.2d : 1|-----\n");*/
	/*ft_printf("%+05.2d\n", 1);*/
	/*printf("%+05.2d\n", 1);*/
	/*printf("-----|+03d : 1|-----\n");*/
	/*ft_printf("%+03d\n", 1);*/
	/*printf("%+03d\n", 1);*/
	/*printf("-----|+3d : 1|-----\n");*/
	/*ft_printf("%+3d\n", 1);*/
	/*printf("%+3d\n", 1);*/
	/*printf("-----|010d : -42|-----\n");*/
	/*ft_printf("%010d\n", -42);*/
	/*printf("%010d\n", -42);*/
	/*printf("-----|10d : -42|-----\n");*/
	/*ft_printf("%10d\n", -42);*/
	/*printf("%10d\n", -42);*/
	/*printf("-----| 03d : 0|-----\n");*/
	/*ft_printf("% 03d\n", 0);*/
	/*printf("% 03d\n", 0);*/
	/*printf("-----| 3d : 0|-----\n");*/
	/*ft_printf("% 3d\n", 0);*/
	/*printf("% 3d\n", 0);*/
	/*printf("-----|.4d : 424242|-----\n");*/
	/*ft_printf("%.4d\n", 424242);*/
	/*printf("%.4d\n", 424242);*/
	/*printf("-----|+03d : 123456|-----\n");*/
	/*ft_printf("%+03d\n", 123456);*/
	/*printf("%+03d\n", 123456);*/
	/*printf("-----|.d : 0|-----\n");*/
	/*ft_printf("%.d\n", 0);*/
	/*printf("%.d\n", 0);*/
	/*printf("-----|.0d : 0|-----\n");*/
	/*ft_printf("%.0d\n", 0);*/
	/*printf("%.0d\n", 0);*/
	/*printf("-----|d : 0|-----\n");*/
	/*ft_printf("%.d\n", 0);*/
	/*printf("%.d\n", 0);*/

	/*printf("-----|.4u : 42|-----\n");*/
	/*printf("%d\n", ft_printf("%.4u\n", 42));*/
	/*printf("%d\n", printf("%.4u\n", 42));*/
	/*printf("-----|10.u : 42|-----\n");*/
	/*printf("%d\n", ft_printf("%10.u\n", 42));*/
	/*printf("%d\n", printf("%10.u\n", 42));*/
	/*printf("-----| u : 42|-----\n");*/
	/*printf("%d\n", ft_printf("% u\n", 42));*/
	/*printf("%d\n", printf("% u\n", 42));*/
	/*printf("-----|+u : 42|-----\n");*/
	/*printf("%d\n", ft_printf("%+u\n", 42));*/
	/*printf("%d\n", printf("%+u\n", 42));*/

	/*printf("-----|o : -42|-----\n");*/
	/*ft_printf("%o\n", -42);*/
	/*printf("%o\n", -42);*/
	/*printf("-----|ho : -42|-----\n");*/
	/*ft_printf("%ho\n", -42);*/
	/*printf("%ho\n", -42);*/
	/*printf("-----|hho : -42|-----\n");*/
	/*ft_printf("%hho\n", -42);*/
	/*printf("%hho\n", -42);*/
	/*printf("-----|.0o : -42|-----\n");*/
	/*ft_printf("%.0o\n", -42);*/
	/*printf("%.0o\n", -42);*/
	/*printf("-----|5.o : 0|-----\n");*/
	/*ft_printf("%5.o\n", 0);*/
	/*printf("%5.o\n", 0);*/
	/*printf("-----|.0o : 0|-----\n");*/
	/*ft_printf("%.0o\n", 0);*/
	/*printf("%.0o\n", 0);*/
	/*printf("-----|#.0o : 0|-----\n");*/
	/*ft_printf("%#.0o\n", 0);*/
	/*printf("%#.0o\n", 0);*/
	/*printf("-----|12o : 42 -----\n");*/
	/*ft_printf("%12o\n", 42);*/
	/*printf("%12o\n", 42);*/
	/*printf("-----|jo, jo : 0, ULONGMAX|-----\n");*/
	/*printf("%d\n", ft_printf("%jo\n", 4294967295));*/
	/*printf("%d\n", printf("%jo\n", 4294967295));*/
	/*printf("-----|#o : 42 -----\n");*/
	/*printf("%d\n", ft_printf("%#o\n", 42));*/
	/*printf("%d\n", printf("%#o\n", 42));*/
	/*printf("-----|#o : -42 -----\n");*/
	/*ft_printf("%#o\n", -42);*/
	/*printf("%#o\n", -42);*/
	/*printf("-----|#o : 0 -----\n");*/
	/*ft_printf("%#o\n", 0);*/
	/*printf("%#o\n", 0);*/
	/*printf("-----| o : 42 -----\n");*/
	/*ft_printf("% o\n", 42);*/
	/*printf("% o\n", 42);*/
	/*printf("-----|+o : 42 -----\n");*/
	/*ft_printf("%+o\n", 42);*/
	/*printf("%+o\n", 42);*/
	/*printf("-----|O : 65535 -----\n");*/
	/*ft_printf("%O\n", 65535);*/
	/*printf("%O\n", 65535);*/
	/*printf("-----|lo : 4294967295 -----\n");*/
	/*ft_printf("%lo\n", 4294967295);*/
	/*printf("%lo\n", 4294967295);*/
	/*printf("-----|lO : 4294967295 -----\n");*/
	/*ft_printf("%lO\n", 4294967295);*/
	/*printf("%lO\n", 4294967295);*/
	/*printf("-----|hho : 65535 -----\n");*/
	/*ft_printf("%hho\n", 65535);*/
	/*printf("%hho\n", 65535);*/
	/*printf("-----|hhO : 65535 -----\n");*/
	/*ft_printf("%hhO\n", 65535);*/
	/*printf("%hhO\n", 65535);*/
	/*printf("-----|hho : 0 -----\n");*/
	/*ft_printf("%hho\n", 0);*/
	/*printf("%hho\n", 0);*/

	/*printf("-----|x : 0 -----\n");*/
	/*ft_printf("%x\n", 0);*/
	/*printf("%x\n", 0);*/
	/*printf("-----|x : 42 -----\n");*/
	/*ft_printf("%x\n", 42);*/
	/*printf("%x\n", 42);*/
	/*printf("-----|X : 42 -----\n");*/
	/*ft_printf("%X\n", 42);*/
	/*printf("%X\n", 42);*/
	/*printf("-----|#x : 42 -----\n");*/
	/*printf("%d\n", ft_printf("%#x\n", 42));*/
	/*printf("%d\n", printf("%#x\n", 42));*/
	/*printf("-----|#X : 42 -----\n");*/
	/*ft_printf("%#X\n", 42);*/
	/*printf("%#X\n", 42);*/
	/*printf("-----|.0X : 42 -----\n");*/
	/*ft_printf("%.0X\n", 42);*/
	/*printf("%.0X\n", 42);*/
	/*printf("-----|#x : 42 -----\n");*/
	/*ft_printf("%#x\n", 42);*/
	/*printf("%#x\n", 42);*/
	/*printf("-----|x : -42 -----\n");*/
	/*ft_printf("%x\n", -42);*/
	/*printf("%x\n", -42);*/
	/*printf("-----|#.x : 0 -----\n");*/
	/*ft_printf("%#.x\n", 0);*/
	/*printf("%#.x\n", 0);*/
	/*printf("-----|#.0x : 0 -----\n");*/
	/*ft_printf("%#.0x\n", 0);*/
	/*printf("%#.0x\n", 0);*/

	/*int i;*/
	/*i = 0;*/
	/*printf("-----|p : &i -----\n");*/
	/*ft_printf("%p\n", &i);*/
	/*printf("%p\n", &i);*/
	/*printf("-----|p : 0 -----\n");*/
	/*ft_printf("%p\n", 0);*/
	/*printf("%p\n", 0);*/
	/*printf("-----|5p : 0 -----\n");*/
	/*ft_printf("%5p\n", 0);*/
	/*printf("%5p\n", 0);*/
	/*printf("-----|.0p : 0 -----\n");*/
	/*ft_printf("%.0p\n", 0);*/
	/*printf("%.0p\n", 0);*/
	/*printf("-----|.p : 0 -----\n");*/
	/*ft_printf("%.p\n", 0);*/
	/*printf("%.p\n", 0);*/
	/*printf("-----|5.p : 0 -----\n");*/
	/*ft_printf("%5.p\n", 0);*/
	/*printf("%5.p\n", 0);*/
	/*printf("-----|.5p : 0 -----\n");*/
	/*ft_printf("%.5p\n", 0);*/
	/*printf("%.5p\n", 0);*/
	/*printf("-----|.5p : i -----\n");*/
	/*ft_printf("%.30p\n", &i);*/
	/*printf("%.30p\n", &i);*/

	/*printf("----------\n");*/
	/*ft_printf("%%\n");*/
	/*printf("%%\n");*/
	/*printf("----------\n");*/
	/*ft_printf("%05.%\n");*/
	/*printf("%05.%\n");*/
	/*printf("----------\n");*/
	/*ft_printf("%.%\n");*/
	/*printf("%.%\n");*/
	/*printf("----------\n");*/
	/*ft_printf("%5%\n");*/
	/*printf("%5%\n");*/

	/*setlocale(LC_ALL, "");*/
	/*printf("-----|C : 暖-----\n");*/
	/*ft_printf("%C\n",L'暖');*/
	/*printf("%C\n", L'暖');*/
	/*printf("-----|C :-----\n");*/
	/*ft_printf("%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C\n",*/
			/*' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',*/
			/*'.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',*/
			/*'<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',*/
			/*'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',*/
			/*'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',*/
			/*'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',*/
			/*'t', 'u', 'v', 'w', 'x', 'y', 'z', '{', 'r');*/
	/*printf("%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C\n",*/
			/*' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',*/
			/*'.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',*/
			/*'<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',*/
			/*'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',*/
			/*'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',*/
			/*'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',*/
			/*'t', 'u', 'v', 'w', 'x', 'y', 'z', '{', 'r');*/

	printf("-----|05p : 0-----\n");
	ft_printf("%05p\n", 0);
	printf("%05p\n", 0);
	printf("-----|05p : 42-----\n");
	ft_printf("%05p\n", 42);
	printf("%05p\n", 42);
	return (0);
}
