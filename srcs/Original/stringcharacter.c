/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringcharacter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:17:57 by prossi            #+#    #+#             */
/*   Updated: 2021/11/08 12:37:26 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void	ifstring(t_print *arg_count)
{
	char	*str;
	int		len;

	str = va_arg(t_print->args, char *);
	if (str == NULL)
	{
		ft_putstr_fd("(NULL)", 1);
		t_print->count += 6;
	}
	else
	{
		len = ft_strlen(str);
		ft_putstr_fd(str, 1);
		t_print->count += len;
	}
}

void	ifchar(t_print *arg_count)
{
	ft_putchar_fd(va_arg(arg_count->args, int), 1);
	arg_count->count++;
}
