/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 18:09:14 by pdelefos          #+#    #+#             */
/*   Updated: 2016/05/12 18:44:51 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include <stdarg.h>
#include <stdlib.h>

void	free_lstopt(t_list **lst_opt)
{
	t_opt	*opt;
	t_list	*lst;
	t_list	*tmp;

	lst = *lst_opt;
	while (lst)
	{
		opt = lst->content;
		tmp = lst;
		lst = lst->next;
		free(opt->str);
		free(opt);
		free(tmp);
	}
}

int		ft_printf(const char *restrict format, ...)
{
	va_list	args;
	t_list	*lst_opt;
	int		ret;

	va_start(args, format);
	lst_opt = NULL;
	ret = 0;
	ret = parse_format(format, &lst_opt);
	if (ret != -1)
		ret = print_format(format, &lst_opt, &args);
	free_lstopt(&lst_opt);
	va_end(args);
	return (ret);
}
