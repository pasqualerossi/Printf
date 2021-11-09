/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointerhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:52:23 by prossi            #+#    #+#             */
/*   Updated: 2021/11/09 12:33:11 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

static char	*numberlength(unsigned long num, int *len)
{
	char	*str;

	while (num >= 16)
	{
		num = num / 16;
		*len += 1;
	}
	str = (char *)malloc((*len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[*len] = '\0';
	return (str);
}

void	ifhex(t_print *arg_count, char c)
{
	unsigned int	num;
	int				len;
	char			*str;

	num = va_arg(arg_count->args, unsigned int);
	len = 1;
	str = numberlength(num, &len);
	len--;
	while (len >= 0)
	{
		if (num % 16 < 10)
			str[len] = '0' + (num % 16);
		else if (c == 'x')
			str[len] = 'a' - 10 + (num % 16);
		else if (c == 'X')
			str[len] = 'A' - 10 + (num % 16);
		num = num / 16;
		len--;
		arg_count->count++;
	}
	ft_putstr_fd(str, 1);
	free(str);
}

void	ifpointer(t_print *arg_count)
{
	int				len;
	char			*str;
	unsigned long	num;

	num = va_arg(arg_count->args, unsigned long);
	len = 1;
	str = numberlength(num, &len);
	ft_putstr_fd("0x", 1);
	arg_count->counter += 2;
	len--;
	while (len >= 0)
	{
		if (num % 16 <= 10)
			str[len] = '0' + (num % 16);
		else
			str[len] = 'W' + (num % 16);
		num = num / 16;
		len--;
		arg_count->counter++;
	}
	ft_putstr_fd(str, 1);
	free(str);
}
